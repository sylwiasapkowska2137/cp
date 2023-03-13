#include "generator.h"

#include <memory>
#include <assert.h>
using namespace std;

long long M = 1000005;
long long MAX_V = 1000000000;

long long R(long long a, long long b) {
    return Generator::random64() % (b - a + 1LL) + a;
}

Test exampleTest() {
  Test test;
  test.addLine(4, 3);
  test.addLine(10, 9, 11, 6);
  return test;
}
  
Test randomTest(long long n, long long k, long long minV, long long maxV) {
    Test test;
    
    assert(k <= n);
    
    test.addLine(n, k);
    
    vector <long long> V;
    long long a[M];
    
    for (int i=1; i<=n; i++) {
        a[i] = R(minV, maxV);
        if (n == 10 && k == 8 && minV == 5 && maxV == 10) 
            cout << a[i] << " ";
    }
    cout << endl;
    long long sum = 0;
    
    for (int i=1; i<=k; i++)
        sum += a[i];
    
    assert(-MAX_V <= sum && sum <= MAX_V);
    V.push_back(sum);
    
    for (int i=k+1; i<=n; i++) {
        sum -= a[i-k];
        sum += a[i];
        assert(-MAX_V <= sum && sum <= MAX_V);
        V.push_back(sum);
    }
    for (int i=1; i<k; i++) {
        sum += a[i];
        sum -= a[n + (i-k)];
        assert(-MAX_V <= sum && sum <= MAX_V);
        V.push_back(sum);
    }
    
    test.addLine(V);

    return test;
}

Test cycleTest(long long n, long long k, long long minV, long long maxV, long long cycleLength) {
    Test test;
    
    assert(k <= n && cycleLength <= n);
    
    test.addLine(n, k);
    
    vector <long long> V;
    long long a[M];
    
    for (int i=1; i<=cycleLength; i++) 
        a[i] = R(minV, maxV);
    
    for (int i=cycleLength+1; i<=n; i++)
        a[i] = a[i-cycleLength];
    
    
    long long sum = 0;
    
    for (int i=1; i<=k; i++)
        sum += a[i];
    
    assert(-MAX_V <= sum && sum <= MAX_V);
    V.push_back(sum);
    
    for (int i=k+1; i<=n; i++) {
        sum -= a[i-k];
        sum += a[i];
        assert(-MAX_V <= sum && sum <= MAX_V);
        V.push_back(sum);
    }
    for (int i=1; i<k; i++) {
        sum += a[i];
        sum -= a[n + (i-k)];
        assert(-MAX_V <= sum && sum <= MAX_V);
        V.push_back(sum);
    }
    
    test.addLine(V);

    return test;
}


int main() {
    Generator gen("wla");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    //1
    gen.beginGroup();
    {
        Generator::setSeed(1982755341);
        gen.addTest(randomTest(10, 5, 1, 10));
        gen.addTest(randomTest(10, 2, 1, 10));
        gen.addTest(randomTest(10, 3, 1, 10));
        gen.addTest(randomTest(10, 8, 5, 10));
        gen.addTest(randomTest(10, 9, 5, 10));
        gen.addTest(randomTest(10, 7, 1, 1));
        gen.addTest(randomTest(10, 6, 0, 0));
        gen.addTest(randomTest(10, 10, 1, 10));
        gen.addTest(randomTest(9, 4, 1, 10));
    }
    gen.endGroup();

    //2
    gen.beginGroup();
    {
        Generator::setSeed(2942755341);
        gen.addTest(randomTest(10, 3, 0, 1));
        gen.addTest(randomTest(10, 7, -2, 2));
        gen.addTest(randomTest(100, 4, -100, -10));
        gen.addTest(randomTest(100, 33, -10, 100));
        gen.addTest(randomTest(99, 51, 0, 1000));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        Generator::setSeed(1982734123);
        gen.addTest(randomTest(1, 1, 1000000000, 1000000000));
        gen.addTest(randomTest(1000, 7, -1000, 1000));
        gen.addTest(cycleTest(999, 257, -10000, 10000, 31));
        gen.addTest(randomTest(997, 133, 10000, 1000000));
        gen.addTest(randomTest(1000, 789, -1000000, -10000));
    }
    gen.endGroup();

    
    
    //4 only n % k != 0
    gen.beginGroup();
    {
        Generator::setSeed(3382755341);
        gen.addTest(randomTest(1, 1, 1000000000, 1000000000));
        gen.addTest(randomTest(100321, 7, -1000, 1000));
        gen.addTest(cycleTest(999678, 257, -10000, 10000, 11));
        gen.addTest(randomTest(997999, 133, -10, 10));
        gen.addTest(randomTest(1000000, 789, -1000000, -10000));
    }
    gen.endGroup();

    //5 only n % k == 0
    gen.beginGroup();
    {
        Generator::setSeed(29487547);
        gen.addTest(randomTest(1000000, 1000, -1000, 1000));
        gen.addTest(randomTest(999008, 8, -1000, 1000));
        gen.addTest(randomTest(997888, 4, 0, 1));
        gen.addTest(randomTest(1000000, 100000, -2, 2));
        gen.addTest(cycleTest(1000000, 100000, -2, 2, 100));
        gen.addTest(cycleTest(999000, 50, -1000, 1000, 50));
    }
    gen.endGroup();

    //6
    gen.beginGroup();
    {
        Generator::setSeed(94933833);
        gen.addTest(randomTest(555555, 3, -1000, 10000));
        gen.addTest(randomTest(999008, 1, -1000, 1000));
        gen.addTest(randomTest(997888, 2, 0, 1));
        gen.addTest(randomTest(1000000, 10, -2, 2));
        gen.addTest(cycleTest(999000, 500, -1000, 1000, 500));
    }
    gen.endGroup();

    //7
    gen.beginGroup();
    {
        Generator::setSeed(303022939);
        gen.addTest(cycleTest(1000000, 500000, 1, 1000, 4));
        gen.addTest(cycleTest(123123, 120120, -1000, 1000, 333));
        gen.addTest(cycleTest(500000, 125, -1000, 1000, 500));
        gen.addTest(cycleTest(1000000, 20000, -1000, 1000, 5000));
        gen.addTest(cycleTest(876123, 997, -1000, 1000, 13));
        gen.addTest(cycleTest(790000, 4, 0, 1000, 64));
    }
    gen.endGroup();


    gen.generate();
}