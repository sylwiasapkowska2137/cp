#include "generator.h"

#include <memory>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <sys/time.h>
#include <cstdlib>

typedef long long LL;

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

LL random(LL a, LL b) 
{
    return Generator::random64() % (b - a + 1) + a;
}

Test generateTest(int a, int b)
{
  Test test;
  test.addLine(random(a, b));
  return test;
}

Test exampleTest() 
{
    Test test;
    test.addLine(2);
    test.addLine(5, 7);
    test.addLine(3, 3);
    return test;
}

Test randomTest(int t, int a, int b)
{
  Test test;
  test.addLine(t);
  while(t--)
  {
    int n = random(a, b);
    int h = random(1, n);
    LL amm = (1LL << (h - 1));
    long long k = amm + random(0, amm - 1);
    test.addLine(n, k);
  }
  return test;
}

int main() 
{
    Generator gen("atk");
    
    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
    
    /* ---- 1 ---- */
    Generator::setSeed(35897024);
    gen.beginGroup();
    gen.addTest(randomTest(100, 1, 10));
    gen.endGroup();
    
    /* ---- 2 ---- */
    Generator::setSeed(73501234);
    gen.beginGroup();
    gen.addTest(randomTest(1000, 10, 20));
    gen.endGroup();
    
    /* ---- 3 ---- */
    Generator::setSeed(34234120);
    gen.beginGroup();
    gen.addTest(randomTest(10000, 20, 30));
    gen.endGroup();
    
    /* ---- 4 ---- */
    Generator::setSeed(45340211);
    gen.beginGroup();
    gen.addTest(randomTest(100000, 30, 40));
    gen.endGroup();
    
    /* ---- 5 ---- */
    Generator::setSeed(12130588);
    gen.beginGroup();
    gen.addTest(randomTest(1000000, 40, 50));
    gen.endGroup();
    
    /* ---- 6 ---- */
    Generator::setSeed(21459112);
    gen.beginGroup();
    gen.addTest(randomTest(1000000, 50, 60));
    gen.endGroup();
    
    gen.generate();
}


