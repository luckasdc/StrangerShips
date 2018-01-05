#!/bin/bash

# Build the project
mkdir build
cd build
cmake .. && make

rc=$?; if [[ $rc != 0 ]]; then echo "Build failed"; exit $rc; fi

# Execute
# ../build/exec
