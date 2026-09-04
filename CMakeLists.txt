cmake_minimum_required(VERSION 3.15)
project(npab VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES

ArtificialBrain.cpp
Connection.cpp
GeneralNeuron.cpp
main.cpp
)

add_executable(npab ${SOURCES})

