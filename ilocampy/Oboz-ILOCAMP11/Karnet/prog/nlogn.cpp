#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, czapa = 1048576 * 2;
int tab[N];
long long pref[N], dp[N];
int n, k, q;

long long drz[2 * czapa];

void insert(int poz, long long w) {
    poz += czapa;
    while(poz >= 1) {
        drz[poz] = max(drz[poz], w);
        poz /= 2;
    }
}

long long query(int poza, int pozb) {
    if(poza > pozb) return 0;
    poza += czapa;
    pozb += czapa;
    long long ret = max(drz[poza], drz[pozb]);
    while(poza / 2 != pozb / 2) {
        if(poza % 2 == 0)
            ret = max(ret, drz[poza + 1]);
        if(pozb % 2 == 1)
            ret = max(ret, drz[pozb - 1]);
        poza /= 2;
        pozb /= 2;
    }
    return ret;
}

void remove(int poz) {
    poz += czapa;
    while(poz >= 1 && drz[poz] > 0) {
        drz[poz] = 0;
        poz /= 2;
    }
}
inline long long DP(int w) {
    if(w > n) return 0;
    return dp[w];
}

inline long long P(int w) {
    w = min(w, n);
    return pref[w];
}


int main() {
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {    
        scanf("%d", &tab[i]);
        pref[i] = pref[i - 1] + tab[i];
    }
    
    scanf("%d", &q);
    
    while(q--) {
        scanf("%d", &k);
        
        for(int i = n; i >= n - k + 1; i--) {
            dp[i] = pref[n] - pref[i - 1];
            insert(i, DP(i + 1) + pref[i - 1]);
        }
        
        for(int i = n - k; i >= 1; i--) {
            
            dp[i] = max(query(i + 1, i + k - 1) - P(i - 1), max(DP(i + 1), P(i + k - 1) - P(i - 1) + DP(i + 2 * k)));;
            insert(i, DP(i + 1) + P(i - 1));
        }
        
        for(int i = 1; i <= n; i++) {
            remove(i);
        }
        
        printf("%lld\n", dp[1]);
    }
    
    return 0;
}