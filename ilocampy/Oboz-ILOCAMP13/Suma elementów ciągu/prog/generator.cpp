//Przemysław Jakub Kozłowski
#include "generator.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <cassert>
#include <set>
#include <cmath>
using namespace std;
typedef long long LL;

inline int R(int a, int b) {return a+Generator::random()%(b-a+1);}

vector<int> UniqueRandom(int n, int a, int b) // Zwraca vector n różnych liczb z przedziału [a,b]
{
    if(b-a+1 <= 2*n)
    {
        vector<int> ret;
        for(int i = a;i <= b;i++) ret.push_back(i);
        shuffle(ret.begin(), ret.end(), Generator::getGen());
        ret.resize(n);
        return ret;
    }
    else
    {
        vector<int> ret;
        set<int> S;
        while(ret.size() < n)
        {
            int x = R(a,b);
            if(!S.count(x))
            {
                ret.push_back(x);
                S.insert(x);
            }
        }
        return ret;
    }
}

vector<int> ArrayRandom(int n, int a, int b) // Zwraca vector n liczb z przedziału [a,b]
{
    vector<int> ret(n);
    for(int i = 0;i < n;i++)
        ret[i] = R(a, b);
    return ret;
}

vector<int> ArraySorted(vector<int> V)
{
    sort(V.begin(), V.end());
    return V;
}

vector<int> LiczbyOSumie(int n, int suma)  // Zwraca vector n nieujemnych liczb o sumie suma
{
    vector<int> V = ArrayRandom(n-1, 0, suma);
    sort(V.begin(), V.end());
    V.push_back(suma-V.back());
    for(int i = (int)V.size() - 2;i >= 1;i--)
        V[i] = V[i] - V[i-1];
    return V;
}

// Właściwa część.

Test exampleTest()
{
    Test test;
    test.addLine(14);
    test.addLine(-2, 1, -1, -4, 6, -2, 12, -5, 8, -7, 10, -5, 1, -6);
    return test;
}

Test randomTest(int n, int minw, int maxw)
{
    Test test;
    test.addLine(n);

    vector<int> V(n);
    for (int i = 0; i < n; i++) {
        V[i] = R(minw, maxw);
    }
    test.addLine(V);

    return test;
}

int main()
{
    Generator gen("sec");

    gen.addTest(exampleTest());

    // Grupa 1
    gen.beginGroup();
    {
        Generator::setSeed(836473);gen.addTest(randomTest(10, -10, 10));
    }
    gen.endGroup();

    // Grupa 2
    gen.beginGroup();
    {
        Generator::setSeed(293474);gen.addTest(randomTest(1000, -10000, 10000));
    }
    gen.endGroup();

    // Grupa 3
    gen.beginGroup();
    {
        Generator::setSeed(123434);gen.addTest(randomTest(10000, -1000000, 1000000));
    }
    gen.endGroup();

    // Grupa 4
    gen.beginGroup();
    {
        Generator::setSeed(837535);gen.addTest(randomTest(100000, -100000000, 100000000));
    }
    gen.endGroup();

    // Grupa 5
    gen.beginGroup();
    {
        Generator::setSeed(127337);gen.addTest(randomTest(1000000, -1000000000, 1000000000));
    }
    gen.endGroup();

    gen.generate();
    return 0;
}
