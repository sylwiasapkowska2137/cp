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

bool Sito[1000005];
int Last[1000005];

vector <int> Primes;

int random(int, int);
int randomPrime(int);
vector <long long> Factor(long long);
Test generateTest(int,int,int,long long, int);
Test exampleTest();
void increase(long long*, long long);
void primeTest(int,int,long long, Test*, bool);
void sameTest(int,int,long long, Test*, bool);

int main() 
{
    for(int i = 2; i <= 1000; i++)
    {
      if(!Sito[i])
      {
        for(int j = i * i; j <= 1000000; j += i)
        {
          Sito[j] = true;
        }
      }
    }
    for(int i = 2; i <= 1000000; i++)
    {
      if(!Sito[i])
      {
        Primes.push_back(i);
      }
      Last[i] = Primes.size() - 1;
    }
    Generator gen("nie");
    
    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
  
    // ---- 1 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 11111111); gen.addTest(generateTest(10, 100, 100, 100, 0));
    Generator::setSeed(2 * 11111111); gen.addTest(generateTest(10, 100, 100, 100, 3));
    Generator::setSeed(3 * 11111111); gen.addTest(generateTest(10, 100, 100, 100, 3));
    gen.endGroup();
    // ----------- //
    
    // ---- 2 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 20220222); gen.addTest(generateTest(10, 100, 1000, 1000, 3));;
    Generator::setSeed(2 * 20220222); gen.addTest(generateTest(10, 100, 1000, 1000, 3));;
    gen.endGroup();
    // ----------- //
    
    // ---- 3 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 33030303); gen.addTest(generateTest(10, 1000, 10000, 10000, 3));
    Generator::setSeed(2 * 33030303); gen.addTest(generateTest(10, 1000, 10000, 10000, 3));
    gen.endGroup();
    // ----------- //
    
    // ---- 4 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 40141144); gen.addTest(generateTest(10, 10000, 1000000, 1000000, 3));
    Generator::setSeed(2 * 40141144); gen.addTest(generateTest(5, 20000, 1000000, 1000000, 3));
    gen.endGroup();
    // ----------- //
    
    // ---- 5 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 50101115); gen.addTest(generateTest(10, 100000, 1000000, 10000000000LL, 1));
    Generator::setSeed(2 * 50101115); gen.addTest(generateTest(10, 100000, 1000000, 10000000000LL, 2));
    Generator::setSeed(3 * 50101115); gen.addTest(generateTest(10, 100000, 1000000, 10000000000LL, 3));
    gen.endGroup();
    // ----------- //
    
    // ---- 6 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 60101116); gen.addTest(generateTest(5, 200000, 1000000, 10000000000LL, 1));
    Generator::setSeed(2 * 60101116); gen.addTest(generateTest(5, 200000, 1000000, 10000000000LL, 2));
    Generator::setSeed(3 * 60101116); gen.addTest(generateTest(5, 200000, 1000000, 10000000000LL, 3));
    gen.endGroup();
    // ----------- //
    
    // ---- 7 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 77101111); gen.addTest(generateTest(1, 1000000, 1000000, 10000000000LL, 1));
    Generator::setSeed(2 * 77101111); gen.addTest(generateTest(1, 1000000, 1000000, 10000000000LL, 2));
    Generator::setSeed(3 * 77101111); gen.addTest(generateTest(1, 1000000, 1000000, 10000000000LL, 3));
    gen.endGroup();
    // ----------- //
    
    gen.generate();
}


int random(int a, int b) 
{
  return Generator::random() % (b - a + 1) + a;
}

int randomPrime(int a) 
{
  return Primes[random(0, Last[a])];
}

vector <long long> Factor(long long x)
{
  vector <long long> V;
  V.clear();
  for(int i = 0; i < Primes.size(); i++)
  {
    while(x % Primes[i] == 0)
    {
      x /= Primes[i];
      V.push_back(Primes[i]);
    }
  }
  if(x != 1) V.push_back(x);
  return V;
}

void increase(long long* x, long long range)
{
  long long bound = range / *x;
  while(bound > 1)
  {
    *x *= randomPrime(bound);
    bound = range / *x;
  }
}

void primeTest(int n, int rangeA, long long rangeK, Test* test, bool zero)
{
  long long k = random(2, rangeK);
  vector <long long> Div = Factor(k);
  vector <long long> Nums (n, 1);
  
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; j <= 20; j++)
    {
      int ind = random(0, Div.size() - 1);
      if(Nums[i] * Div[ind] <= rangeA)
      {
        Nums[i] *= Div[ind];
      }
    }
    increase(&Nums[i], rangeA);
  }
  if(zero) Nums[random(0, n - 1)] = 0;
                                                   
  test->addLine(n, k);
  test->addLine(Nums);
}


void sameTest(int n, int rangeA, long long rangeK, Test* test, bool zero)
{
  long long k = random(2, 100);
  vector <long long> Nums (n, 1);
  
  for(int i = 0; i < n; i++)
  {
    while(Nums[i] * k <= rangeA)
    {
      Nums[i] *= k;
    }
    increase(&Nums[i], rangeA);
  }
  if(zero) Nums[random(0, n - 1)] = 0;
  
  test->addLine(n, k);
  test->addLine(Nums);
}

Test generateTest(int tests, int n, int rangeA, long long rangeK, int casse)
{
  Test test;
  test.addLine(tests);
  for(int i = 1; i <= tests; i++)
  {
    switch(casse)
    {
      case 0:
        if(random(0, 1)) primeTest(n, rangeA, rangeK, &test, 1);
        else sameTest(n, rangeA, rangeK, &test, 1);
        if(random(0, 1)) casse = 3;
        break;
      case 1: primeTest(n, rangeA, rangeK, &test, 0); break;
      case 2: sameTest(n, rangeA, rangeK, &test, 0); break;
      case 3:
        if(random(0, 1)) primeTest(n, rangeA, rangeK, &test, 0);
        else sameTest(n, rangeA, rangeK, &test, 0);                 
        break;
    }
  }
  return test;
}

Test exampleTest() 
{
    Test test;
    test.addLine(2);
    test.addLine(3, 2);
    test.addLine(2, 3, 4);
    test.addLine(3, 3);
    test.addLine(7, 12, 15);
    return test;
}

