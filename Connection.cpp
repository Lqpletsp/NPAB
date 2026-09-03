#include "Connection.hpp"
#include <random>

void pl::Connection::SetConnectionStrength() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(0.0f, 1.0f);
  ConnectionStrength = distrib(gen);
}
