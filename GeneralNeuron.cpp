#include "GeneralNeuron.hpp"
#include <random>

void nrn::GNeuron::GetSignal(float SignalReceived) {
  CurrentSignal += SignalReceived;
}

void nrn::GNeuron::ChangeActiveStatus(bool Status) { Active = Status; }

float nrn::GNeuron::SendSignal() {
  if (CurrentSignal > Threshold) {
    float SignalToSend = (CurrentSignal - Threshold) / Threshold;
    if (SignalToSend > CurrentSignal) {
      SignalToSend = CurrentSignal;
      CurrentSignal = 0;
    } else
      CurrentSignal -= SignalToSend;
    return SignalToSend;
  }
  return 0.0;
}

void nrn::GNeuron::SetNeuronThreshold() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(0.0f, 1.0f);
  Threshold = distrib(gen);
}

float nrn::GNeuron::GetAndReact(float signal) {
  GetSignal(signal);
  return SendSignal();
}
