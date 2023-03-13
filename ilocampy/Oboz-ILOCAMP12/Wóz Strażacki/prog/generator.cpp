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

const int MAXVAL = 1000000000;

Test cars(vector<int> spaces, vector<int> wozy, int maxval)
{
    Test test;

    int n = spaces.size();
    int m = n - 1;

    LL suma_spa = 0;
    for(int i = 0;i < n;i++)
    {
        assert(0 <= spaces[i] && spaces[i] <= maxval);
        suma_spa += spaces[i];
    }

    assert(1 <= suma_spa && suma_spa <= maxval);
    int reszta = maxval-suma_spa;
    assert(m <= reszta);

    int suma_sam = 0;
    vector<int> samochody(m);
    for(int i = 0;i < m;i++)
    {
        samochody[i] = R(1, reszta-(m-i-1));
        reszta -= samochody[i];
        assert(1 <= samochody[i] && samochody[i] <= maxval);
        suma_sam += samochody[i];
    }
    assert(1 <= suma_sam && suma_sam+suma_spa <= maxval);

    shuffle(samochody.begin(), samochody.end(), Generator::getGen());

    test.addLine(m, suma_sam+suma_spa);

    int pos = 0;
    for(int i = 0;i < m;i++)
    {
        pos += spaces[i];
        test.addLine(pos, samochody[i]);
        pos += samochody[i];
    }

    int q = wozy.size();
    test.addLine(q);
    for(int i = 0;i < q;i++)
    {
        if(i > 0) assert(wozy[i] >= wozy[i - 1]);
        assert(0 <= wozy[i] && wozy[i] <= MAXVAL);
        test.addLine(wozy[i]);
    }

    return test;
}

Test randomTest(int n, int wspa, int wcar, int q, int wozmin, int wozmax)
{
    assert(1 <= wspa+wcar && wspa+wcar <= MAXVAL);
    vector<int> spa = LiczbyOSumie(n, wspa);
    vector<int> wozy = ArraySorted(UniqueRandom(q, wozmin, wozmax));
    assert(wozy.back() <= wspa); // Odpowiedź to nie -1.
    return cars(spa, wozy, wspa+wcar);
}

Test exampleTest()
{
    Test test;

    test.addLine(4, 22);
    test.addLine(2, 3);
    test.addLine(7, 3);
    test.addLine(11, 2);
    test.addLine(16, 4);
    test.addLine(1);
    test.addLine(7);

    return test;
}

Test mojTest()
{
    vector<int> spaces;
    spaces.push_back(100);
    for(int i = 1;i <= 100;i++)
        spaces.push_back(1);
    spaces.push_back(30);
    vector<int> wozy = UniqueRandom(99, 1, 300);
    wozy.push_back(220);
    sort(wozy.begin(), wozy.end());
    return cars(spaces, wozy, 230+101);
}

int main()
{
    Generator gen("woz");

    gen.addTest(exampleTest());

    // Grupa 1 -- 00p. -- n <= 10, w <= 100, q <= 10 -- 00% punktów
    gen.beginGroup();
    {
        Generator::setSeed(729374);gen.addTest(cars({1,2,3}, {7}, 11));
        Generator::setSeed(729374);gen.addTest(cars({1,2,3}, {6}, 100));
        Generator::setSeed(829374);gen.addTest(randomTest(10, 100, 100, 10, 1, 100));
        Generator::setSeed(923843);gen.addTest(randomTest(10, 30, 70, 10, 1, 30));
        Generator::setSeed(584739);gen.addTest(randomTest(10, 50, 50, 10, 1, 50));
    }
    gen.endGroup();

    // Grupa 2 -- 00p. -- n <= 1000, w <= 100000, q <= 100 -- 00% punktów
    gen.beginGroup();
    {
        Generator::setSeed(937465);gen.addTest(mojTest());
        Generator::setSeed(734586);gen.addTest(randomTest(1000, 50000, 50000, 100, 1, 50000));
        Generator::setSeed(239495);gen.addTest(randomTest(957, 70000, 30000, 100, 1, 70000));
    }
    gen.endGroup();

    // Grupa 3 -- 00p. -- n <= 10000, w <= 1000000, q <= 100 -- 00% punktów
    gen.beginGroup();
    {
        Generator::setSeed(234825);gen.addTest(randomTest(10000, 500000, 500000, 100, 1, 500000));
        Generator::setSeed(935763);gen.addTest(randomTest(9507, 1234, 10000, 100, 1, 1234));
    }
    gen.endGroup();

    // Grupa 4 -- 00p. -- n <= 100000, w <= 1000000000, q <= 10 -- 80% punktów
    gen.beginGroup();
    {
        Generator::setSeed(127428);gen.addTest(randomTest(100000, 500000000, 500000000, 10, 1, 500000000));
        Generator::setSeed(927473);gen.addTest(randomTest(99999, 500000, 100000, 10, 1, 500000));
    }
    gen.endGroup();

    // Grupa 5 -- 00p. -- n <= 1000000, w <= 1000000000, q <= 100 -- 100% punktów
    gen.beginGroup();
    {
        Generator::setSeed(982252);gen.addTest(randomTest(1000000, 500000000, 500000000, 100, 1, 500000000));
        Generator::setSeed(938382);gen.addTest(randomTest(999999, 998000000, 1000000, 100, 1, 998000000));
        Generator::setSeed(263747);gen.addTest(randomTest(999979, 100000, 1000000, 100, 1, 100000));
    }
    gen.endGroup();


    gen.generate();
    return 0;
}
