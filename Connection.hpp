#pragma once
namespace pl {
class Connection {
public:
  float ConnectionStrength = 0.0;
  int ConnectingToNeuron; // NID of the neuron that is connected

  Connection(int ConnectingToNeuron, int ConnectionStrength) {
    this->ConnectingToNeuron = ConnectingToNeuron;
    this->ConnectionStrength = ConnectionStrength;
  }
};
} // namespace pl
