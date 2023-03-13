#include "generator.h"

#include <memory>
#include <bits/stdc++.h>

using graph_t = std::vector<std::pair<int, int>>;

Test exampleTest();
Test simple1();
Test small1();
Test small2();
Test randomSequence(int n, int k, int minValue, int maxValue);
Test sortedSequence(int n, int k, int minValue, int maxValue, bool ascending);


int main() {
    Generator gen("dzi");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
    
    gen.beginGroup(); //1
    {
        gen.addTest(simple1());
        gen.addTest(small1());
        gen.addTest(small2());
    }
    gen.endGroup();
    
    gen.beginGroup(); //2
    {
        Generator::setSeed(51351);
        gen.addTest(randomSequence(20, 10, -10, 10));
        Generator::setSeed(68161);
        gen.addTest(sortedSequence(20, 10, -10, 10, false));
        Generator::setSeed(84585);
        gen.addTest(randomSequence(20, 15, 5, 5));
        Generator::setSeed(86248);
        gen.addTest(randomSequence(20, 15, 1, 1));
    }
    gen.endGroup();
    
    gen.beginGroup(); //3
    {
        Generator::setSeed(58492);
        gen.addTest(randomSequence(200, 50, -100, 1000));
        Generator::setSeed(985832);
        gen.addTest(randomSequence(200, 50, -10, 10));
        Generator::setSeed(97644);
        gen.addTest(randomSequence(200, 50, 100, 110));
        Generator::setSeed(57580);
        gen.addTest(randomSequence(200, 50, -100, 100));
    }
    gen.endGroup();
    
    gen.beginGroup(); //4
    {
        Generator::setSeed(83627);
        gen.addTest(randomSequence(1000, 100, 1, 1000000000));
        Generator::setSeed(910916);
        gen.addTest(sortedSequence(1000, 100, -20, 1000, true));
        Generator::setSeed(526810);
        gen.addTest(randomSequence(1000, 100, -20, 20));
        Generator::setSeed(927635);
        gen.addTest(randomSequence(1000, 100, 1000, 1100));
    }
    gen.endGroup();
    
    gen.beginGroup(); //5
    {
        Generator::setSeed(99911);
        gen.addTest(randomSequence(50000, 100, -1000000000, 1000000000));
        Generator::setSeed(965433);
        gen.addTest(randomSequence(50000, 100, 1, 50));
        Generator::setSeed(33733);
        gen.addTest(randomSequence(50000, 100, 10000, 11000));
        Generator::setSeed(351351);
        gen.addTest(randomSequence(50000, 100, 1, 1000));
    }
    gen.endGroup();
    
    gen.beginGroup(); //6
    {
        int n = 500000;
        int q = 100;
        Generator::setSeed(531511);
        gen.addTest(randomSequence(n, q, -1000000000, 1000000000));
        Generator::setSeed(41312);
        gen.addTest(randomSequence(n, q, -10, 10));
        Generator::setSeed(64362);
        gen.addTest(randomSequence(n, q, 50, 100));
        Generator::setSeed(6462);
        gen.addTest(randomSequence(n, q, 900000000, 1000000000));
    }
    gen.endGroup();
    
    gen.beginGroup(); //7
    {
        int n = 500000;
        int q = 100;
        Generator::setSeed(642624);
        gen.addTest(randomSequence(n, q, 1, 1));
        Generator::setSeed(8224502);
        gen.addTest(randomSequence(n, q, 1000000000, 1000000000));
        Generator::setSeed(34254521);
        gen.addTest(sortedSequence(n, q, 100, 100000, false));
        Generator::setSeed(492552);
        gen.addTest(randomSequence(n, q, 20, 100));
    }
    gen.endGroup();
    
    gen.generate();
}

int random(int a, int b);
std::vector<int> randomQueries(int n, int k);

Test exampleTest() {
    Test test;
    
    test.addLine(9);
    test.addLine(5, 4, 2, 4, 2, 5, 1, 2, 1);
    
    return test;
}

Test simple1() {
    Test test;
    
    test.addLine(2);
    test.addLine(1, 1);
    
    return test;
}

Test small1() {
    Test test;
    
    test.addLine(7);
    test.addLine(3, 6, 4, 1, 1, 6, 7);
    
    return test;
}

Test small2() {
    Test test;
    
    test.addLine(10);
    test.addLine(4, 1, 9, 7, 2, 6, 2, 4, 5, 5);
    
    return test;
}

Test sortedSequence(int n, int k, int minValue, int maxValue, bool ascending) {
    Test test;
    std::vector<int> sequence(n);
    
    test.addLine(n);
    for(int i = 0; i < n; i++) {
        sequence[i] = random(minValue, maxValue);
    }
    
    sort(sequence.begin(), sequence.end());
    if(ascending == false) {
        reverse(sequence.begin(), sequence.end());
    }
    test.addLine(sequence);
    
    return test;
}

Test randomSequence(int n, int k, int minValue, int maxValue) {
    Test test;
    std::vector<int> sequence(n);
    test.addLine(n);
    
    for(int i = 0; i < n; i++) {
        sequence[i] = random(minValue, maxValue);
    }
    test.addLine(sequence);
    
    return test;
}

std::vector<int> randomQueries(int n, int k) {
    std::vector<int> ret;
    for(int i = 0; i < k; i++) {
        ret.push_back(random(1, n));
    }
    return ret;
}

int random(int a, int b) {
    return rand() % (b - a + 1) + a;
}