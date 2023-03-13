#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sys/time.h>

#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define QI queue <int>
#define VI vector <int>
#define PII pair <int,int>
#define SZ(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define SYNC ios_base::sync_with_stdio(0)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

using namespace std;

map <int,bool> M;

vector <LL> V;

int main()
{
	timeval czas;
	gettimeofday(&czas, 0);
	srand(czas.tv_sec*1000+czas.tv_usec/1000);
	int n, x, h;
	scanf("%d %d %d %d", &n, &x, &h);
	int k = 1 + (LL)((LL)rand() * 100000 + rand()) % n;
	cout << n << " " << k << "\n";
  for(int i = 1; i <= n; i++)
  {
    int a = 1 + (LL)((LL)rand() * 100000 + rand()) % x;
    while(M[a] == true)
    {
      a = 1 + (LL)((LL)rand() * 100000 + rand()) % x;
    }
    M[a] = true;
    V.PB(a);
  }
  sort(ALL(V));
  V.PB(2500000000);
  for(int i = 0; i < n; i++)
  {
    int a = V[i];
    int b;
    if(rand()%2)
      b = 1 + (LL)((LL)rand() * 100000 + rand()) % (V[i + 1] - V[i]);
    else
      b = rand() % 100  + (LL)((LL)rand() * 100000 + rand()) % (V[i] - V[i - 1]);
    cout << a << " " << b << endl;
  }
}
