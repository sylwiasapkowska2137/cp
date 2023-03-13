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
int solve(vector<int>, vector<int>);
Test generateTest(int,bool,int,int);
Test exampleTest();

int main() 
{
    Generator gen("gwk");
    
    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();
  
    // ---- 1 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 11111111); gen.addTest(generateTest(10, true, 50, 30));
    Generator::setSeed(2 * 11111111); gen.addTest(generateTest(10, true, 50, 30));
    Generator::setSeed(3 * 11111111); gen.addTest(generateTest(10, false, 50, 30));
    gen.endGroup();
    // ----------- //
    
    // ---- 2 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 20220222); gen.addTest(generateTest(100, true, 500, 300));;
    Generator::setSeed(2 * 20220222); gen.addTest(generateTest(100, true, 500, 300));;
    Generator::setSeed(2 * 20220222); gen.addTest(generateTest(100, false, 500, 300));;
    gen.endGroup();
    // ----------- //
    
    // ---- 3 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 33030303); gen.addTest(generateTest(1000, true, 5000, 50000));
    Generator::setSeed(2 * 33030303); gen.addTest(generateTest(1000, true, 5000, 50000));
    Generator::setSeed(3 * 33030303); gen.addTest(generateTest(1000, false, 5000, 50000));
    gen.endGroup();
    // ----------- //
    
    // ---- 4 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 40141144); gen.addTest(generateTest(10000, true, 100000, 70000));
    Generator::setSeed(2 * 40141144); gen.addTest(generateTest(10000, true, 100000, 70000));
    Generator::setSeed(3 * 40141144); gen.addTest(generateTest(10000, false, 100000, 70000));
    gen.endGroup();
    // ----------- //
    
    // ---- 5 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 50101115); gen.addTest(generateTest(100000, true, 1000000, 10000000));
    Generator::setSeed(2 * 50101115); gen.addTest(generateTest(100000, true, 1000000, 10000000));
    Generator::setSeed(3 * 50101115); gen.addTest(generateTest(100000, false, 1000000, 10000000));
    gen.endGroup();
    // ----------- //
    
    // ---- 6 ---- //
    gen.beginGroup();
    Generator::setSeed(1 * 60601616); gen.addTest(generateTest(300000, true, 1000000, 10000000));
    Generator::setSeed(2 * 60601616); gen.addTest(generateTest(300000, true, 1000000, 10000000));
    Generator::setSeed(3 * 60601616); gen.addTest(generateTest(300000, false, 1000000, 10000000));
    gen.endGroup();
    // ----------- //
    
    gen.generate();
}


int random(int a, int b) 
{
  return Generator::random() % (b - a + 1) + a;
}

typedef long long LL;
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)(x).size()

long long DP[3][1000000];
  
int solve(vector <long long> X, vector <long long> H)
{
  int n = SZ(X);
  for(int j = 0; j < 3; j++)
  {
    for(int i = 0; i < 1000000; i++)
    {
      DP[j][i] = 0;
    }
  }
  X.insert(X.begin(), 0);
  H.insert(H.begin(), 0);
  X[0] = -1e14;
  X.PB(1e14);
  for(int i = 1; i <= n; i++)
  {
    // 0 - upada w lewo
    if(X[i] - H[i] > X[i - 1])
      DP[0][i] = max(DP[0][i - 1], DP[1][i - 1]) + 1;
    if(X[i] - H[i] > X[i - 1] + H[i - 1])
      DP[0][i] = max(DP[0][i], DP[2][i - 1] + 1);

    // 1 - w ogole nie upada
    DP[1][i] = max(DP[0][i - 1], max(DP[1][i - 1], DP[2][i - 1]));

    // 2 - upada w prawo
    if(X[i] + H[i] < X[i + 1])
      DP[2][i] = max(DP[0][i - 1], max(DP[1][i - 1], DP[2][i - 1])) + 1;
  }
  int res = max(DP[0][n], max(DP[1][n], DP[2][n]));
  return res;
}

Test generateTest(int n, bool valid, int length, int height)
{
  bool M[1000000];
  for(int i = 0; i < 1000000; i++)
  {
    M[i] = false;
  }
  vector <long long> V;
  vector <long long> X;
  vector <long long> H;
  V.clear();
  X.clear();
  H.clear();
  V.PB(-10000000);
  for(int i = 1; i <= n; i++)
  {
    int a = random(1, length);
    while(M[a] == true)
    {
      a = random(1, length);
    }
    M[a] = true;
    V.PB(a);
  }
  sort(ALL(V));
  V.PB(2500000000);
  for(int i = 1; i <= n; i++)
  {
    int a = V[i];
    int b;
    if(random(0,1))
      b = random(1, V[i + 1] - V[i]);
    else
      b = random(1, V[i] - V[i - 1]);
    X.PB(a);
    H.PB(b);
  }
  Test test;
  int res = solve(X, H);
  if(valid)
  {
    test.addLine(n, random(0, res - 1));
  }
  else
  {
    test.addLine(n, res);
  }
  for(int i = 0; i < SZ(X); i++)
  {
    test.addLine(X[i], H[i]);
  }
  return test;
}


Test exampleTest() 
{
    Test test;
    test.addLine(5, 3);
    test.addLine(2, 5);
    test.addLine(3, 3);
    test.addLine(9, 2);
    test.addLine(11, 15);
    test.addLine(14, 2);
    return test;
}