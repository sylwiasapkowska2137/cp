//Przemysław Jakub Kozłowski
#include "generator.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

Test exampleTest();
Test randomTest(int n, int m);
Test special1Test(int n, int m, int k);

int main()
{
    Generator gen("odz");

    gen.addTest(exampleTest());

    // Grupa 1 -- 10p. -- n,m <= 7 -- 10% punktów
    gen.beginGroup();
    {
        Generator::setSeed(298434);gen.addTest(randomTest(7, 7));
        Generator::setSeed(873548);gen.addTest(randomTest(6, 5));
        Generator::setSeed(357465);gen.addTest(randomTest(1, 1));
        Generator::setSeed(783475);gen.addTest(special1Test(7, 7, 3));
    }
    gen.endGroup();

    // Grupa 2 -- 10p. -- n <= 4 ; m <= 200
    gen.beginGroup();
    {
        Generator::setSeed(864743);gen.addTest(randomTest(4, 200));
        Generator::setSeed(873647);gen.addTest(randomTest(6, 5));
    }
    gen.endGroup();

    // Grupa 3 -- 10p. -- n <= 200 ; m <= 4
    gen.beginGroup();
    {
        Generator::setSeed(834357);gen.addTest(randomTest(200, 4));
        Generator::setSeed(375636);gen.addTest(randomTest(150, 1));
    }
    gen.endGroup();

    // Grupa 4 -- 10p. -- n,m <= 1000 -- 40% punktów
    gen.beginGroup();
    {
        Generator::setSeed(294754);gen.addTest(special1Test(998, 999, 5));
        Generator::setSeed(937535);gen.addTest(randomTest(1000, 1000));
    }
    gen.endGroup();

    // Grupa 5 -- 10p. -- n <= 1000 ; m <= 10^9 -- 50% punktów
    gen.beginGroup();
    {
        Generator::setSeed(294754);gen.addTest(randomTest(1000, 1000000));
        Generator::setSeed(386554);gen.addTest(randomTest(1000, 1000000000));
    }
    gen.endGroup();

    // Grupa 6 -- 10p. -- n,m <= 10^5 -- 60% punktów
    gen.beginGroup();
    {
        Generator::setSeed(484554);gen.addTest(randomTest(10000, 100000));
        Generator::setSeed(834754);gen.addTest(randomTest(100000, 100000));
    }
    gen.endGroup();

    // Grupa 7 -- 10p. -- n <= 10^5 ; m <= 10^9 -- 70% punktów
    gen.beginGroup();
    {
        Generator::setSeed(483423);gen.addTest(randomTest(100000, 10000000));
        Generator::setSeed(293475);gen.addTest(randomTest(100000, 1000000000));
    }
    gen.endGroup();

    // Grupa 8 -- 10p. -- n <= 5*10^5 ; m <= 10^9 -- 80% punktów
    gen.beginGroup();
    {
        Generator::setSeed(238575);gen.addTest(special1Test(500000, 500000000, 10000));
        Generator::setSeed(486475);gen.addTest(randomTest(500000, 1000000000));
    }
    gen.endGroup();

    // Grupa 9 -- 10p. -- n,m <= 10^6
    gen.beginGroup();
    {
        Generator::setSeed(854754);gen.addTest(special1Test(1000000, 1000000, 100));
        Generator::setSeed(934754);gen.addTest(randomTest(1000000, 1000000));
    }
    gen.endGroup();

    // Grupa 10 -- 10p. -- n <= 10^6 ; m <= 10^9 -- 100% punktów
    gen.beginGroup();
    {
        Generator::setSeed(234854);gen.addTest(special1Test(1000000, 1000000000, 2));
        Generator::setSeed(934584);gen.addTest(special1Test(1000000, 1000000000, 5));
        Generator::setSeed(354675);gen.addTest(special1Test(1000000, 1000000000, 1000));
        Generator::setSeed(834854);gen.addTest(randomTest(1000000, 1000000000));
    }
    gen.endGroup();

    gen.generate();
    return 0;
}

Test exampleTest() {
    Test test;

    test.addLine(4, 7);
    test.addLine(0, 4, 6, 0);

    return test;
}

inline int R(int a, int b) {return a+Generator::random()%(b-a+1);}

vector<int> obl(const vector<int> &V)
{
    vector<int> ret(V.size());
    ret[0] = -1;
    for(int i = 1;i < V.size();i++)
    {
        int p = i-1;
        while(p != -1 && V[p] >= V[i]) p = ret[p];
        ret[i] = p;
    }
    for(int i = 0;i < ret.size();i++)
        ret[i] = (ret[i] == -1 ? 0 : V[ret[i]]);
    return ret;
}

Test randomTest(int n, int m)
{
    Test test;
    test.addLine(n, m);

    vector<int> A(n);
    for(int i = 1;i <= n;i++)
        A[i-1] = R(1,m);
    vector<int> B = obl(A);

    test.addLine(B);
    return test;
}

Test special1Test(int n, int m, int k)
{
    Test test;
    test.addLine(n, m);

    vector<int> A(n);
    for(int i = 1;i <= n;i++)
        A[i-1] = R(1,m);

    int dlg = n/k;
    for(int num = 1;num <= k;num++)
    {
        if(num%2 == 0) sort(A.begin()+(num-1)*dlg, A.begin()+num*dlg);
        else sort(A.begin()+(num-1)*dlg, A.begin()+num*dlg, greater<int>());
    }
    sort(A.begin()+k*dlg, A.end());

    vector<int> B = obl(A);
    test.addLine(B);

    return test;
}
