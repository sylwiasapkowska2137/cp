#include "generator.h"

#include <memory>
#include <set>
#include <utility>
#include <vector>


template <class F, class S>
std::ostream &operator<<(std::ostream &os, const std::pair<F, S> &pair) {
    os << pair.first << " " << pair.second;
    return os;
}

using graph_t = std::vector<std::pair<int, int>>;
using namespace std;

#define MP make_pair
#define ST first
#define ND second
#define PB push_back
#define PII pair<int,int>
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)(x).size()

const int MINN = 2;
const int MAXN = 100 * 100;
const int MAXM = 100 * 1000;
const int MAXK = 5;

Test exampleTest();

bool Solve(int);
Test levelTest(int,int);

int main() 
{
    Generator gen("grb");

    gen.beginGroup();
    gen.addTest(exampleTest());
    gen.endGroup();

    //1
    gen.beginGroup();
    {
        Generator::setSeed(1111111);
        gen.addTest(levelTest(10, 2));
        Generator::setSeed(1112111);
        gen.addTest(levelTest(10, 3));
        Generator::setSeed(1113111);
        gen.addTest(levelTest(10, 4));
        Generator::setSeed(1114111);
        gen.addTest(levelTest(10, 5));
    }
    gen.endGroup();

    //2
    gen.beginGroup();
    {
        Generator::setSeed(2321232);
        gen.addTest(levelTest(100, 2));
        Generator::setSeed(2322232);
        gen.addTest(levelTest(100, 3));
        Generator::setSeed(2323232);
        gen.addTest(levelTest(100, 4));
        Generator::setSeed(2324232);
        gen.addTest(levelTest(100, 5));
    }
    gen.endGroup();
    //3
    gen.beginGroup();
    {
        Generator::setSeed(3521253);
        gen.addTest(levelTest(1000, 2));
        Generator::setSeed(3522253);
        gen.addTest(levelTest(1000, 3));
        Generator::setSeed(3523253);
        gen.addTest(levelTest(1000, 4));
        Generator::setSeed(3524253);
        gen.addTest(levelTest(1000, 5));
        
    }
    gen.endGroup();

    //4
    gen.beginGroup();
    {
        Generator::setSeed(4971794);
        gen.addTest(levelTest(10000, 2));
        Generator::setSeed(4972794);
        gen.addTest(levelTest(10000, 3));
        Generator::setSeed(4973794);
        gen.addTest(levelTest(10000, 4));
        Generator::setSeed(4974794);
        gen.addTest(levelTest(10000, 5));
    }
    gen.endGroup();

    
    gen.generate();
}

using namespace std;

Test exampleTest() 
{
    Test test;
    test.addLine(8, 7, 3);
    test.addLine(1, 2, 3, 1, 3, 2, 3, 1);
    test.addLine(3, 3, 2, 3, 2, 1, 1, 3);
    test.addLine(5, 3, 3);
    test.addLine(1, 6, 2);
    test.addLine(1, 2, 1);
    test.addLine(8, 4, 3);
    test.addLine(5, 7, 1);
    test.addLine(4, 5, 1);
    test.addLine(4, 6, 1);
    return test;
}

vector < pair<PII, int> > Edges;
vector < PII > Graph[MAXN + 7];
vector <int> Buttons[2];
set <PII> S;

Test levelTest(int n, int k)
{
    int level = 5;
    Edges.clear();
    Buttons[0].clear();
    Buttons[1].clear();
    for(int i = 0; i <= n; i++)
    {
        Graph[i].clear();
    }
    while(!S.empty())
    {
        S.erase(S.begin());
    }
    vector <int> Temp(n);
    iota(ALL(Temp), 1);
    random_shuffle(ALL(Temp));
    
    for(int i = 0; i < n; i++)
    {
        Buttons[0].PB(1 + Generator::random() % k);
        Buttons[1].PB(1 + Generator::random() % k);
        if(Buttons[0].back() == Buttons[1].back())
        {
            Buttons[1].back() = (Buttons[0].back() == 1) ? 2 : Buttons[1].back() - 1;
        }
    }
    for(int i = 1; i <= n - 1; i++)
    {
        int a = Temp.back();
        Temp.pop_back();
        Edges.PB(MP(MP(a, Temp.back()), 1 + Generator::random() % k));
        Graph[a].PB(MP(Temp.back(), Edges.back().ND));
        Graph[Temp.back()].PB(MP(a, Edges.back().ND));
        S.insert(MP(a, Temp.back()));
    }
    for(int i = 1; i <= n; i++)
    {
        while(SZ(Graph[i]) < level)
        {
            int a = i;
            int b = 1 + Generator::random() % n;
            while(a == b || S.count(MP(a,b)) != 0)
            {
                b = 1 + Generator::random() % n;
            }
            int c = 1 + Generator::random() % k;
            Graph[a].PB(MP(b,c));
            Graph[b].PB(MP(a,c));
            Edges.PB(MP(MP(a,b),c));
            S.insert(MP(a,b));
        }
    }
    random_shuffle(ALL(Edges));
    Test test;
    test.addLine( n, SZ(Edges), k );
    test.addLine(Buttons[0]);;
    test.addLine(Buttons[1]);
    for(int i = 0; i < SZ(Edges); i++)
    {
        test.addLine(Edges[i].ST.ST, Edges[i].ST.ND, Edges[i].ND);
    }
   
   return test;
}


bool Solve(int)
{
    return true;
}









