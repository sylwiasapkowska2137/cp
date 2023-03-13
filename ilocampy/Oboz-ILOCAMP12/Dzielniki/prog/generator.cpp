//Przemysław Jakub Kozłowski
#include "generator.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <cassert>
using namespace std;

inline int R(int a, int b) {return a+Generator::random()%(b-a+1);}

Test reczny(int x, int y)
{
    Test test;
    test.addLine(x, y);
    return test;
}

int main()
{
    Generator gen("dzi");

    // Przykładowy
    gen.addTest(reczny(2, 4));

    // Grupa 1 -- 15p. -- x = 2, y <= 10000 -- 15% punktów
    gen.beginGroup();
    {
        gen.addTest(reczny(2, 1));
        gen.addTest(reczny(2, 2));
        gen.addTest(reczny(2, 13));
        gen.addTest(reczny(2, 50));
        gen.addTest(reczny(2, 67));
        gen.addTest(reczny(2, 100));
        gen.addTest(reczny(2, 1000));
        gen.addTest(reczny(2, 9999));
        gen.addTest(reczny(2, 10000));
    }
    gen.endGroup();

    // Grupa 2 -- 15p. -- x = 2, y <= 100000 -- 30% punktów
    gen.beginGroup();
    {
        gen.addTest(reczny(2, 1000));
        gen.addTest(reczny(2, 10000));
        gen.addTest(reczny(2, 12345));
        gen.addTest(reczny(2, 99999));
        gen.addTest(reczny(2, 100000));
    }
    gen.endGroup();

    // Grupa 3 -- 20p. -- x,y <= 1000 -- 20% punktów
    gen.beginGroup();
    {
        gen.addTest(reczny(3, 999));
        gen.addTest(reczny(7, 1000));
        gen.addTest(reczny(127, 3));
        gen.addTest(reczny(977, 1));
        gen.addTest(reczny(997, 999));
        gen.addTest(reczny(839, 1000));
    }
    gen.endGroup();

    // Grupa 4 -- 15p. -- x,y <= 20000 -- 50% punktów
    gen.beginGroup();
    {
        gen.addTest(reczny(3, 20000));
        gen.addTest(reczny(947, 20000));
        gen.addTest(reczny(7853, 20000));
        gen.addTest(reczny(17977, 17977));
        gen.addTest(reczny(19997, 19949));
        gen.addTest(reczny(19997, 123));
    }
    gen.endGroup();

    // Grupa 5 -- 50p. -- x,y <= 100000 -- 100% punktów
    gen.beginGroup();
    {
        gen.addTest(reczny(5, 100000));
        gen.addTest(reczny(25639, 99999));
        gen.addTest(reczny(48353, 48571));
        gen.addTest(reczny(97231, 99000));
        gen.addTest(reczny(99929, 48571));
        gen.addTest(reczny(99961, 100000));
    }
    gen.endGroup();

    gen.generate();
    return 0;
}
