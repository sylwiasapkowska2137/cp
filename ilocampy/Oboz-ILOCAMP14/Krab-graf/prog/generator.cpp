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

#define PII pair<int,int>
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define SZ(x) (int)(x).size()

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

int random(int, int);
vector<PII> generateCrabGraph(int,int);
vector<PII> renumerate(vector<PII>);
Test generateFromVector(vector<PII>);
Test generateValid(int,int);
Test generateValidStar(int,int,int);
Test generateInvalidCenter(int,int);
Test generateInvalidLength(int,int);
Test generateInvalidRoute(int,int);
Test generateInvalidStar(int,int);
Test generatePath(int);
Test exampleTest1();
Test exampleTest2();
Test exampleTest3();
Test generateCase1();
Test generateCase2();
Test generateCase3();
Test generateCase4();
Test generateCase5();

int main() 
{
    Generator gen("krg");
    
    gen.beginGroup();
    gen.addTest(exampleTest1());
    gen.addTest(exampleTest2());
    gen.addTest(exampleTest3());
    gen.endGroup();
  
    // ---- 1 ---- //
    gen.beginGroup();
    gen.addTest(generateCase1());
    gen.addTest(generateCase2());
    gen.addTest(generateCase3());
    gen.addTest(generateCase4());
    gen.addTest(generateCase5());
    Generator::setSeed(1 * 11111111); gen.addTest(generateValid(10, 3));
    Generator::setSeed(2 * 11111111); gen.addTest(generateValid(10, 2));
    gen.endGroup();
    
    gen.beginGroup();
    Generator::setSeed(1 * 11111112); gen.addTest(generateValid(20, 5));
    Generator::setSeed(11 * 11111112); gen.addTest(generateInvalidCenter(20, 5));
    gen.endGroup();
    
    gen.beginGroup();
    Generator::setSeed(1 * 11111113); gen.addTest(generateValid(20, 5));
    Generator::setSeed(2 * 11111113); gen.addTest(generateInvalidLength(20, 5));
    gen.endGroup();
    
    gen.beginGroup();
    Generator::setSeed(1 * 11111114); gen.addTest(generateValid(20, 5));
    Generator::setSeed(2 * 11111114); gen.addTest(generateInvalidRoute(10, 3));
    gen.endGroup();
    
    gen.beginGroup();
    Generator::setSeed(1 * 11111115); gen.addTest(generateValid(20, 5));
    Generator::setSeed(2 * 11111115); gen.addTest(generateInvalidStar(20, 5));
    Generator::setSeed(3 * 11111115); gen.addTest(generateValidStar(20, 5, 0));
    Generator::setSeed(4 * 11111115); gen.addTest(generateValidStar(20, 5, 1));
    gen.endGroup();
   
    gen.beginGroup();
    Generator::setSeed(1 * 42343411); gen.addTest(generateValid(1000, 100));
    Generator::setSeed(2 * 42343412); gen.addTest(generateInvalidCenter(1000, 100));
    Generator::setSeed(2 * 42343413); gen.addTest(generateInvalidLength(1000, 100));
    Generator::setSeed(2 * 42343414); gen.addTest(generateInvalidRoute(1000, 100));;
    Generator::setSeed(2 * 42343415); gen.addTest(generatePath(1000));
    Generator::setSeed(2 * 42343416); gen.addTest(generateInvalidStar(1000, 100));
    Generator::setSeed(2 * 42343417); gen.addTest(generateValidStar(1000, 100, 0));
    Generator::setSeed(2 * 42343418); gen.addTest(generateValidStar(1000, 100, 1));
    gen.endGroup();
    
    gen.beginGroup();
    Generator::setSeed(1 * 22222222); gen.addTest(generateValid(500000, 5000));
    Generator::setSeed(2 * 22222221); gen.addTest(generateInvalidCenter(500000, 5000));
    Generator::setSeed(2 * 22222222); gen.addTest(generateInvalidLength(500000, 5000));
    Generator::setSeed(2 * 22222223); gen.addTest(generateInvalidRoute(500000, 5000));
    Generator::setSeed(2 * 22222224); gen.addTest(generatePath(500000));
    Generator::setSeed(2 * 22222225); gen.addTest(generateInvalidStar(500000, 5000));
    Generator::setSeed(2 * 22222226); gen.addTest(generateValidStar(500000, 5000, 0));
    Generator::setSeed(2 * 22222227); gen.addTest(generateValidStar(500000, 5000, 1));
    gen.endGroup();
    
    
    // ----------- //
    
    gen.generate();
}


