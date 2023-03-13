#include <bits/stdc++.h>
#include "generator.h"
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
using namespace std;

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

Test test(int n, int k, int d, int a, int b)
{
	Test test;
	test.addLine(n, k);
	FOR(i, 2, n)
	    {
	    test.addLine(i, R(max(1, i-d), i-1), R(a, b));
	    }
	return test;
}
Generator gen("mak");
void add(int n, int k, int d, int a, int b)
    {
    gen.beginGroup();
        {
		gen.addTest(test(n, k, d, a, b)); 
        }
    gen.endGroup();
    }


int main() {
	
	add(30000, 100, 1e9, 500, 800); 
	add(30000, 1000, 1e9, 1e5, 2e5);
	add(30000, 3000, 1e9, 1e5, 1.1e5); 
	add(30000, 3000, 3, 1e5, 1.1e5); 
	add(50000, 100, 1000, 500, 800); 
	add(50000, 1000, 1e9, 1e4, 2e4);
	add(50000, 4000, 100, 1e5, 1.1e5); 
	add(50000, 9000, 10, 1, 1e6); 
	add(100000, 300, 1e9, 500, 800); 
	add(100000, 4000, 100, 1e2, 1e6);
	add(100000, 9000, 1e9, 9e5, 1.e6); 
	add(100000, 20000, 3, 1e4, 2e4); 
    

    gen.generate();
    return 0;
}
