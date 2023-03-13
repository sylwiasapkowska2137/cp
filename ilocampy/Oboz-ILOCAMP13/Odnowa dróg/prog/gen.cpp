//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <vector>
#include <set>
#include <ctime>
#include <deque>
#include <map>
#include <cassert>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
typedef long long LL;

// *** Rand ***
//Przemysław Jakub Kozłowski
//Działa tak samo jak zwykły rand() u mnie.
#include <deque>
#include <algorithm>
#define rand Rand
#define srand Srand
#define random_shuffle Random_shuffle
std::deque<int> Drand;
void Srand(int seed)
{
    Drand.resize(344);
    Drand[0] = seed;
    for(int i = 1;i < 31;i++)
    {
        Drand[i] = (16807LL*Drand[i-1])%2147483647;
        if(Drand[i] < 0) Drand[i] += 2147483647;
    }
    for(int i = 31;i < 34;i++) Drand[i] = Drand[i-31];
    for(int i = 34;i < 344;i++) Drand[i] = Drand[i-31]+Drand[i-3];
    for(int i = 1;i <= 344-31;i++) Drand.pop_front();
}
int Rand()
{
    Drand.push_back(Drand.front()+Drand[Drand.size()-3]);
    Drand.pop_front();
    return (((unsigned int)Drand.back()) >> 1);
}
template <class _RandomAccessIter>
inline void Random_shuffle(_RandomAccessIter __first, _RandomAccessIter __last) {
  if (__first == __last) return;
  for (_RandomAccessIter __i = __first + 1; __i != __last; ++__i)
    std::swap(*__i, *(__first + Rand()%((__i - __first) + 1)));
}
// *** Koniec Rand ***
int R(int a, int b) // b-a < 2^31
{return a+Rand()%(b-a+1);}
LL RL(LL a, LL b) // b-a < 2^62
{return a+((LL)Rand()*2147483647+Rand())%(b-a+1);}

vector<int> UniqueRandom(int n, int a, int b) // Zwraca vector n różnych liczb z przedziału [a,b]
{
    if(b-a+1 <= 2*n)
    {
        vector<int> ret;
        for(int i = a;i <= b;i++) ret.push_back(i);
        Random_shuffle(ret.begin(), ret.end());
        ret.resize(n);
        return ret;
    }
    else
    {
        vector<int> ret;
        set<int> S;
        while(ret.size() < n)
        {
            int x = R(a,b);
            if(!S.count(x))
            {
                ret.push_back(x);
                S.insert(x);
            }
        }
        return ret;
    }
}

void GeneratePrint(const char *filename, const char *test)
{
    FILE *file;
    if(filename[0] != 0)
    {
        file = fopen(filename, "r");
        if(file) {fclose(file);return;}
        file = fopen(filename, "w");
        fprintf(stderr, "Generowanie: %s\n", filename);
    }
    else file = stdout;

    fprintf(file, "%s", test);

    if(filename[0] != 0) fclose(file);
}

void GenerateRandom1(const char *filename, int ziarno, int n, int m) // n-1 <= m <= n*(n-1)/2
{
    FILE *file;
    if(filename[0] != 0)
    {
        file = fopen(filename, "r");
        if(file) {fclose(file);return;}
        file = fopen(filename, "w");
        fprintf(stderr, "Generowanie: %s\n", filename);
    }
    else file = stdout;
    Srand(ziarno);
    //Poczatek

    if(!(n-1 <= m && m <= n*(n-1)/2)) cerr << "BŁAD!" << endl;

    fprintf(file, "%d %d\n", n, m);

    vector<pair<int,int> > kra;
    char tab[n+7][n+7];

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            tab[i][j] = 0;

    for(int i = 2;i <= n;i++)
    {
        int r = R(1,i-1);
        tab[i][r] = tab[r][i] = 1;
        kra.push_back(MP(i, r));
    }

    vector<int> ur = UniqueRandom(m-(n-1), 1, n*(n-1)/2-(n-1));
    sort(ur.begin(), ur.end());
    reverse(ur.begin(), ur.end());

    for(int i = 1, num = 0;i <= n;i++)
        for(int j = i+1;j <= n;j++)
            if(!tab[i][j])
            {
                num++;
                if(!ur.empty() && num == ur.back())
                {
                    kra.push_back(MP(i,j));
                    tab[i][j] = tab[j][i] = 1;
                    ur.pop_back();
                }
            }



    Random_shuffle(kra.begin(), kra.end());
    for(int i = 0;i < kra.size();i++)
        if(R(0,1))
            swap(kra[i].FI, kra[i].SE);
    deque<int> kol(n+7);
    for(int i = 1;i <= n;i++) kol[i] = i;
    Random_shuffle(kol.begin()+1, kol.begin()+n+1);

    for(int i = 0;i < kra.size();i++)
        fprintf(file, "%d %d\n", kol[kra[i].FI], kol[kra[i].SE]);

    //Koniec
    if(filename[0] != 0) fclose(file);
}


int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        GenerateRandom1("odn1-1p20.in" , 1,  20,  19);
        GenerateRandom1("odn2-1.in"    , 2,  20,   20);
        GenerateRandom1("odn3-1.in"    , 3,  20,  190);
        GenerateRandom1("odn4-1.in"    , 4,  20,   50);
        GenerateRandom1("odn5-1.in"   ,1509554281, 16, 74);
        GenerateRandom1("odn6-1.in"    , 5,  19,  120);
        GenerateRandom1("odn7-1.in"    , 6,   2,    1);

        GenerateRandom1("odn8-2p20.in" , 7,  40,  700);
        GenerateRandom1("odn9-2.in"    , 8,  35,  595);
        GenerateRandom1("odn10-2.in"    , 9,  31,  251);

        GenerateRandom1("odn11-3p20.in",10,  70, 2415);
        GenerateRandom1("odn12-3.in"   ,11,  69, 1723);
        GenerateRandom1("odn13-3.in"   ,12,  70,   69);
        GenerateRandom1("odn14-3.in"   ,13,  70,   81);
        
        GenerateRandom1("odn15-4p20.in",14,  90, 4000);
        GenerateRandom1("odn16-4.in"   ,15,  90, 3245);
        GenerateRandom1("odn17-4.in"   ,16,  85,  234);
        GenerateRandom1("odn18-4.in"   ,17,  90,   93);
        //GenerateRandom1("odn22-5.in"   ,22,  

        GenerateRandom1("odn19-5p20.in",18, 100, 4950);
        GenerateRandom1("odn20-5.in"   ,19, 100,   99);
        GenerateRandom1("odn21-5.in"   ,20, 100, 2347);
        GenerateRandom1("odn22-5.in"   ,190686788, 95, 553);
    }
    else
    {
        srand(atoi(argv[1]));
        int n = R(5,90);
        int m = R(n-1,n*(n-1)/2);
        int rr = rand();
        cerr << "N: " << n << " M: " << m << " RR: " << rr << endl;
        GenerateRandom1("", rr, n,m);
    }

    return 0;
}

