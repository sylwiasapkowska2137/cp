#include "generator.h"

#include <memory>

#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define VVI vector< VI >
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

template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

int R(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

Test example() {
    Test test;
    test.addLine(5, 1);
    test.addLine(1, 2, 1);
    test.addLine(2, 3, 7);
    test.addLine(4, 2, 2);
    test.addLine(3, 5, 4);
    return test;
}

Test exampleTest() {
    Test test;
    test.addLine(6, 2);
    test.addLine(1, 2, 4);
    test.addLine(1, 3, 3);
    test.addLine(3, 4, 8);
    test.addLine(3, 5, 5);
    test.addLine(1, 6, 6);
    return test;
}
  
int a, b;  
  
VPII generatetree1(int n)
{
    VPII ret;
    FOR(i,2,n)
    {
        ret.PB(MP(i,R(1,i-1)));
    }
    return ret;
}

VPII generatetree2(int n)
{
    VPII ret;
    FOR(i,2,n)
    {
    if(R(1,100)>=3)ret.PB(MP(i,R(max(1,i-7),i-1)));
    else ret.PB(MP(i,R(1,i-1)));
    }
    return ret;
}

struct FI
{
    int *t;
    FI(int n)
        {
        n++;
        t=new int[n+1];
        FOR(i,1,n)t[i]=i;
        }
    int find(int a)
        {
        return a==t[a]?a:t[a]=find(t[a]);
        }
    void unio(int a,int b)
        {
        t[find(a)]=find(b);
        }
};
  
VPII generatetree3(int n)
{
    FI X(n);
    VPII ret;
    while(ret.size()!=n-1)
    {
        a=R(1,n);
        b=R(1,n);
        if(X.find(a)!=X.find(b))
        {
                ret.PB(MP(a,b));
                X.unio(a,b);
        }
    }
    return ret;
}

VPII generatetree4(int n,int T=0)//duże stopnie
{
    if(T==0)T=R(3,10);
    VPII ret;
    FOR(i,2,n)
        {
            if(R(1,300)>=5)ret.PB(MP(i,R(1,min(i-1,T))));
            else ret.PB(MP(i,R(1,i-1)));
        }
    return ret;  
}

VPII generatetree5(int n,int T=0)//bardzo duże stopnie
{
    if(T==0)T=R(1,4);
    VPII ret;
    FOR(i,2,n)
    {
        if(R(1,300)>=2)ret.PB(MP(i,R(1,min(i-1,T))));
        else ret.PB(MP(i,R(1,i-1)));
    }
    return ret;  
}
  
VPII generatetree6(int n)
{
    VPII ret;
    FOR(i,2,n)
    {
        if(R(1,3000)>=2)ret.PB(MP(i,R(max(1,i-2),i-1)));
        else ret.PB(MP(i,R(1,i-1)));
    }
    return ret;
}

void permutuj(VPII &V)
  {
  int n=V.size()+1;
  int t[n+1];
  FOR(i,1,n)
    t[i]=i;
  random_shuffle(t+2,t+n+1);
  REP(i,V.size())
    {
        V[i].f=t[V[i].f];
        V[i].s=t[V[i].s];
        if(R(1,3)==1)swap(V[i].f,V[i].s);
    }
  random_shuffle(ALL(V));
  }
  
  
  

  

  
bool checktree(VPII V) {
    // {a
    int n=V.size()+1;
    FI X(n);
    REP(i,V.size())
    {
        a=V[i].f;
        b=V[i].s;
        if(a>n||b>n)return 0;
        if(a<1||b<1)return 0;
        if(X.find(a)==X.find(b))return 0;
        X.unio(a,b);
    }
    return 1;
}

const int MXN = 1e6+6;
VI V[MXN];
int odl[MXN];
void dfs(int x,int pp)
{
    for(auto it:V[x])
    {
        if(it == pp)continue;
        odl[it] = odl[x] + 1;
        dfs(it, x);
    }
}

int srednica(VPII X)
  {
  int n = X.size() + 1;
  FOR(i,1,n)
    {
    V[i].clear();
    odl[i]=0;
    }
  for(auto it:X)
    {
    V[it.f].PB(it.s);
    V[it.s].PB(it.f);
    }
  odl[1]=0;
  dfs(1, 0);
  int mx=0;
  FOR(i,1,n)
    {
    if(odl[mx] < odl[i])
      {
      mx = i;
      }
    }
  odl[mx]=0;
  dfs(mx, 0);
  int r = 0;
  FOR(i,1,n)
    {
    maxi(r, odl[i]);
    }
  return r;
  }

  
  
  
  
 VPII generatetree(int n,int x, int minS)
 {
    VPII V1;
        switch (x)
        {
        case 1:
        {
        V1=generatetree1(n);
        break;
        }
        case 2:
        {
        V1=generatetree2(n);
        break;
        }
        case 3:
        {
        V1=generatetree3(n);
        break;
        }
        case 4:
        {
        V1=generatetree4(n);
        break;
        }
        case 5:
        {
        V1=generatetree5(n);
        break;
        }
        case 6:
        {
        V1=generatetree6(n);
        
        while (srednica(V1) < minS)
            V1 = generatetree6(n);
        
        break;
        }
        }
    permutuj(V1);
    return V1;
  }
  
  
Test randomWeights(int n, int k, int x, int minS, int maxWeight) {
    Test test;
    
    assert(n <= 3000 && k <= n && maxWeight <= 1000000000);
    
    VPII v = generatetree(n, x, minS);
    
    test.addLine(n, k);
    
    for (int i=0; i<v.size(); i++) {
        int c = R(1, maxWeight);
        
        test.addLine(v[i].f, v[i].s, c);
    }
    
    return test;
}

Test randomWeightsLL(int n, int k, int x, int minS, int maxWeight) {
    Test test;
    
    assert(n <= 3000 && k <= n && maxWeight <= 1000000000);
    
    VPII v = generatetree(n, x, minS);
    
    test.addLine(n, k);
    
    for (int i=0; i<v.size(); i++) {
        int c = R(maxWeight-2, maxWeight);
        
        test.addLine(v[i].f, v[i].s, c);
    }
    
    return test;
}

Test corner1() {
    Test test;
    
    test.addLine(1, 1);
    
    return test;
}

Test corner2() {
    Test test;
    
    test.addLine(2, 1);
    test.addLine(1, 2, 5);
    
    return test;
}

Test corner3() {
    Test test;
    
    test.addLine(3, 1);
    test.addLine(1, 2, 3);
    test.addLine(1, 3, 4);
    
    return test;
}

Test corner4() {
    Test test;
    
    test.addLine(3, 2);
    test.addLine(1, 2, 4);
    test.addLine(1, 3, 1);
    
    return test;
}

Test corner5() {
    Test test;
    
    test.addLine(3, 2);
    test.addLine(1, 2, 4);
    test.addLine(1, 3, 1);
    
    return test;
}

Test corner6() {
    Test test;
    
    test.addLine(3, 3);
    test.addLine(1, 2, 7);
    test.addLine(1, 3, 11);
    
    return test;
}


int main() {
    Generator gen("dzi");

    gen.beginGroup();
    gen.addTest(example());
    gen.endGroup();

    // 1
    gen.beginGroup();
    {
        gen.addTest(corner1());
        gen.addTest(corner2());
        gen.addTest(corner3());
        gen.addTest(corner4());
        gen.addTest(corner5());
        gen.addTest(corner6());
        
        Generator::setSeed(101);
        gen.addTest(randomWeights(10, 1, 1, 0, 10));
        Generator::setSeed(102);
        gen.addTest(randomWeights(10, 3, 2, 0, 3));
        Generator::setSeed(103);
        gen.addTest(randomWeights(10, 4, 3, 0, 20));
        Generator::setSeed(104);
        gen.addTest(randomWeights(10, 10, 4, 0, 10));
    }
    gen.endGroup();

    // 2
    gen.beginGroup();
    {
        Generator::setSeed(201);
        gen.addTest(randomWeights(20, 1, 1, 0, 10));
        Generator::setSeed(202);
        gen.addTest(randomWeights(20, 3, 2, 0, 3));
        Generator::setSeed(203);
        gen.addTest(randomWeights(30, 14, 3, 0, 20));
        Generator::setSeed(204);
        gen.addTest(randomWeights(40, 17, 4, 0, 50));
        Generator::setSeed(204);
        gen.addTest(randomWeights(50, 21, 5, 0, 2));
    }
    gen.endGroup();

    // 3
    gen.beginGroup();
    {
        Generator::setSeed(301);
        gen.addTest(randomWeights(100, 10, 4, 0, 1000));
        Generator::setSeed(302);
        gen.addTest(randomWeights(99, 5, 5, 0, 1000));
        Generator::setSeed(303);
        gen.addTest(randomWeights(100, 33, 5, 0, 1000));
        Generator::setSeed(304);
        gen.addTest(randomWeights(200, 100, 6, 90, 1000));
        Generator::setSeed(304);
        gen.addTest(randomWeights(200, 47, 6, 50, 1000));
    }
    gen.endGroup();

    // 4
    gen.beginGroup();
    {
        Generator::setSeed(401);
        gen.addTest(randomWeights(1000, 40, 1, 0, 1000000));
        Generator::setSeed(402);
        gen.addTest(randomWeights(1000, 170, 4, 0, 1000000));
        Generator::setSeed(403);
        gen.addTest(randomWeights(1000, 22, 3, 0, 1000000));
        Generator::setSeed(404);
        gen.addTest(randomWeights(1000, 300, 6, 300, 1000000));
        Generator::setSeed(404);
        gen.addTest(randomWeights(1000, 979, 6, 170, 1000000));
    }
    gen.endGroup();

    // 5
    gen.beginGroup();
    {
        Generator::setSeed(501);
        gen.addTest(randomWeights(1000, 333, 2, 0, 1000000000));
        Generator::setSeed(502);
        gen.addTest(randomWeights(1000, 17, 4, 0, 1000000000));
        Generator::setSeed(503);
        gen.addTest(randomWeights(1000, 230, 5, 0, 1000000000));
        Generator::setSeed(504);
        gen.addTest(randomWeights(1000, 700, 5, 0, 1000000000));
        Generator::setSeed(504);
        gen.addTest(randomWeights(1000, 501, 5, 0, 1000000000));
    }
    gen.endGroup();

    // 6
    gen.beginGroup();
    {
        Generator::setSeed(601);
        gen.addTest(randomWeights(1000, 333, 6, 170, 1000000000));
        Generator::setSeed(602);
        gen.addTest(randomWeights(1000, 17, 6, 230, 1000000000));
        Generator::setSeed(603);
        gen.addTest(randomWeights(1000, 230, 6, 400, 1000000000));
        Generator::setSeed(604);
        gen.addTest(randomWeights(1000, 700, 6, 500, 1000000000));
        Generator::setSeed(604);
        gen.addTest(randomWeights(1000, 501, 6, 700, 1000000000));
    }
    gen.endGroup();

    // 7
    gen.beginGroup();
    {
        Generator::setSeed(701);
        gen.addTest(randomWeights(1000, 5, 4, 0, 1000000000));
        Generator::setSeed(702);
        gen.addTest(randomWeights(1000, 2, 3, 0, 1000000000));
        Generator::setSeed(703);
        gen.addTest(randomWeights(1000, 42, 5, 0, 1000000000));
        Generator::setSeed(704);
        gen.addTest(randomWeights(1000, 500, 5, 0, 1000000000));
        Generator::setSeed(704);
        gen.addTest(randomWeightsLL(1000, 1, 2, 0, 1000000000));
    }
    gen.endGroup();

    gen.generate();
}




