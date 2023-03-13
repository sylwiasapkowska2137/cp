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

Test mTest(string s)
{
    Test test;
    test.addLine(s.size());
    test.addLine(s);
    return test;
}

int val[MXN];
Test random(int n, int k, int q)
{
    assert(n % k == 0);

    

    Test test;
    test.addLine(n, k, q);
    REP(i, n-1)
        {
        test.addLine(i+2, R(1, i+1));
        }
    VI V;
    FOR(i, 1, n)
        {
        V.PB(i%k+1);
        }
    random_shuffle(ALL(V));
    REP(i, V.size())val[i+1] = V[i];
    test.addLine(V);
    REP(i, q/2)
        {
        int a = R(1, n);
        int b = R(1, n);
        if(a == b)
            {
            test.addLine(a, R(1, k));
            }
        else
            test.addLine(a, val[b]);

        test.addLine(b, val[a]);
        
        swap(val[a], val[b]);
        }
    if(q % 2 == 1)
        {
        test.addLine(R(1, n), R(1, k));
        }
    return test;
}
/*
s <= 100: 20
s <= 1000: 20
s <= 10000: 20
s <= 70000: 20
s <= 100000: 20

*/
int main() {
    Generator gen("wst");

    
    gen.beginGroup();//1
    {
        gen.addTest(random(10, 2, 1000));
    }
    gen.endGroup();
    

    
   
    
    gen.generate();
    return 0;
}
