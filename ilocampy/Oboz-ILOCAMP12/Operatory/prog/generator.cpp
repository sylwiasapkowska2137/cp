//Przemysław Jakub Kozłowski
#include "generator.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <cassert>
using namespace std;

Test reczny(string s)
{
    Test test;
    test.addLine(s.size());
    test.addLine(s);
    return test;
}

inline int R(int a, int b) {return a+Generator::random()%(b-a+1);}

Test randomTest(int n)
{
    if(n%2 == 0) n--;
    string S;
    S.resize(n);
    for(int i = 0;i < n;i++)
    {
        if(i%2 == 0)
        {
            int r = R(0,9);
            S[i] = '0'+r;
        }
        else
        {
            int r = R(10, 14);
            if(r == 10)
                S[i] = '<';
            else if(r == 11)
                S[i] = '>';
            else if(r == 12)
                S[i] = '=';
            else if(r == 13)
                S[i] = '+';
            else if(r == 14)
                S[i] = '-';
        }
    }
    return reczny(S);
};

Test randomTest2(int n, double prawd)
{
    if(n%2 == 0) n--;
    string S;
    S.resize(n);
    for(int i = 0;i < n;i++)
    {
        if(i%2 == 0)
        {
            int r = R(0,9);
            S[i] = '0'+r;
        }
        else
        {
            const int W = 1000000000;
            int r1 = R(1, W);
            if(r1 <= prawd*W)
            {
                int r2 = R(1, 3);
                if(r2 == 1)
                    S[i] = '<';
                else if(r2 == 2)
                    S[i] = '>';
                else if(r2 == 3)
                    S[i] = '=';
                else
                    assert(false);
            }
            else
            {
                int r2 = R(1,2);
                if(r2 == 1)
                    S[i] = '+';
                else if(r2 == 2)
                    S[i] = '-';
                else
                    assert(false);
            }
        }
    }
    return reczny(S);
};

Test specialTest3(int n)
{
    while(n%4 != 3) n--;

    string S;

    int k = (n+1)/4;

    S += "9";
    for(int i = 2;i <= k;i++)
        S += "+9";
    S += "=9";
    for(int i = 2;i <= k;i++)
        S += "+9";

    return reczny(S);
};

Test specialTest4(int n)
{
    while(n%4 != 3) n--;

    string S;

    int k = (n+1)/4;

    S += "0";
    for(int i = 2;i <= k;i++)
        S += "-9";
    S += "=0";
    for(int i = 2;i <= k;i++)
        S += "-9";

    return reczny(S);
};

Test specialTest5(int n)
{
    while(n%4 != 3) n--;

    string S;

    int k = (n+1)/4 - 2;

    S += "9";
    for(int i = 2;i <= k;i++)
        S += "+9";
    S += "-1";
    for(int i = 2;i <= k;i++)
        S += "-9";
    S += "=3-4";

    return reczny(S);
};

