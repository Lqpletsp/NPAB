#include "ArtificialBrain.hpp"

void md::Brain::IncrementNID() { nrn::NeuronID += 1; }

void md::Brain::InitialzeBNeuron(int n) {
  for (size_t i = 0; i < n; ++i) {
    nrn::BNeuron BaseNeuron_i{nrn::NeuronID};
    IncrementNID();
    BaseNeurons.push_back(BaseNeuron_i);
  }
}
void md::Brain::InitialzeGNeuron(int n) {
  for (size_t i = 0; i < n; ++i) {
    nrn::GNeuron LayeredNeuron_i{nrn::NeuronID};
    IncrementNID();
    LayeredNeurons.push_back(LayeredNeuron_i);
  }
}
void md::Brain::InitialzeTNeuron(int n) {
  for (size_t i = 0; i < n; ++i) {
    nrn::TNeuron TopNeuron_i{nrn::NeuronID};
    IncrementNID();
    TopNeurons.push_back(TopNeuron_i);
  }
}

void md::Brain::SetupNeurons(int B_n, int T_n, int G_n) {
  InitialzeBNeuron(B_n);
  InitialzeTNeuron(T_n);
  InitialzeGNeuron(G_n);
}
