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
Test generateA(int,int);
Test generateB(int,int);
Test generateC(int,int);
Test exampleTest();
void increase(long long*, long long);

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
    Generator gen("far");
    
    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
  
    // ---- 1 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 11111111); gen.addTest(generateA(20, 50));
    Generator::setSeed(2 * 11111111); gen.addTest(generateA(20, 50));
    gen.endGroup();
    // ----------- //
    
    // ---- 2 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 20220222); gen.addTest(generateA(200, 400));
    Generator::setSeed(2 * 20220222); gen.addTest(generateA(200, 400));
    gen.endGroup();
    // ----------- //
    
    // ---- 3 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 33030303); gen.addTest(generateA(2500, 5000));
    Generator::setSeed(2 * 33030303); gen.addTest(generateA(2500, 5000));
    gen.endGroup();
    // ----------- //
    
    // ---- 4 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 40141144); gen.addTest(generateA(40000, 50000));
    Generator::setSeed(2 * 40141144); gen.addTest(generateA(40000, 50000));
    Generator::setSeed(5 * 40141144); gen.addTest(generateA(40000, 50000));
    gen.endGroup();
    // ----------- //
    
    // ---- 5 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 50101115); gen.addTest(generateA(100000, 100000));
    Generator::setSeed(2 * 50101115); gen.addTest(generateA(100000, 100000));
    Generator::setSeed(3 * 50101115); gen.addTest(generateC(100000, 100000));
    gen.endGroup();
    // ----------- //
    
    // ---- 6 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 60101116); gen.addTest(generateA(1000000, 1000000));
    Generator::setSeed(2 * 60101116); gen.addTest(generateA(1000000, 1000000));
    Generator::setSeed(3 * 60101116); gen.addTest(generateC(1000000, 1000000));
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
    int r = randomPrime(100);
    if(*x * r > range) 
    {
      break;
    }
    else
    {
      *x *= r;
    }
    bound = range / *x;
  }
}

void change(vector <long long>* V, int a, int b, int val, int rangeA)
{
  for(int i = a; i <= b; i++)
  {
    if((*V)[i] * val <= rangeA)
    {
      (*V)[i] *= val;
    }
  }
}

Test generateA(int n, int rangeA)
{
  vector <long long> Nums(n, 1);
  
  for(int i = 0; i < n; i++)
  {
    int start = max(0, i - random(0, 10));
    int end = random(i, n - 1);
    int value = randomPrime(sqrt(rangeA));
    change(&Nums, start, end, value, rangeA);
    i = end;
  }
  for(int i = 0; i < n; i++)
  {
    increase(&Nums[i], rangeA);
    if(Nums[i] > rangeA) assert(false);
  }
  Test test;                                                  
  test.addLine(n);
  test.addLine(Nums);
  return test;
}

Test generateC(int n, int rangeA)
{
  vector <long long> Nums (n, 1);
  int big1 = Primes[Last[rangeA]];
  int big2 = Primes[Last[big1 - 1]];
  int big3 = Primes[Last[big2 - 1]];
  for(int i = 0; i < n; i++)
  {
    int end = random(i, n - 1);
    int r = random(0, 2);
    int value = (r == 1) ? big1 : (r == 2) ? big2 : big3;
    change(&Nums, i, end, value, rangeA);
    i = end;
    if(Nums[i] > rangeA) assert(false);
  }
  Test test;                                                  
  test.addLine(n);
  test.addLine(Nums);
  return test;
}

Test exampleTest() 
{
    Test test;
    test.addLine(5);
    test.addLine(7, 5, 6, 10, 5);
    return test;
}

