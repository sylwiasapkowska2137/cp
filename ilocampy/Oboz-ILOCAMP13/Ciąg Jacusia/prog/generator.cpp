#include "generator.h"

#include <memory>
#include <assert.h>
using namespace std;

long long M = 1000005;
long long MAX_V = 1000000000;

int R(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

Test exampleTest() {
  Test test;
  test.addLine(8);
  test.addLine(1, -1, -1, 6, 10, -1, 12, -1);
  return test;
}
  
Test randomTestWithSolution(int n, int blockMaxSize, int random1, int random2) {
    Test test;
    
    test.addLine(n);
    
    int block = R(1, blockMaxSize);
    int a = block;
    int change = 0;
    
    vector <int> V;
    
    for (int i=1; i<=n; i++) {
        int x = R(1, random1);
        
        if (x < random2) {
            if (change <= 1) {
                V.push_back(a);
        
                change = R(1, block);
                a += change;
            }
            else {
                V.push_back(-1);
                change--;
            }
        }
        else {
            V.push_back(a);
        
            change = R(1, block);
            a += change;
        }
        
        assert(a <= 1000000000);
    }
    
    test.addLine(V);

    return test;
}

Test randomTestWithoutSolution(int n, int div) {
    Test test;
    
    test.addLine(n);
    
    int last = 0;
    int ile = 0;
    vector <int> V;
    int block;
    
    while (ile < n) {
        int x = R(1, 3);
        
        if (x == 1) {
            block = R(1, n/div);
            int count = block;
            
            while (count-- && ile < n) {
                V.push_back(-1);
                ile++;
            }
            if (ile == n)
                break;
        }
        else {
            x = R(1, 3);
            
            if (x == 1) {
                V.push_back(last + block);
                last += block;
                ile++;
            }
            else {
                int next = last + block + R(1, block);
                V.push_back(next);
                ile++;
                last = next;
            }
        }
    }

    test.addLine(V);
    
    return test;
}

Test corner1() {
    Test test;
    
    test.addLine(5);
    test.addLine(5, 4, 3, 2, 1);
    
    return test;
}

Test corner2() {
    Test test;
    
    test.addLine(5);
    test.addLine(3, 6, 9, 10, 13);
    
    return test;
}

Test corner3() {
    Test test;
    
    test.addLine(6);
    test.addLine(5, 7, 7, 9, 10, 11);
    
    return test;
}

Test corner4() {
    Test test;
    
    test.addLine(6);
    test.addLine(5, -1, -1, 6, 10, 11);
    
    return test;
}

Test corner5() {
    Test test;
    
    test.addLine(6);
    test.addLine(1, -1, -1, -1, -1, 5);
    
    return test;
}

Test corner6() {
    Test test;
    
    test.addLine(7);
    test.addLine(-1, -1, -1, -1, -1, -1, 6);
    
    return test;
}

Test corner7() {
    Test test;
    
    test.addLine(10);
    test.addLine(-1, -1, -1, -1, 5, -1, -1, 7, -1, 9);
    
    return test;
}



int main() {
    Generator gen("cia");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    //1
    gen.beginGroup();
    {
        Generator::setSeed(1982755341);

        gen.addTest(corner1());
        gen.addTest(corner3());
        gen.addTest(corner7());
        gen.addTest(randomTestWithSolution(10, 4, 10, 2));
        gen.addTest(randomTestWithSolution(10, 6, 10, 3));
        gen.addTest(randomTestWithSolution(10, 5, 10, 5));
    }
    gen.endGroup();

    //2
    gen.beginGroup();
    {
        Generator::setSeed(2942755341);

        gen.addTest(corner2());
        gen.addTest(randomTestWithSolution(200, 4, 10, 4));
        gen.addTest(randomTestWithSolution(200, 100, 10, 3));
        gen.addTest(randomTestWithSolution(200, 50, 10, 8));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        Generator::setSeed(1982734123);

        gen.addTest(corner4());
        gen.addTest(randomTestWithSolution(1000, 5, 10, 2));
        gen.addTest(randomTestWithSolution(1000, 10, 10, 3));
        gen.addTest(randomTestWithSolution(1000, 1000, 10, 5));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        Generator::setSeed(3382755341);

        gen.addTest(randomTestWithSolution(500000, 10, 10, 2));
        gen.addTest(randomTestWithSolution(100000, 50, 10, 8));
        gen.addTest(randomTestWithSolution(500000, 3, 10, 0));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        Generator::setSeed(29487547);

        gen.addTest(corner5());
        gen.addTest(corner4());
        gen.addTest(corner6());
        gen.addTest(randomTestWithSolution(500000, 4, 10, 0));
        gen.addTest(randomTestWithoutSolution(500000, 100));
        gen.addTest(randomTestWithoutSolution(500000, 10000));
    }
    gen.endGroup();



    gen.generate();
}