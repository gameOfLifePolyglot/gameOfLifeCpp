#!/bin/bash
mkdir build
cd build
cmake ..
cmake --build .
ctest -VV