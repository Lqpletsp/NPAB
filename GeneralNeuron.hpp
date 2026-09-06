#pragma once
#include "Connection.hpp"
#include <vector>
namespace nrn {
class GNeuron { // G -> General
private:
  void SetNeuronThreshold();
  float SendSignal();
  void GetSignal(float SignalReceived);

public:
  int NID;
  float Threshold = 0.0;
  float CurrentSignal = 0.0;
  std::vector<pl::Connection> Connections;
  bool Active = true;

  GNeuron(int &NID) { this->NID = NID; }
  void ChangeActiveStatus(bool Status);
  float GetAndReact(float stimulus);
};

class BNeuron : public GNeuron { // B -> Base
public:
  BNeuron(int NID) : GNeuron(NID) { Threshold = 0.1; }
};

class TNeuron : public GNeuron { // T -> Top
public:
  TNeuron(int NID) : GNeuron(NID) { Threshold = 1.0; }
};
inline int NeuronID = 0;

} // namespace nrn
