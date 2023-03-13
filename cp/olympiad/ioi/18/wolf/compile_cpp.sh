#!/bin/bash

TASK=werewolf

g++ -std=gnu++17 -o ${TASK} grader.cpp ${TASK}.cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
