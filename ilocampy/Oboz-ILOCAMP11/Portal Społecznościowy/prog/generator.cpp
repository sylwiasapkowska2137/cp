//Przemysław Jakub Kozłowski
#include "generator.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <cassert>
#define FI first
#define SE second
#define MP make_pair
using namespace std;

Test exampleTest();
Test randomTest(int n, int m, int l);
Test special1Test(int n, int m, int lmin, int lmax, int pmin, int pmax);

int main()
{
    Generator gen("por");

    gen.addTest(exampleTest());

    // S - łączna liczba przedziałów we wszystkich zapytaniach
    // Grupa 1 -- 20p. -- n,m,l <= 10
    gen.beginGroup();
    {
        Generator::setSeed(983573);gen.addTest(randomTest(10, 10, 10));
        Generator::setSeed(836473);gen.addTest(special1Test(10, 10, 5, 10, 1, 3));
        Generator::setSeed(836683);gen.addTest(special1Test(10, 10, 1, 3, 1, 2));
    }
    gen.endGroup();

    // Grupa 2 -- 20p. -- n <= 100 ; S <= 10000
    gen.beginGroup();
    {
        Generator::setSeed(846582);gen.addTest(randomTest(100, 100, 100));
        Generator::setSeed(736945);gen.addTest(special1Test(100, 100, 1, 100, 2, 10));
        Generator::setSeed(247656);gen.addTest(special1Test(97, 1000, 5, 10, 1, 97));
        Generator::setSeed(738465);gen.addTest(special1Test(100, 10, 1000, 1000, 100, 100));
    }
    gen.endGroup();

    // Grupa 3 -- 20p. -- n <= 500 ; S <= 100000
    gen.beginGroup();
    {
        Generator::setSeed(184395);gen.addTest(randomTest(500, 1000, 100));
        Generator::setSeed(826384);gen.addTest(special1Test(500, 100, 500, 1000, 10, 20));
        Generator::setSeed(263748);gen.addTest(special1Test(450, 10000, 2, 10, 1, 450));
        Generator::setSeed(473675);gen.addTest(special1Test(500, 100000, 1, 1, 500, 500));
    }
    gen.endGroup();

    // Grupa 4 -- 20p. -- n <= 1000 ; S <= 100000
    gen.beginGroup();
    {
        Generator::setSeed(735483);gen.addTest(randomTest(1000, 100000, 1));
        Generator::setSeed(465758);gen.addTest(special1Test(1000, 10000, 7, 10, 1, 10));
        Generator::setSeed(937465);gen.addTest(special1Test(1000, 100, 700, 1000, 1000, 1000));
    }
    gen.endGroup();

    // Grupa 5 -- 20p. -- , N <= 1000 ; S <= 1000000
    gen.beginGroup();
    {
        Generator::setSeed(936485);gen.addTest(randomTest(1000, 1000, 1000));
        Generator::setSeed(927365);gen.addTest(special1Test(1000, 1000, 2, 1000, 10, 20));
        Generator::setSeed(182634);gen.addTest(special1Test(1000, 10000, 70, 100, 100, 200));
        Generator::setSeed(349548);gen.addTest(special1Test(1000, 100000, 10, 10, 1000, 1000));
    }
    gen.endGroup();

    gen.generate();
    return 0;
}

Test exampleTest() {
    Test test;

    test.addLine(6);
    test.addLine(0, 0, 1, 0, 1, 1);
    test.addLine(0, 0, 1, 0, 0, 1);
    test.addLine(0, 0, 0, 0, 1, 1);
    test.addLine(1, 0, 0, 0, 0, 1);
    test.addLine(0, 0, 0, 0, 0, 1);
    test.addLine(0, 0, 0, 0, 0, 0);
    test.addLine(2);
    test.addLine(2);
    test.addLine(1, 3);
    test.addLine(5, 6);
    test.addLine(2);
    test.addLine(1, 3);
    test.addLine(5, 5);

    return test;
}

inline int R(int a, int b) {return a+Generator::random()%(b-a+1);}

Test randomTest(int n, int m, int l)
{
    Test test;

    test.addLine(n);
    for(int i = 1;i <= n;i++)
    {
        vector<int> V(n);
        for(int j = 0;j < n;j++)
            V[j] = (i == j+1 ? 0 : R(0, 1));
        test.addLine(V);
    }

    assert(m*l <= 1000000);
    test.addLine(m);
    for(int i = 1;i <= m;i++)
    {
        test.addLine(l);
        for(int i = 1;i <= l;i++)
        {
            int a = R(1, n);
            int b = R(1, n);
            if(a > b) swap(a, b);
            test.addLine(a, b);
        }
    }

    return test;
}

vector<vector<int> > obl(int n, const vector<vector<int> > &B)
{
    vector<vector<int> > A(n+1, vector<int>(n+1, 0) );

    for(int i = 1;i <= n;i++)
        for(int j = i+1;j <= n;j++)
        {
            if(B[i][j] && !B[j][i]) A[j][i] = 1;
            else if(!B[i][j] && B[j][i]) A[i][j] = 1;
        }

    for(int i = 1; i <= n;i++)
        A[i].erase(A[i].begin());
    A.erase(A.begin());

    return A;
}

inline void ustaw(vector<vector<int> > &B, int a, int b)
{
    B[b][a] = 0;
    B[a][b] = 1;
}

Test special1Test(int n, int m, int lmin, int lmax, int pmin, int pmax)
{
    Test test;

    vector<vector<int> > B(n+1, vector<int>(n+1, 0) );
    vector<vector<pair<int,int> > > zap;

    for(int i = 1;i <= m;i++)
    {
        zap.resize(zap.size()+1);
        int l = R(lmin, lmax);
        for(int j = 1;j <= l;j++)
        {
            int dlg = R(pmin, pmax);
            int a = R(1,n-dlg+1);
            int b = a+dlg-1;
            zap.back().push_back(MP(a,b));
        }
    }

    for(int i = 1;i <= n;i++)
        B[i][i] = 1;

    for(int i = 0;i < m;i++)
    {
        vector<pair<int,int> > zaps = zap[i];
        int rl = R(0, zaps.size()-1);
        int kan = R(zaps[rl].FI, zaps[rl].SE);

        sort(zaps.begin(), zaps.end());

        int last = 0;
        for(int j = 0;j < zaps.size();j++)
        {
            last = max(last, zaps[j].FI);
            while(last <= zaps[j].SE)
            {
                ustaw(B, kan, last);
                last++;
            }
        }
    }

    test.addLine(n);
    vector<vector<int> > A = obl(n, B);
    for(int i = 0;i < n;i++)
        test.addLine(A[i]);

    test.addLine(m);
    for(int i = 0;i < m;i++)
    {
        test.addLine(zap[i].size());
        for(int j = 0;j < zap[i].size();j++)
            test.addLine(zap[i][j].FI, zap[i][j].SE);
    }

    return test;
}
