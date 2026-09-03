#pragma once
namespace pl {
class Connection {

  float ConnectionStrength = 0.0;
  void SetConnectionStrength();
  int ConnectingToNeuron; // NID of the neuron that is connected

  Connection(int &ConnectingToNeuron) {
    this->ConnectingToNeuron = ConnectingToNeuron;
  }
};
} // namespace pl
