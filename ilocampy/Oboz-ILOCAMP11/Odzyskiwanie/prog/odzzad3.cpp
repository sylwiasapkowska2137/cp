//Przemysław Jakub Kozłowski
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
typedef long long LL;
const int N = 1000006, MOD = 1000000007;

inline int pot(int a, int k, int mod)
{
    int ret = 1;
    while(k)
    {
        if(k%2) ret = (LL)ret*a%mod;
        k /= 2;
        a = (LL)a*a%mod;
    }
    return ret;
}

int dzielsil[N];

inline void init(int n)
{
    for(int i = n;i >= 1;i--)
        dzielsil[i] = pot(i, MOD-2, MOD);
}

inline int obl_przedzial(int S, int T)
{
    // (S+T-1 po T) = (S+T-1)! / (S-1)! / T!
    int ret = 1;
    for(int i = S;i <= S+T-1;i++)
        ret = (LL)ret*i%MOD;
    ret = (LL)ret*dzielsil[T]%MOD;
    return ret;

}

int obl(int n, int m, const int *B)
{
    vector<int> stos;
    stos.push_back(0);

    int wyn = 1;
    pair<int,int> prz = MP(0,0);
    int count = 0;
    int last = m;
    for(int i = 1;i <= n+1;i++)
    {
        pair<int,int> curr = MP(0,0);
        if(i == n+1) curr = MP(0,0);
        else if(i != n && B[i] < B[i+1])
        {
            while(B[i+1] <= stos.back()) stos.pop_back();
            if(B[i] != stos.back()) return 0;
            stos.push_back(B[i+1]);
            if(prz.FI != 0) prz.FI = max(prz.FI, B[i+1]);
            last = m;
        }
        else
        {
            while(B[i] < stos.back())
            {
                last = stos.back();
                stos.pop_back();
            }
            if(B[i] != stos.back()) return 0;
            curr = MP(stos.back()+1, last);
        }
        //
        if(prz != curr)
        {
            if(prz.FI != 0 && count > 0) wyn = (LL)wyn*obl_przedzial(prz.SE-prz.FI+1, count)%MOD;
            prz = curr;
            count = 0;
        }
        count++;
    }

    return wyn;
}

int n,m;
int B[N];

int main()
{
    scanf("%d%d", &n, &m);

    for(int i = 1;i <= n;i++)
        scanf("%d", &B[i]);

    init(n);
    printf("%d\n", obl(n,m,B));

    return 0;
}
