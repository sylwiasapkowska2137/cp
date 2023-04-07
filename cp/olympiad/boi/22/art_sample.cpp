#include "art.h"
//
// --- Sample implementation for the task art ---
//
// To compile this program with the sample grader, place:
//     art.h art_sample.cpp sample_grader.cpp
// in a single folder, then open the terminal in this directory (right-click onto an empty spot in the directory,
// left click on "Open in terminal") and enter e.g.:
//     g++ -std=c++17 art_sample.cpp sample_grader.cpp
// in this folder. This will create a file a.out in the current directory which you can execute from the terminal
// as ./a.out
// See task statement or sample_grader.cpp for the input specification
//
void solve(int N) {
    std::vector<int> order = {1, 2, 3};
    publish(order);
    order = {2, 3, 1};
    publish(order);
    order = {1, 3, 2};
    answer(order);
}
