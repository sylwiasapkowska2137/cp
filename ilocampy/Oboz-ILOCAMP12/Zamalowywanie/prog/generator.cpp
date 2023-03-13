//Przemysław Jakub Kozłowski
#include "generator.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

Test exampleTest();
Test randomTest(int n, int m, int minval, int maxval);

int main()
{
    Generator gen("zam");

    gen.addTest(exampleTest());

    // Grupa 1 -- 20p. -- n,m <= 5 -- 20% punktów
    gen.beginGroup();
    {
        Generator::setSeed(298434);gen.addTest(randomTest(5, 5, -100, 100));
        Generator::setSeed(873548);gen.addTest(randomTest(4, 5, -20, 200));
        Generator::setSeed(357465);gen.addTest(randomTest(1, 1, -100, -50));
        Generator::setSeed(783475);gen.addTest(randomTest(5, 4, 100, 200));
    }
    gen.endGroup();

    // Grupa 2 -- 20p. -- n,m <= 20 -- 40% punktów
    gen.beginGroup();
    {
        Generator::setSeed(218434);gen.addTest(randomTest(20, 15, -1000, 100));
        Generator::setSeed(573548);gen.addTest(randomTest(20, 20, -2000, 15));
        Generator::setSeed(352465);gen.addTest(randomTest(20, 19, -30, 3000));
        Generator::setSeed(783175);gen.addTest(randomTest(5, 4, -3000, 3000));
    }
    gen.endGroup();

    // Grupa 3 -- 20p. -- n,m <= 50 -- 60% punktów
    gen.beginGroup();
    {
        Generator::setSeed(218474);gen.addTest(randomTest(50, 30, -1000000, 1000000));
        Generator::setSeed(542514);gen.addTest(randomTest(49, 49, -2000000, 1000005));
        Generator::setSeed(372665);gen.addTest(randomTest(20, 19, -3000000, 3000000));
        Generator::setSeed(723135);gen.addTest(randomTest(5, 4, -3000000, 3000000));
    }
    gen.endGroup();

    // Grupa 4 -- 20p. -- n,m <= 100 -- 80% punktów
    gen.beginGroup();
    {
        Generator::setSeed(118474);gen.addTest(randomTest(100, 100, -100000000, 10000));
        Generator::setSeed(642514);gen.addTest(randomTest(70, 99, -1000000000, 100000005));
        Generator::setSeed(572665);gen.addTest(randomTest(90, 89, -100000000, 700000000));
        Generator::setSeed(623135);gen.addTest(randomTest(100, 90, -10000000, 1000000000));
    }
    gen.endGroup();

    // Grupa 5 -- 20p. -- n,m <= 300 -- 100% punktów
    gen.beginGroup();
    {
        Generator::setSeed(124474);gen.addTest(randomTest(300, 300, 1000000000, 1000000000));
        Generator::setSeed(663574);gen.addTest(randomTest(200, 300, -1000000000, 1000000000));
        Generator::setSeed(577625);gen.addTest(randomTest(300, 200, -1000000000, 1000000));
        Generator::setSeed(632565);gen.addTest(randomTest(250, 275, -10000000, 1000000000));
    }
    gen.endGroup();

    gen.generate();
    return 0;
}

Test exampleTest() {
    Test test;

    test.addLine(5, 5);
    test.addLine(5, -4, -2, -3, 3);
    test.addLine(-2, 2, -1, 1, -4);
    test.addLine(-4, -1, 3, 0, -3);
    test.addLine(-2, 3, -1, 3, -2);
    test.addLine(-3, 3, 0, 3, 4);

    return test;
}

inline int R(int a, int b) {return a+Generator::random()%(b-a+1);}

Test randomTest(int n, int m, int minval, int maxval)
{
    Test test;
    test.addLine(n, m);

    for(int i = 1;i <= n;i++)
    {
        vector<int> A(m);
        for(int i = 1;i <= m;i++)
            A[i-1] = R(minval,maxval);
        test.addLine(A);
    }

    return test;
}
