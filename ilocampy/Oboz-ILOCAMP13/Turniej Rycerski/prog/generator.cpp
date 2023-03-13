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
    test.addLine(4);
    test.addLine(7, 7, 9);
    test.addLine(12, 15, 6);
    test.addLine(3, 5, 3);
    test.addLine(1, 1, 2);
    return test;
}

Test reczny(vector<vector<int> > V)
{
    Test test;
    test.addLine(V.size());
    shuffle(V.begin(), V.end(), Generator::getGen());
    for (int i = 0; i < V.size(); i++) {
        test.addLine(V[i]);
    }
    return test;
}

Test recznybs(vector<vector<int> > V)
{
    Test test;
    test.addLine(V.size());
    for (int i = 0; i < V.size(); i++) {
        test.addLine(V[i]);
    }
    return test;
}

vector<vector<int> > randList(int n, int minw, int maxw)
{
    vector<vector<int> > V;
    for (int i = 0; i < n; i++) {
        int a = R(minw, maxw);
        int b = R(minw, maxw);
        int c = R(minw, maxw);
        V.push_back({a,b,c});
    }
    return V;
}

vector<vector<int> > sumList(const vector<vector<int> > &A, const vector<vector<int> > &B)
{
    vector<vector<int> > V = A;
    for (int i = 0; i < B.size(); i++) {
        V.push_back(B[i]);
    }
    return V;
}

int main()
{
    Generator gen("tur");

    gen.addTest(exampleTest());

    // Grupa 1
    gen.beginGroup();
    {
        Generator::setSeed(923845);gen.addTest(reczny(randList(10, 1, 10)));
        Generator::setSeed(729374);gen.addTest(reczny(randList(7, 2, 7)));
        Generator::setSeed(829374);gen.addTest(reczny({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}));
    }
    gen.endGroup();

    // Grupa 2
    gen.beginGroup();
    {
        Generator::setSeed(858405);gen.addTest(reczny({{10, 200, 3000}, {30, 100, 4000}, {40, 150, 2000}, {10, 11, 12}}));
        Generator::setSeed(921211);gen.addTest(reczny({{10, 200, 3000}, {30, 100, 4000}, {40, 150, 2000}, {10, 11, 12}, {1000, 201, 1}}));
    }
    gen.endGroup();

    // Grupa 3
    gen.beginGroup();
    {
        Generator::setSeed(289458);gen.addTest(reczny({
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1},
            {2, 1, 2}
        }));
        Generator::setSeed(122324);gen.addTest(reczny({
            {100, 100, 100},
            {100, 50, 150},
            {1, 1, 1},
            {2, 1, 2}
        }));
        Generator::setSeed(893485);gen.addTest(reczny({
            {1, 10, 9},
            {2, 10, 9},
            {3, 9, 8},
            {1, 11, 8},
            {1, 9, 19},
            {1, 1, 1},
        }));
    }
    gen.endGroup();

    // Grupa 4
    gen.beginGroup();
    {
        Generator::setSeed(892754);gen.addTest(reczny(randList(1000000 - 1000, 1, 1000)));
        Generator::setSeed(102838);gen.addTest(reczny(sumList(randList(100000 - 1000, 1, 1000),{{1002, 1003, 1004}})));
        Generator::setSeed(960584);gen.addTest(reczny(sumList(randList(100099 - 10, 1, 1000),{{1002, 1003, 1004}, {1000, 1004, 1005}, {1001, 1005, 1000}})));
    }
    gen.endGroup();

    // Grupa 5
    gen.beginGroup();
    {
        Generator::setSeed(128424);gen.addTest(reczny(randList(1000000 - 9, 1, 1000000000)));
        Generator::setSeed(958438);gen.addTest(reczny(sumList(randList(1000000 - 10, 1, 1000000000),{{1002, 1003, 1004}})));
        Generator::setSeed(238845);gen.addTest(reczny(sumList(randList(1000000 - 10, 1, 100000000),{
            {100, 1003, 1004},
            {1000000000, 1000000000, 1},
            {1001, 1005, 1000},
        })));
        Generator::setSeed(954834);gen.addTest(recznybs(
            sumList(sumList(randList(299000, 1, 1000), randList(299000, 1000000, 1000000000)), randList(299000, 1, 1000))
        ));
    }
    gen.endGroup();

    // Grupa 6
    gen.beginGroup();
    {
        Generator::setSeed(824583);gen.addTest(recznybs(
            sumList(sumList(randList(299000, 1, 1000), randList(299000, 1000000, 1000000000)), randList(299000, 1, 1000))
        ));
        Generator::setSeed(201382);gen.addTest(reczny(
            sumList(sumList(sumList(randList(299000, 1, 1000), randList(299000, 1000000, 100000000)), randList(299000, 1, 1000)), {{1000000000, 1000000000, 1000000000}})
        ));
    }
    gen.endGroup();

    // Grupa 7
    gen.beginGroup();
    {
        Generator::setSeed(983584);gen.addTest(recznybs(
            sumList(sumList(randList(299000, 1000000, 1000000000), randList(299000, 1, 1000)), randList(299000, 1000000, 1000000000))
        ));
        Generator::setSeed(129384);gen.addTest(recznybs(
            sumList(sumList(randList(299000, 1, 1000), randList(299000, 1000000, 1000000000)), randList(299000, 1, 1000))
        ));
        Generator::setSeed(234830);gen.addTest(reczny(
            sumList(sumList(sumList(randList(299000, 1, 1000), randList(299000, 1000000, 100000000)), randList(299000, 1, 1000)), {{1000000000, 1000000000, 1000000000}})
        ));
    }
    gen.endGroup();

    gen.generate();
    return 0;
}
