//Przemysław Jakub Kozłowski
#include "generator.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;

inline int R(int a, int b) {return a+Generator::random()%(b-a+1);}

vector<int> ArrayRandom(int n, int a, int b) // Zwraca vector n liczb z przedziału [a,b]
{
    vector<int> ret(n);
    for(int i = 0;i < n;i++)
        ret[i] = R(a, b);
    return ret;
}

Test reczny(vector<int> A, int m)
{
    Test test;

    test.addLine(A.size(), m);
    test.addLine(A);

    return test;
}

Test randomTest(int n, int w, int mod)
{
    return reczny(ArrayRandom(n, 1, w), mod);
}

Test exampleTest()
{
    Test test;

    test.addLine(3);
    test.addLine(1, 2, 3);

    return test;
}

int main()
{
    Generator gen("aks");

    gen.addTest(reczny({1,2,3}, 100));

    gen.addTest(reczny({3,4,5}, 120));
    Generator::setSeed(182643);gen.addTest(randomTest(10, 10, 1000000000));
    Generator::setSeed(128483);gen.addTest(randomTest(9, 1000000000, 127));

    Generator::setSeed(129247);gen.addTest(randomTest(999, 1000, 97374));
    Generator::setSeed(592759);gen.addTest(randomTest(1000, 1000000000, 9374628));

    Generator::setSeed(238745);gen.addTest(randomTest(10000, 10000, 123259));
    Generator::setSeed(932842);gen.addTest(randomTest(10000, 1, 102345678));

    Generator::setSeed(237483);gen.addTest(randomTest(100000, 1001, 1009));

    Generator::setSeed(971364);gen.addTest(randomTest(1000000, 1000000000, 999999938));
    Generator::setSeed(276535);gen.addTest(randomTest(999999, 100000000, 999999937));

    gen.generate();
    return 0;
}
