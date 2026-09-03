#include "ArtificialBrain.hpp"
#include <random>
#include <vector>

std::vector<double> GenerateInputSignals(int n) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(0.0, 1);

  std::vector<double> Signals;
  for (size_t i = 0; i < n; ++i) {
    Signals.push_back(distrib(gen));
  }
  return Signals;
}
int main() {
  int nBaseNeurons = 1, nLayeredNeurons = 3, nTopNeurons = 1;
  // generate 5 input signals
  std::vector<double> InputSignals = GenerateInputSignals(5);
  md::Brain Brain_main;
  Brain_main.SetupNeurons(nBaseNeurons, nBaseNeurons, nLayeredNeurons);
  return 0;
}
