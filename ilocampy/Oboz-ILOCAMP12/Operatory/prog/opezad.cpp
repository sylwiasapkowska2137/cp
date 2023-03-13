//Przemysław Jakub Kozłowski
#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;
typedef unsigned char uchar;
const int N = 10000027, INF = 1000000009, Csize = 5*N/16, Bsize = 9*N/2/2;
const ushort PIEC = (((1<<5)-1)<<11);

int n;
uchar Ctab[Csize];
bitset<Bsize> Btab;
int Bmin = INF, Bmax = -INF;

inline char Cget(int x)
{
    int poz = 5*(x)/8;
    int prz = 5*(x)%8;
    ushort w = (((ushort)Ctab[poz])<<8)+Ctab[poz+1];
    char c = ((PIEC>>prz)&w)>>(11-prz);
    if(c > 9) c -= 19;
    return c;
}
inline void Cset(int x, char c)
{
    if(c < 0) c += 19;
    int poz = 5*(x)/8;
    int prz = 5*(x)%8;
    ushort w = (((ushort)Ctab[poz])<<8)+Ctab[poz+1];
    ushort v = (((ushort)c)<<11);
    w = ((w&~(PIEC>>prz))|(v>>prz));
    Ctab[poz] = w>>8;
    Ctab[poz+1] = w;
}

inline void Bdodaj(int a, int b)
{
    a /= 2; b /= 2;
    int tsum;

    tsum = 0;
    for(int i = b;i >= a;i--)
    {
        int w = Cget(i);
        tsum += abs(w);
        Bmin = min(Bmin, tsum);
        Bmax = max(Bmax, tsum);
        tsum = tsum-abs(w)+w;
    }

    tsum = 0;
    for(int i = b;i >= a;i--)
    {
        int w = Cget(i);
        tsum += abs(w);
        if(Bmax-tsum < Bsize && tsum-Bmin < Bsize)
            Btab[(Bsize+tsum)%Bsize] = true;
        tsum = tsum-abs(w)+w;
    }
}

inline void Bwyczysc(int a, int b)
{
    a /= 2; b /= 2;
    Bmin = INF;
    Bmax = -INF;

    int tsum = 0;
    for(int i = b;i >= a;i--)
    {
        int w = Cget(i);
        tsum += abs(w);
        Btab[(Bsize+tsum)%Bsize] = false;
        tsum = tsum-abs(w)+w;
    }
}

inline bool Bcheck(int x)
{
    if(Bmax-x < Bsize && x-Bmin < Bsize)
        return Btab[(Bsize+x)%Bsize];
    else
        return false;
}

int main()
{
    scanf("%d ", &n);

    char cfirst = getchar_unlocked() - '0';
    int pocz1 = 1, pocz2 = 1, tsum = 0, wyn = 0;
    char lastop = 0;
    tsum += cfirst;
    Cset(0, cfirst);
    for(int i = 3;i <= n;i += 2)
    {
        char c1 = getchar_unlocked();
        char c2 = getchar_unlocked() - '0';

        if(pocz1 < i && (c1 == '=' || c1 == '<' || c1 == '>'))
        {
            if(pocz1 == pocz2)
            {
                pocz2 = i;
                Bdodaj(pocz1, pocz2 - 2);
            }
            else
            {
                Bwyczysc(pocz1, pocz2 - 2);
                pocz1 = pocz2;
                pocz2 = i;
                Bdodaj(pocz1, pocz2 - 2);
            }
            lastop = c1;
            tsum = 0;
        }

        char w = (i > pocz2 && c1 == '-' ? -c2 : c2);
        tsum += w;
        Cset(i/2, w);

        if( pocz1 != pocz2 && (
            (lastop == '=' && Bcheck(tsum)) ||
            (lastop == '<' && Bmin < tsum) ||
            (lastop == '>' && Bmax > tsum)
        ))
        {
            wyn++;
            Bwyczysc(pocz1, pocz2 - 2);
            pocz1 = pocz2 = i+2;
        }
    }

    printf("%d\n", wyn);

    return 0;
}
