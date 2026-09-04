#pragma once
#include "GeneralNeuron.hpp"
#include <vector>
namespace md {
class Brain {
private:
  void IncrementNID();
  void InitialzeBNeuron(int n);
  void InitialzeGNeuron(int n);
  void InitialzeTNeuron(int n);
  void FormConnectionsBetweenNeurons();

public:
  std::vector<nrn::BNeuron> BaseNeurons;
  std::vector<nrn::GNeuron> LayeredNeurons;
  std::vector<nrn::TNeuron> TopNeurons;

  void SetupNeurons(int B_n, int T_n, int G_n);
};
} // namespace md
