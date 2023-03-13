#include<bits/stdc++.h>
#include "generator.h"
#include "medTest.h"
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
using namespace std;
int a, b;
 
int R(int a, int b) {
    return Generator::random() % (b - a + 1) + a;
}

Test exampleTest() {
    Test test;
    test.addLine(5, 5);
    test.addLine(1, 2, 2, 1);
    test.addLine(1, 3, 4, 4);
    test.addLine(2, 4, 3, 1);
    test.addLine(2, 5, 5, 2);
    return test;
}
  
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
  
  
  
Test randomWeights(int n, int x, int minS, int maxWeight) {
    Test test;
    
    VPII v = generatetree(n, x, minS);
    
    test.addLine(n);
    
    for (int i=0; i<v.size(); i++) {
        int tmin = R(1, maxWeight);
        int t = R(a, maxWeight);
        
        test.addLine(v[i].f, v[i].s, t, tmin);
    }
    
    return test;
}


  
  
  
  
int main() {
    Generator gen("kam");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

//     //1
//     gen.beginGroup();
//     {
//         Generator::setSeed(1982755341);
// 
//     gen.endGroup();
// 
//     //2
//     gen.beginGroup();
//     {
//         Generator::setSeed(2942755341);
// 
//     }
//     gen.endGroup();
// 
//     // 3
//     gen.beginGroup();
//     {
//         Generator::setSeed(1982734123);
// 
//     }
//     gen.endGroup();
//     
//     //4
//     gen.beginGroup();
//     {
//         Generator::setSeed(3382755341);
// 
//     }
//     gen.endGroup();
// 
//     //5 
//     gen.beginGroup();
//     {
//         Generator::setSeed(29487547);
// 
//     }
//     gen.endGroup();
// 
//     //6
//     gen.beginGroup();
//     {
//         Generator::setSeed(94933833);
// 
//     }
//     gen.endGroup();
// 
//     //7
//     gen.beginGroup();
//     {
//         Generator::setSeed(303022939);
// 
//     }
//     gen.endGroup();


    gen.generate();
}