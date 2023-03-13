#!/bin/bash

g++ -O3 -static trilib.c triangles.cpp -lm -std=c++17 -Wall -Wextra -Wshadow -o what