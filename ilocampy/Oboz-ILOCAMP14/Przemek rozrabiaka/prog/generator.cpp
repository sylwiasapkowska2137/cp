#include "generator.h"

#include <memory>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <sys/time.h>
#include <cstdlib>

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

int random(int, int);
long long randomLL(long long, long long);
Test generateTest(int, long long);
Test exampleTest();

int main() 
{
    Generator gen("pro");
    
    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
  
    // ---- 1 ---- //
    gen.beginGroup();
    Generator::setSeed(32432532); gen.addTest(generateTest(10, 50));
    gen.endGroup();
    // ----------- //
    
    // ---- 2 ---- //
    gen.beginGroup();
    Generator::setSeed(98634025); gen.addTest(generateTest(10, 10000000000LL));
    gen.endGroup();
    // ----------- //
    
    // ---- 3 ---- //
    gen.beginGroup();
    Generator::setSeed(12304134); gen.addTest(generateTest(100, 500));
    gen.endGroup();
    // ----------- //
    
    // ---- 4 ---- //
    gen.beginGroup();
    Generator::setSeed(90357230); gen.addTest(generateTest(100, 1000000000000LL));
    gen.endGroup();
    // ----------- //
    
    // ---- 5 ---- //
    gen.beginGroup();
    Generator::setSeed(32543259); gen.addTest(generateTest(1000, 5000));
    gen.endGroup();
    // ----------- //
    
    // ---- 6 ---- //
    gen.beginGroup();
    Generator::setSeed(78934502); gen.addTest(generateTest(1000, 1000000000000000LL));
    gen.endGroup();
    // ----------- //
    
    // ---- 7 ---- //
    gen.beginGroup();
    Generator::setSeed(54204124); gen.addTest(generateTest(10000, 1000000000));
    gen.endGroup();
    // ----------- //
    
    // ---- 8 ---- //
    gen.beginGroup();
    Generator::setSeed(934759142); gen.addTest(generateTest(10000, 1000000000000000000LL));
    gen.endGroup();
    // ----------- //
    
    gen.generate();
}


int random(int a, int b) 
{
  return Generator::random() % (b - a + 1) + a;
}

long long randomLL(long long a, long long b) 
{
  return Generator::random64() % (b - a + 1) + a;
}

Test generateTest(int n, long long k)
{
  Test test;
  test.addLine(n);
  for(int i = 1; i <= n; i++)
  {
    long long val = randomLL(1, k / 4) * 4;
    if(random(1, 3) == 1)
    {
      test.addLine(val);
    }
    else
    {
      test.addLine(val + random(1, 3));
    }
  }
  return test;
}

Test exampleTest() 
{
    Test test;
    test.addLine(2);
    test.addLine(2);
    test.addLine(3);
    return test;
}