#pragma once
#include "GeneralNeuron.hpp"
#include <memory>
#include <unordered_map>
namespace md {
class Brain {
private:
  struct NID_SIG_COS {
    float Signal;
    float ConnectionStrength;
  };
  int BNeuron_i = 0, LNeuron_i = 0, TNeuron_i = 0;
  // contains the NID and signal it is meant to recieve
  std::unordered_map<int, std::vector<NID_SIG_COS>> SignalMap;
  float TopNeuronOutput;

  void IncrementNID();
  void InitialzeBNeuron(int n);
  void InitialzeGNeuron(int n);
  void InitialzeTNeuron(int n);
  void FormConnectionsBetweenBaseAndLayered();
  void FormConnectionsBetweenLayeredAndTop();
  void FormConnectionsBetweenNeurons();
  void StimulateBaseNeurons(float signal);
  void StimulateLayeredNeurons();
  void StimulateTopNeurons();

public:
  std::vector<nrn::BNeuron> BaseNeurons;
  std::vector<nrn::GNeuron> LayeredNeurons;
  std::vector<nrn::TNeuron> TopNeurons;
  std::vector<std::unique_ptr<nrn::GNeuron>> NeuronMap;

  void SetupNeurons(int B_n, int T_n, int G_n);
  // brain recieves values that it may react to
  void StimuliPath(float stimulus);
  float GetTopNeuronOutput();
};
} // namespace md
