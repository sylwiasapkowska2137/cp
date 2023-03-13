#include "generator.h"

#include <memory>
#include <iostream>
using namespace std;

long long MAX_Z = 100 * 1000;
long long MAX_N = 1000000000LL * 1000000000LL;
long long MAX_K = 1000000000LL * 1000000000LL;

long long R(long long a, long long b) {
    return Generator::random64() % (b - a + 1LL) + a;
}

Test exampleTest() {
  Test test;
  test.addLine(2);
  test.addLine(6, 3);
  test.addLine(4, 4);
  return test;
}
  
Test randomTest(int z, long long minN, long long maxN, long long minK, long long maxK, int onlyNegativeOverflow) {
    Test test;
    
    assert(z <= MAX_Z);
    test.addLine(z);
    
    if (minK == 1) {
        test.addLine(minN, 1);
        test.addLine(maxN, 1);
        z -= 2;
    }
    
    for (int i=0; i<z; i++) {
        long long n, x, k;
        
        n = R(minN, maxN);
        x = R(0, 4);
    
        if (x) {
            k = R(minK, maxK/100LL);
        }
        else {
            k = R(minK, maxK);
        }
        
        if (onlyNegativeOverflow) {
            bool cool = false;

            while (!cool) {
                cool = true;
                
                for (long long j=k; j<=n; j*=k) {
                    long long nextI = j*k;
                    long long checkI = nextI / k;
                    
                    if (checkI != j && j >=0 && nextI >= 0) {
                        cool = false;
                        
                        n = R(minN, maxN);
                        x = R(0, 4);
                    
                        if (x) {
                            k = R(minK, maxK/100LL);
                        }
                        else {
                            k = R(minK, maxK);
                        }
                        
                        break;
                    }
                }
            }
        }
       
        test.addLine(n, k);
    }
    
    return test;
}


int main() {
    Generator gen("kla");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    //1
    gen.beginGroup();
    {
        Generator::setSeed(1982755341);
        gen.addTest(randomTest(30, 1, 20, 1, 1000, 0));
    }
    gen.endGroup();

    //2
    gen.beginGroup();
    {
        Generator::setSeed(2942755341);
        gen.addTest(randomTest(100, 1, 1000, 2, 2000, 0));
    }
    gen.endGroup();

    //3
    gen.beginGroup();
    {
        Generator::setSeed(1982734123);
        gen.addTest(randomTest(100000, 100000, 1000000, 2, 1000, 0));
    }
    gen.endGroup();

    //4
    gen.beginGroup();
    {
        Generator::setSeed(3382755341);
        gen.addTest(randomTest(100000, 1000000000LL, 1000000000000LL, 2, 1000000000LL, 0));
    }
    gen.endGroup();

    // increasing number of test cases will cause problems
    //5
    gen.beginGroup();
    {
        Generator::setSeed(29487547);
        gen.addTest(randomTest(2000, 1000000LL, MAX_N, 1000000000LL, MAX_K, 1));
    }
    gen.endGroup();

    //6
    gen.beginGroup();
    {
        Generator::setSeed(94933833);
        gen.addTest(randomTest(100000, 1, MAX_N, 1000, 1000000000LL, 0));
    }
    gen.endGroup();

    //7
    gen.beginGroup();
    {
        Generator::setSeed(303022939);
        gen.addTest(randomTest(100000, 1, MAX_N, 1, MAX_K, 0));
    }
    gen.endGroup();
    
     //8
    gen.beginGroup();
    {
        Generator::setSeed(377705341);
        gen.addTest(randomTest(100000, 100000000LL, 1000000000000LL, 2, 10000000LL, 0));
    }
    gen.endGroup();


    gen.generate();
}