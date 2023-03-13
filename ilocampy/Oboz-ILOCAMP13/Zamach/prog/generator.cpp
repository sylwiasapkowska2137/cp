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
    test.addLine(4, 2);
    test.addLine(3, 1, 4, 2);
    return test;
}

Test randomTest(int n, int k, int h)
{
    Test test;
    test.addLine(n, k);
    vector<int> line;
    for (int i = 0; i < n; i++) {
        line.push_back(R(0, h));
    }
    test.addLine(line);
    return test;
}

Test special1Test(int n, int k, int minw, int maxw, int skok) {
    Test test;
    test.addLine(n, k);

    vector<int> A(n);
    int nast = 0;

    assert(minw <= maxw);
    assert(1 <= skok && skok < n);
    for (int i = skok; i < n; i += skok) {
        A[i] = (nast += R(minw, maxw));
    }

    for (int r = 0; r < n; r++) {
        int p = R(0, n - 1);
        if (A[p] == 0) {
            A[p] = (nast += R(minw, maxw));
        }
    }

    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            A[i] = (nast += R(minw, maxw));
        }
    }

    test.addLine(A);
    return test;
}

int main()
{
    Generator gen("zam");

    gen.addTest(exampleTest());

    // Grupa 1
    gen.beginGroup();
    {
        Generator::setSeed(729374);gen.addTest(randomTest(5, 3, 5));
        Generator::setSeed(729374);gen.addTest(randomTest(10, 10, 2));
        Generator::setSeed(829374);gen.addTest(randomTest(8, 1, 8));
    }
    gen.endGroup();

    // Grupa 2
    gen.beginGroup();
    {
        Generator::setSeed(727535);gen.addTest(randomTest(15, 7, 15));
        Generator::setSeed(124345);gen.addTest(randomTest(20, 9, 11));
        Generator::setSeed(346525);gen.addTest(randomTest(19, 6, 17));
    }
    gen.endGroup();

    // Grupa 3
    gen.beginGroup();
    {
        Generator::setSeed(984535);gen.addTest(randomTest(100, 50, 99));
        Generator::setSeed(923584);gen.addTest(randomTest(97, 2, 89));
        Generator::setSeed(346523);gen.addTest(randomTest(67, 65, 11));
    }
    gen.endGroup();

    // Grupa 4
    gen.beginGroup();
    {
        Generator::setSeed(823743);gen.addTest(randomTest(500, 250, 500));
        Generator::setSeed(421845);gen.addTest(randomTest(389, 17, 275));
        Generator::setSeed(853055);gen.addTest(randomTest(453, 453, 452));
    }
    gen.endGroup();

    // Grupa 5
    gen.beginGroup();
    {
        Generator::setSeed(936593);gen.addTest(randomTest(1000, 500, 1000));
        Generator::setSeed(934753);gen.addTest(randomTest(789, 21, 438));
        Generator::setSeed(843853);gen.addTest(randomTest(823, 801, 456));
        Generator::setSeed(238138);gen.addTest(special1Test(1000, 500, 1000, 1000, 1));
    }
    gen.endGroup();

    // Grupa 6
    gen.beginGroup();
    {
        Generator::setSeed(872374);gen.addTest(randomTest(10, 6, 1000000000));
        Generator::setSeed(948374);gen.addTest(randomTest(9, 4, 100000000));
        Generator::setSeed(993847);gen.addTest(randomTest(12, 12, 999999999));
    }
    gen.endGroup();

    // Grupa 7
    gen.beginGroup();
    {
        Generator::setSeed(238484);gen.addTest(randomTest(100, 50, 1000000));
        Generator::setSeed(998802);gen.addTest(randomTest(100, 100, 1000000));
        Generator::setSeed(972639);gen.addTest(randomTest(999, 847, 999999));
    }
    gen.endGroup();

    // Grupa 8
    gen.beginGroup();
    {
        Generator::setSeed(923743);gen.addTest(randomTest(500, 250, 1000000000));
        Generator::setSeed(854377);gen.addTest(randomTest(500, 500, 1000000000));
        Generator::setSeed(976554);gen.addTest(randomTest(499, 47, 999999999));
        Generator::setSeed(938545);gen.addTest(special1Test(499, 300, 100, 1000, 70));
    }
    gen.endGroup();

    // Grupa 9
    gen.beginGroup();
    {
        Generator::setSeed(937457);gen.addTest(randomTest(700, 500, 1000000000));
        Generator::setSeed(128774);gen.addTest(randomTest(697, 697, 1000000000));
        Generator::setSeed(832764);gen.addTest(randomTest(684, 147, 999999999));
        Generator::setSeed(829347);gen.addTest(special1Test(699, 243, 100000, 100000, 20));
    }
    gen.endGroup();

    // Grupa 10
    gen.beginGroup();
    {
        Generator::setSeed(172934);gen.addTest(randomTest(1000, 500, 1000000000));
        Generator::setSeed(943820);gen.addTest(randomTest(1000, 1000, 1000000000));
        Generator::setSeed(384729);gen.addTest(randomTest(999, 847, 999999999));
        Generator::setSeed(834374);gen.addTest(special1Test(989, 756, 10000, 1000000, 30));
        Generator::setSeed(827344);gen.addTest(special1Test(1000, 20, 500000, 1000000, 123));
        Generator::setSeed(128374);gen.addTest(special1Test(1000, 900, 1, 1000000, 1));
    }
    gen.endGroup();

    gen.generate();
    return 0;
}