int main()
{
    Generator gen("ope");

    gen.beginGroup();
    {
        gen.addTest(reczny("7-5<3=5"));
        gen.addTest(reczny("2+5<6-4<5=3"));
    }
    gen.endGroup();


    // Grupa 1 -- 10p. -- n <= 10 -- 10% punktów
    gen.beginGroup();
    {
        gen.addTest(reczny("1-5=5"));
        gen.addTest(reczny("1<2<3<4<5"));
        gen.addTest(reczny("1>2<3>4>5"));
        gen.addTest(reczny("1>2<3<4>5"));
        gen.addTest(reczny("9>8<7>6>5"));
        gen.addTest(reczny("1>1>1>1<1"));
        gen.addTest(reczny("1=1=1=1=1"));
        gen.addTest(reczny("1+2+3=6=6"));
        gen.addTest(reczny("1+2+3=6=7"));
        gen.addTest(reczny("1-2-3=1-5"));
        gen.addTest(reczny("9+9=9+9+9"));
        gen.addTest(reczny("9+9=9+1+8"));
        gen.addTest(reczny("9+7=9+9-2"));
        gen.addTest(reczny("7-4=8-5"));
        gen.addTest(reczny("7-4=8-4"));
        gen.addTest(reczny("1-2-3-4-5"));

    }
    gen.endGroup();

    // Grupa 2 -- 10p. -- n <= 100 -- 20% punktów
    gen.beginGroup();
    {
        gen.addTest(reczny("1+2+3+4+5+6+7+8+9+5=5+5+5+5+5+5+5+5+5+5"));
        gen.addTest(reczny("1+2+3+4+5+6+7+8+9+5=5+5+5+5+5+5+5+5+5+5"));
        gen.addTest(reczny("1+2+3>4+5+6+7+8+9+5=5+5+5+5+5+5+5<5+5+5"));
        gen.addTest(reczny("1-2+3>4-5+6+7-8+9+5=5-5+5+5-5+5+5<5-5+5"));
        gen.addTest(reczny("1-2-3-4-5-6-7-8-9>8+1+1+1+1+1+1+1+1+1+1"));
        gen.addTest(reczny("1-2-3-4-5-6-7-8-9>8+1+1+1+1+2+2+2-1-1-1"));
        gen.addTest(reczny("5<8-1-6>5+1=1=1>1-0+0=0+3=3-3=0"));
        gen.addTest(reczny("5+2+3=1+4+5-6-1-9-1+4=1-6+7-2=3+1+1+1+1+1+1+1+1+1=5+6+7=8+5=9+4+2+4<1+1+1+1+1+1"));
        Generator::setSeed(283475);gen.addTest(randomTest(100));
        Generator::setSeed(934875);gen.addTest(randomTest2(100, 0.1));
    }
    gen.endGroup();

    // Grupa 3 -- 10p. -- n <= 1000 -- 30% punktów
    gen.beginGroup();
    {
        Generator::setSeed(345345);gen.addTest(randomTest(1000));
        Generator::setSeed(925735);gen.addTest(randomTest2(1000, 0.1));
        Generator::setSeed(288937);gen.addTest(randomTest2(1000, 0.01));
        Generator::setSeed(398499);gen.addTest(specialTest3(1000));
        Generator::setSeed(293845);gen.addTest(specialTest4(1000));
        Generator::setSeed(294382);gen.addTest(specialTest5(1000));
    }
    gen.endGroup();

    // Grupa 4 -- 10p. -- n <= 10000 -- 40% punktów
    gen.beginGroup();
    {
        Generator::setSeed(930583);gen.addTest(randomTest(10000));
        Generator::setSeed(903454);gen.addTest(randomTest2(10000, 0.001));
        Generator::setSeed(129384);gen.addTest(specialTest3(10000));
        Generator::setSeed(549683);gen.addTest(specialTest4(10000));
    }
    gen.endGroup();

    // Grupa 5 -- 10p. -- n <= 100000 -- 50% punktów
    gen.beginGroup();
    {
        Generator::setSeed(234493);gen.addTest(randomTest(100000));
        Generator::setSeed(924243);gen.addTest(randomTest2(100000, 0.001));
        Generator::setSeed(239485);gen.addTest(specialTest3(100000));
        Generator::setSeed(239486);gen.addTest(specialTest4(100000));
        Generator::setSeed(299485);gen.addTest(specialTest5(100000));
    }
    gen.endGroup();

    // Grupa 6 -- 10p. -- n <= 1000000 -- 60% punktów
    gen.beginGroup();
    {
        Generator::setSeed(923483);gen.addTest(randomTest(1000000));
        Generator::setSeed(234958);gen.addTest(randomTest2(1000000, 0.001));
    }
    gen.endGroup();

    // Grupa 7 -- 10p. -- n <= 5000000 -- 70% punktów
    gen.beginGroup();
    {
        Generator::setSeed(139573);gen.addTest(randomTest(5000000));
        Generator::setSeed(375235);gen.addTest(randomTest2(5000000, 0.001));
    }
    gen.endGroup();

    // Grupa 8 -- 10p. -- n <= 7000000 -- 80% punktów
    gen.beginGroup();
    {
        Generator::setSeed(238535);gen.addTest(randomTest(7000000));
        Generator::setSeed(234853);gen.addTest(randomTest2(7000000, 0.0001));
        Generator::setSeed(938475);gen.addTest(specialTest5(7000000));
    }
    gen.endGroup();

    // Grupa 9 -- 10p. -- n <= 9000000 -- 90% punktów
    gen.beginGroup();
    {
        Generator::setSeed(348854);gen.addTest(randomTest(9000000));
        Generator::setSeed(458395);gen.addTest(randomTest2(9000000, 0.0001));
    }
    gen.endGroup();

    // Grupa 10 -- 10p. -- n <= 10000000 -- 100% punktów
    gen.beginGroup();
    {
        Generator::setSeed(349583);gen.addTest(randomTest(10000000));
        Generator::setSeed(394853);gen.addTest(randomTest2(10000000, 0.0001));
        Generator::setSeed(294835);gen.addTest(specialTest3(10000000));
        Generator::setSeed(293858);gen.addTest(specialTest4(10000000));
    }
    gen.endGroup();

    gen.generate();
    return 0;
}
