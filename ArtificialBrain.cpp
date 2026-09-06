#include "ArtificialBrain.hpp"
#include "GeneralNeuron.hpp"

void md::Brain::IncrementNID() { nrn::NeuronID += 1; }

void md::Brain::InitialzeBNeuron(int n) {
  for (size_t i = 0; i < n; ++i) {
    nrn::BNeuron BaseNeuron_i{nrn::NeuronID};
    SignalMap[nrn::NeuronID] = {};
    NeuronMap.push_back(std::make_unique<nrn::BNeuron>(BaseNeuron_i));
    IncrementNID();
    BaseNeurons.push_back(BaseNeuron_i);
  }
}
void md::Brain::InitialzeGNeuron(int n) {
  for (size_t i = 0; i < n; ++i) {
    nrn::GNeuron LayeredNeuron_i{nrn::NeuronID};
    SignalMap[nrn::NeuronID] = {};
    NeuronMap.push_back(std::make_unique<nrn::GNeuron>(LayeredNeuron_i));
    IncrementNID();
    LayeredNeurons.push_back(LayeredNeuron_i);
  }
}
void md::Brain::InitialzeTNeuron(int n) {
  for (size_t i = 0; i < n; ++i) {
    nrn::TNeuron TopNeuron_i{nrn::NeuronID};
    SignalMap[nrn::NeuronID] = {};
    NeuronMap.push_back(std::make_unique<nrn::TNeuron>(TopNeuron_i));
    IncrementNID();
    TopNeurons.push_back(TopNeuron_i);
  }
}

void md::Brain::FormConnectionsBetweenBaseAndLayered() {
  for (size_t i = 0; i < BaseNeurons.size(); ++i) {
    for (size_t j = 0; j < LayeredNeurons.size(); ++j) {
      BaseNeurons.at(i).Connections.emplace_back(LayeredNeurons.at(j).NID,
                                                 0.5f);
    }
  }
}
void md::Brain::FormConnectionsBetweenLayeredAndTop() {
  for (size_t i = 0; i < LayeredNeurons.size(); ++i) {
    for (size_t j = 0; j < TopNeurons.size(); ++j) {
      LayeredNeurons.at(i).Connections.emplace_back(TopNeurons.at(j).NID, 0.5f);
    }
  }
}

void md::Brain::FormConnectionsBetweenNeurons() {
  // between base neurons and layered neurons
  FormConnectionsBetweenBaseAndLayered();
  // between layered neurons and top neurons
  FormConnectionsBetweenLayeredAndTop();
}

void md::Brain::SetupNeurons(int B_n, int T_n, int G_n) {
  InitialzeBNeuron(B_n);
  InitialzeTNeuron(T_n);
  InitialzeGNeuron(G_n);
  FormConnectionsBetweenNeurons();
}

void md::Brain::StimulateBaseNeurons(float stimulus) {
  for (auto neuron : BaseNeurons) {
    float SignalSent = neuron.GetAndReact(stimulus);
    for (auto connection : neuron.Connections) {
      SignalMap[connection.ConnectingToNeuron].push_back(
          {SignalSent, connection.ConnectionStrength});
    }
  }
}
void md::Brain::StimulateLayeredNeurons() {
  for (auto neuron : LayeredNeurons) {
    auto NeuronSignalsMD = SignalMap.at(neuron.NID);
    for (auto SignalMD : NeuronSignalsMD) {
      float SignalSent =
          neuron.GetAndReact(SignalMD.ConnectionStrength + SignalMD.Signal);
      for (auto connection : neuron.Connections) {
        SignalMap[connection.ConnectingToNeuron].push_back(
            {SignalSent, connection.ConnectionStrength});
      }
    }
    SignalMap[neuron.NID].clear();
  }
}
void md::Brain::StimulateTopNeurons() {
  for (auto neuron : TopNeurons) {
    auto NeuronSignalsMD = SignalMap.at(neuron.NID);
    for (auto SignalMD : NeuronSignalsMD) {
      float SignalSent =
          neuron.GetAndReact(SignalMD.ConnectionStrength + SignalMD.Signal);
      TopNeuronOutput = SignalSent;
    }
    SignalMap[neuron.NID].clear();
  }
}

float md::Brain::GetTopNeuronOutput() { return TopNeuronOutput; }

void md::Brain::StimuliPath(float stimulus) {
  StimulateBaseNeurons(stimulus);
  StimulateLayeredNeurons();
  StimulateTopNeurons();
}
