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
    test.addLine(3);
    test.addLine(20, 3);
    test.addLine(10, 9);
    test.addLine(25, 4);
    return test;
}

Test randomTest(int n, int a, int b)
{
    Test test;
    test.addLine(n);

    for (int i = 0; i < n; i++) {
        test.addLine(R(1, a), R(1, b));
    }

    return test;
}

Test specialTest(int n, int a, int przegrany)
{
    Test test;
    test.addLine(n);

    vector<pair<int,int> > V;
    V.push_back(make_pair(3, 1));
    assert(przegrany > 1);
    assert((long long)n*a < 1000000000);

    int tosty = 0;
    for (int i = 1; i < n; i++) {
        if (i + 1 != przegrany) {
            int dodaj = R(1, a);
            int zjedz = R(1, dodaj);
            V.push_back(make_pair(V.back().first + dodaj, zjedz));
            tosty += zjedz;
        } else {
            int dodaj = R(1, a);
            int zjedz = V.back().first + dodaj - 1 - tosty + 1;
            V.push_back(make_pair(V.back().first + dodaj, zjedz));
        }
    }

    shuffle(V.begin(), V.end(), Generator::getGen());

    for (int i = 0; i < V.size(); i++) {
        test.addLine(V[i].first, V[i].second);
    }

    return test;
}

int main()
{
    Generator gen("tos");

    gen.addTest(exampleTest());

    // Grupa 1
    gen.beginGroup();
    {
        Generator::setSeed(836473);gen.addTest(randomTest(10, 10000, 10));
        Generator::setSeed(983274);gen.addTest(randomTest(10, 10, 10000));
        Generator::setSeed(182734);gen.addTest(randomTest(10, 10000, 100));
    }
    gen.endGroup();

    // Grupa 2
    gen.beginGroup();
    {
        Generator::setSeed(988732);gen.addTest(specialTest(10, 1000, 11));
        Generator::setSeed(982283);gen.addTest(specialTest(10, 900, 10));
        Generator::setSeed(774675);gen.addTest(specialTest(11, 50, 12));
    }
    gen.endGroup();

    // Grupa 3
    gen.beginGroup();
    {
        Generator::setSeed(938457);gen.addTest(randomTest(1000, 1000000000, 1000));
        Generator::setSeed(283845);gen.addTest(randomTest(1000, 1000, 1000000000));
        Generator::setSeed(929548);gen.addTest(randomTest(1000, 100000, 10000));
    }
    gen.endGroup();

    // Grupa 4
    gen.beginGroup();
    {
        Generator::setSeed(192834);gen.addTest(specialTest(100000, 2854, 95846));
        Generator::setSeed(843530);gen.addTest(specialTest(100000, 8453, 100000+1));
        Generator::setSeed(204835);gen.addTest(specialTest(100000, 9000, 100000+1));
    }
    gen.endGroup();

    // Grupa 5
    gen.beginGroup();
    {
        Generator::setSeed(847357);gen.addTest(randomTest(1000000, 1000000000, 1000000000));
        Generator::setSeed(394854);gen.addTest(specialTest(1000000, 992, 1000000+1));
        Generator::setSeed(239855);gen.addTest(specialTest(1000000, 876, 900006));
    }
    gen.endGroup();

    gen.generate();
    return 0;
}