int random(int a, int b) 
{
  return Generator::random() % (b - a + 1) + a;
}

void renumerate(vector <PII>* V)
{
  int n = 0;
  for(int i = 0; i < V->size(); i++)
  {
    PII p = (*V)[i];
    n = max(n, max(p.first, p.second));
  }
  vector <int> Num(n, 0);
  iota(Num.begin(), Num.end(), 1);
  random_shuffle(Num.begin(), Num.end());
//   for(int i = 0; i < Num.size(); i++)
//   {
//     cout << Num[i] << " ";
//   }
//   cout << endl;
  for(int i = 0; i < V->size(); i++)
  {
    PII p = (*V)[i];
    PII p2 = MP(Num[p.first - 1], Num[p.second - 1]);
//     cout << p.first << " " << p.second << " || " << p2.first << " " << p2.second << endl;
    (*V)[i] = p2;
  }
}

vector <PII> generateCrabGraph(int n, int routes)
{
  int a = 1;
  int b = 2;
  vector <PII> V;
  V.PB(MP(a,b));
  int len = (n - 2) / routes;
  for(int i = 1; i <= routes; i++)
  {
    int start = (random(1, 2) == 1) ? a : b;
    for(int j = 1; j <= len; j++)
    {
      int c = V.size() + 2;
//       cout << start << " " << c << " " << V.size() << endl;
      V.PB(MP(start, c));
      start = c;
    }
  }
  return V;
}

Test generateFromVector(vector <pair<int,int> > V)
{
  Test test;
  test.addLine((int)V.size() + 1);
  renumerate(&V);
  random_shuffle(V.begin(), V.end());
  for(int i = 0; i < V.size(); i++)
  {
    test.addLine(V[i].first, V[i].second);
  }
  return test;
}

Test generatePath(int n)
{
  vector <PII> V;
  V.clear();
  for(int i = 1; i < n; i++)
  {
    V.PB(MP(i, i + 1));
  }
  return generateFromVector(V);
}

Test generateValid(int n, int routes)
{
  return generateFromVector(generateCrabGraph(n, routes));
}

Test generateInvalidCenter(int n, int routes)
{
  vector <PII> V = generateCrabGraph(n, routes);
  int a = V[0].first;
  int b = V[0].second;
  int c = a;
  int ile = random(1, 5);
  int d = 0;
  while(ile--)
  {
    d = V.size() + 2;
    V.PB(MP(c, d));
    c = d;
  }
  V.PB(MP(d, b));
  V.erase(V.begin());
  return generateFromVector(V);
}

Test generateInvalidStar(int n, int routes)
{
  vector <PII> V; V.clear();
  int gLen = (n - 1) / routes;
  for(int i = 1; i <= routes; i++)
  {
    int len = random(1, gLen);
    int a = 1;
    int b = SZ(V) + 2;
    V.PB(MP(a, b));
    for(int j = 1; j < len; j++)
    {
      a = b;
      b = SZ(V) + 2;
      V.PB(MP(a,b));
    }
  }
  return generateFromVector(V);
}

