#include "GeneralNeuron.hpp"
#include <random>

void nrn::GNeuron::GetSignal(float &SignalReceived) {
  CurrentSignal += SignalReceived;
}

void nrn::GNeuron::ChangeActiveStatus(bool &Status) { Active = Status; }

float nrn::GNeuron::SendSignal() {
  if (CurrentSignal >= Threshold) {
    int SignalToSend = (CurrentSignal - Threshold) / Threshold;
    CurrentSignal -= SignalToSend;
    return CurrentSignal;
  }
  return 0.0;
}

void nrn::GNeuron::SetNeuronThreshold() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(0.0, 1);
  Threshold = distrib(gen);
}
