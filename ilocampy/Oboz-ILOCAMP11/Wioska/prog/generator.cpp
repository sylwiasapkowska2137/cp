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
typedef long long LL;

Test exampleTest();
Test randomTest(int n, int m, int spadek, int rozrzut);
Test fromFile(const std::string &filename);

int main()
{
    Generator gen("wio");

    gen.addTest(exampleTest());

    // W - maksymalna waga krawędzi
    // Grupa 1 -- n <= 10 ; w <= 10000
    gen.beginGroup();
    {
        Generator::setSeed(173848);gen.addTest(randomTest(10, 10000, 500, 10));
        Generator::setSeed(836426);gen.addTest(randomTest(10, 10000, 1000, 100));
        Generator::setSeed(353683);gen.addTest(randomTest(10, 10000, 100, 5));
        Generator::setSeed(927485);gen.addTest(randomTest(9, 10000, 3000, 5));
        Generator::setSeed(837495);gen.addTest(randomTest(10, 10000, 5000, 5));
        gen.addTest(fromFile("reczny1.in"));
    }
    gen.endGroup();

    // Grupa 2 -- n <= 30 ; w <= 10^9
    gen.beginGroup();
    {
        Generator::setSeed(839457);gen.addTest(randomTest(30, 1000000000, 100, 10));
        Generator::setSeed(283745);gen.addTest(randomTest(30, 1000000000, 1000, 1000));
        Generator::setSeed(937485);gen.addTest(randomTest(30, 1000000000, 10000, 100));
        Generator::setSeed(674836);gen.addTest(randomTest(30, 1000000000, 100000, 10));
        Generator::setSeed(192743);gen.addTest(randomTest(30, 1000000000, 1000000, 1000));
        Generator::setSeed(293845);gen.addTest(randomTest(30, 1000000000, 10000000, 5));
        Generator::setSeed(128374);gen.addTest(randomTest(30, 1000000000, 100000000, 100));
        gen.addTest(fromFile("reczny2.in"));
        gen.addTest(fromFile("reczny8.in"));
    }
    gen.endGroup();

    // Grupa 3 -- n <= 100 ; w <= 10^9
    gen.beginGroup();
    {
        Generator::setSeed(908456);gen.addTest(randomTest(100, 1000000000, 500000, 10000));
        Generator::setSeed(394545);gen.addTest(randomTest(100, 1000000000, 1000000, 1000));
        Generator::setSeed(294843);gen.addTest(randomTest(100, 1000000000, 9999000, 10));
        Generator::setSeed(923745);gen.addTest(randomTest(100, 1000000000, 10000000, 10));
        Generator::setSeed(298547);gen.addTest(randomTest(100, 1000000000, 10000000, 100));
        Generator::setSeed(287439);gen.addTest(randomTest(100, 1000000000, 50000000, 10));
        Generator::setSeed(293845);gen.addTest(randomTest(100, 1000000000, 100000000, 1000));
        gen.addTest(fromFile("reczny3.in"));
        gen.addTest(fromFile("reczny4.in"));
        gen.addTest(fromFile("reczny5.in"));
        gen.addTest(fromFile("reczny6.in"));
        gen.addTest(fromFile("reczny7.in"));
    }
    gen.endGroup();

    gen.generate();
    return 0;
}

Test exampleTest() {
    Test test;

    test.addLine(3);
    test.addLine(1, 2);
    test.addLine(2, 2, 2);
    test.addLine(3, 2, 100);
    test.addLine(100, 1, 100);
    test.addLine(2, 2, 2);
    test.addLine(2, 100, 100, 2);
    test.addLine(2, 100, 3, 2);
    test.addLine(2, 3, 100, 2);

    return test;
}

inline int R(int a, int b) {return a+Generator::random()%(b-a+1);}

Test randomTest(int n, int w, int spadek, int rozrzut)
{
    Test test;

    test.addLine(n);

    int wiox = R(1, n);
    int wioy = R(1, n);
    test.addLine(wiox, wioy);

    for(int i = 1;i <= n+1+n;i++)
    {
        vector<int> linia;
        for(int j = 1;j <= (i <= n+1 ? n : n+1);j++)
        {
            int odl = abs(wioy-i)+abs(wiox-j);
            int srodek = max(1LL,w-(LL)spadek*odl);
            int pocz = max(1,srodek-rozrzut);
            int kon = min(w,srodek+rozrzut);
            int waga = R(pocz, kon);
            assert(1 <= waga && waga <= w);

            linia.push_back(waga);
        }
        test.addLine(linia);
    }

    return test;
}

Test fromFile(const std::string &filename) {
    std::ifstream ifs("../test_reczne/" + filename);

    Test test;
    int n;
    ifs >> n;
    test.addLine(n);

    int wiox, wioy;
    ifs >> wiox >> wioy;
    test.addLine(wiox, wioy);

    for(int i = 1;i <= n+1;i++)
    {
        vector<int> line;
        for(int j = 1;j <= n;j++)
        {
            int a;
            ifs >> a;
            line.push_back(a);
        }
        test.addLine(line);
    }

    for(int i = 1;i <= n;i++)
    {
        vector<int> line;
        for(int j = 1;j <= n+1;j++)
        {
            int a;
            ifs >> a;
            line.push_back(a);
        }
        test.addLine(line);
    }

    return test;
}