Test generateValidStar(int n, int routes, int erased)
{
  vector <PII> V; V.clear();
  int len = (n - 1) / routes;
  for(int i = 1; i <= routes - erased; i++)
  {
    int a = 1;
    int b = SZ(V) + 2;
    V.PB(MP(a,b));
    for(int j = 1; j < len; j++)
    {
      a = b;
      b = SZ(V) + 2;
      V.PB(MP(a,b));
    }
  }
  for(int i = 1; i <= erased; i++)
  {
    len -= random(1, 2);
    int a = 1;
    int b = SZ(V) + 2;
    
    for(int j = 1; j <= len; j++)
    {
      V.PB(MP(a,b));
      a = b;
      b = SZ(V) + 2;
    }
  }
  return generateFromVector(V);
}

Test generateInvalidLength(int n, int routes)
{
  vector <PII> V = generateCrabGraph(n, routes);
  vector <int> Lvl(V.size(), 0);
  for(int i = 0; i < V.size(); i++)
  {
    PII p = V[i];
    Lvl[p.first - 1]++;
    Lvl[p.second - 1]++;
  }
  for(int i = 0; i < V.size(); i++)
  {
    PII p = V[i];
    if(Lvl[p.first - 1] == 1 || Lvl[p.second - 1] == 1)
    {
      V.erase(V.begin() + i);
      if(random(1, 4) == 1) break;
    }
  }
  return generateFromVector(V);
}

Test generateInvalidRoute(int n, int routes)
{
  vector <PII> V = generateCrabGraph(n, routes);
  vector <int> Lvl (SZ(V) + 2, 0);
  for(int i = 0; i < SZ(V); i++)
  {
    PII p = V[i];
    Lvl[p.first]++;
    Lvl[p.second]++;
  }
  int m = SZ(V);
  for(int i = 0; i < m; i++)
  {
    PII p = V[i];
    if(Lvl[p.second] == 1) swap(p.first, p.second);
    if(Lvl[p.first] == 1)
    {
      int c = p.second;
      V.PB(MP(c, SZ(V) + 2));
      if(random(1, 10) == 1) break;
    }
  }
  return generateFromVector(V);
}

Test exampleTest1() 
{
    Test test;
    test.addLine(9);
    test.addLine(7, 2);
    test.addLine(1, 4);
    test.addLine(7, 9);
    test.addLine(2, 1);
    test.addLine(6, 2);
    test.addLine(1, 5);
    test.addLine(3, 1);
    test.addLine(8, 6);
    return test;
}

Test exampleTest2() 
{
    Test test;
    test.addLine(9);
    test.addLine(1, 3);
    test.addLine(3, 4);
    test.addLine(3, 7);
    test.addLine(1, 2);
    test.addLine(1, 5);
    test.addLine(5, 8);
    test.addLine(2, 6);
    test.addLine(9, 2);
    return test;
}

Test exampleTest3() 
{
    Test test;
    test.addLine(7);
    test.addLine(4, 5);
    test.addLine(5, 1);
    test.addLine(3, 4);
    test.addLine(1, 2);
    test.addLine(4, 7);
    test.addLine(4, 6);
    return test;
}

Test generateCase1()
{
  Test test;
  test.addLine(2);
  test.addLine(1, 2);
  return test;  
}

Test generateCase2()
{
  Test test;
  test.addLine(3);
  test.addLine(1, 2);
  test.addLine(1, 3);
  return test;  
}

Test generateCase3()
{
  Test test;
  test.addLine(3);
  test.addLine(1, 2);
  test.addLine(2, 3);
  return test;  
}

Test generateCase4()
{
  Test test;
  test.addLine(4);
  test.addLine(2, 3);
  test.addLine(3, 1);
  test.addLine(1, 4);
  return test;
}

Test generateCase5()
{
  Test test;
  test.addLine(8);
  test.addLine(1, 2);
  test.addLine(2, 3);
  test.addLine(2, 4);
  test.addLine(2, 5);
  test.addLine(4, 6);
  test.addLine(4, 7);
  test.addLine(5, 8);
  test.addLine(5, 9);
  return test;
}