#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#include "generator.h"
using namespace std;

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

int R(int a, int b)
{
    return Generator::random() % (b - a + 1) + a;
}

Test randomTest(int n, char a, char b, int pa = 50)
{
    Test test;
    test.addLine(n);
    string s;
    REP(i, n)
        {
        if(R(1, 100) <= pa)
            s += a;
        else
            s += R(a+1, b);
        }
    test.addLine(s);
    return test;
}

int main() {
    Generator gen("slo");

    
    gen.beginGroup();//1
    {
		for (int i=1; i<=11; i++)
		    {
			gen.setSeed(10+i);
			gen.addTest(randomTest(R(1,10), 'a', 'b', 50));
		    }
    }
    gen.endGroup();
    
   
    
    gen.generate();
    return 0;
}
