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

int random(int, int);;
Test generateA(int);;
Test generateB(int);
Test generateC(int);
Test exampleTest();

int main() 
{
    Generator gen("prz");
    
    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
  
    // ---- 1 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 11111111); gen.addTest(generateA(10));
    Generator::setSeed(2 * 11111111); gen.addTest(generateB(10));
    Generator::setSeed(101 * 11111111); gen.addTest(generateB(10));
    gen.endGroup();
    // ----------- //
    
    // ---- 2 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 20220222); gen.addTest(generateA(100));;
    Generator::setSeed(2 * 20220222); gen.addTest(generateB(100));;
    Generator::setSeed(2 * 20220222); gen.addTest(generateB(100));;
    gen.endGroup();
    // ----------- //
    
    // ---- 3 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 33030303); gen.addTest(generateA(1000));
    Generator::setSeed(2 * 33030303); gen.addTest(generateB(1000));
    Generator::setSeed(3 * 33030303); gen.addTest(generateB(1000));
    gen.endGroup();
    // ----------- //
    
    // ---- 4 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 40141144); gen.addTest(generateA(10000));
    Generator::setSeed(2 * 40141144); gen.addTest(generateB(10000));
    Generator::setSeed(3 * 40141144); gen.addTest(generateB(10000));
    gen.endGroup();
    // ----------- //
    
    // ---- 5 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 50101115); gen.addTest(generateB(100000));
    Generator::setSeed(2 * 50101115); gen.addTest(generateB(100000));
    Generator::setSeed(3 * 50101115); gen.addTest(generateB(100000));
    Generator::setSeed(4 * 50101115); gen.addTest(generateB(100000));
    gen.endGroup();
    // ----------- //
    
    // ---- 6 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 60601616); gen.addTest(generateB(1000000));
    Generator::setSeed(2 * 60601616); gen.addTest(generateB(1000000));
    Generator::setSeed(3 * 60601616); gen.addTest(generateB(1000000));
    Generator::setSeed(4 * 60601616); gen.addTest(generateB(1000000));
    gen.endGroup();
    // ----------- //
    
    gen.generate();
}


int random(int a, int b) 
{
  return Generator::random() % (b - a + 1) + a;
}

vector <int> generateVector(int n)
{
  vector <int> V(n);
  iota(V.begin(), V.end(), 1);
  return V;
}

void shuffle(int a, int b, vector <int>* V)
{
  swap(V->at(a), V->at(b));
  if(a + 1 < b - 1)
  {
    random_shuffle(V->begin() + a + 1, V->begin() + b - 1); 
  }
}

Test generateA(int n)
{
  Test test;
  test.addLine(n);
  vector <int> V = generateVector(n);
  reverse(V.begin(), V.end() - min(random(0, 5), n - 1));
  test.addLine(V);
  return test;
}

Test generateB(int n)
{
  Test test;
  test.addLine(n);
  vector <int> V = generateVector(n);
  n -= random(1, 4);
  int start = random(1, 3);
  int end = random(start, n - 1);
  shuffle(end, n - 1, &V);
  int left = end - start;
  for(int i = start; i < end; i++)
  {
    if(left >= 2)
    {
      int len = random(1, left / 2);
      left -= 2 * len;
      shuffle(i, i + len, &V);
      i = random(i + len, max(i + len, end - 1));
       left = end - i;
    }
  }
  test.addLine(V);
  return test;
}


Test exampleTest() 
{
    Test test;
    test.addLine(5);
    test.addLine(1, 3, 2, 5, 4);
    return test;
}

