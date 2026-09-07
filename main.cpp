#include "ArtificialBrain.hpp"
int main() {
  int nBaseNeurons = 1, nLayeredNeurons = 3, nTopNeurons = 1;
  // generate 5 input signals
  md::Brain Brain_main;
  Brain_main.SetupNeurons(nBaseNeurons, nTopNeurons, nLayeredNeurons);
  Brain_main.StimuliPath(0.3);
  return 0;
}
