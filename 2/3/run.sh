#!/bin/bash

mpicc pipe.c -o pipe
mpirun -np 17 ./pipe 2
