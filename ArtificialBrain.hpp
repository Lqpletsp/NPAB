#pragma once
#include "GeneralNeuron.hpp"
#include <memory>
namespace md {
class Brain {
private:
  void IncrementNID();
  void InitialzeBNeuron(int n);
  void InitialzeGNeuron(int n);
  void InitialzeTNeuron(int n);
  void FormConnectionsBetweenBaseAndLayered();
  void FormConnectionsBetweenLayeredAndTop();
  void FormConnectionsBetweenNeurons();

public:
  std::vector<nrn::BNeuron> BaseNeurons;
  std::vector<nrn::GNeuron> LayeredNeurons;
  std::vector<nrn::TNeuron> TopNeurons;
  std::vector<std::unique_ptr<nrn::GNeuron>> NeuronMap;

  void SetupNeurons(int B_n, int T_n, int G_n);
  // brain recieves values that it may react to
  void StimuliPath(std::vector<double> Stimuli);
};
} // namespace md
