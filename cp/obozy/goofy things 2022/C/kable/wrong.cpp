#include "kablib.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> wejscie = init();
    int n = wejscie[0], x = wejscie[1], y = wejscie[2];
    int r1 = wez({1, 2, 3});
    vector<int> t2{1};
    int r2 = wez(t2);
    vector<int> t3;
    t3.emplace_back(3);
    int r3 = wez(t3);
    odpowiedz(1, 3);
}