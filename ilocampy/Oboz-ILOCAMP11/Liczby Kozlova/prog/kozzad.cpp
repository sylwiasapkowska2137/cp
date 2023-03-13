#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define ALL(x) (x).begin(),(x).end()
typedef long long LL;
const int INF = 1000000000;
typedef vector<int> VI;
bool prime(LL x) 
	{
  if(x<2) return false;
  for(int i=2;i*i<=x;++i) if(x%i==0) return false;
  return true;
	}
 
vector<LL> primes;
LL xx;
LL tot;
 
void rek(LL ilo, int p, LL sn) 
	{
  tot += xx/ilo * sn;
  while(p<primes.size()) 
  	{
    LL ilo2 = ilo * primes[p] * primes[p];
    if(ilo2>xx) break;
    ++p;
    rek(ilo2, p, -sn);
   }
}
 
LL f(LL x) 
	{
  xx=x;
  tot = 0;
  rek(1, 0, +1);
  return tot;
	}
 
int main()
	{
	int n;
	cin>>n;
  for(LL x=2;x*x<=2000000000;++x) if(prime(x)) primes.push_back(x);
  LL a=0, b=2000000000;
  while(b-a>1) 
  	{
    LL c = (a+b)/2;
    if(f(c)>=n) b = c; 
    else a = c;
    }
  cout<<b<<endl;
  }
