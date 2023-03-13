#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

pair<long long, int>S[N];
int psize, ksize, n, q, k;
int tab[N];
long long dp[N], pref[N];

inline long long DP(int w) {
    if(w > n) return 0;
    return dp[w];
}

inline long long PREF(int w) {
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
        
        ksize = -1;
        psize = 0;
        
        for(int i = n; i >= 1; i--) {
            while(psize <= ksize && S[psize].second > i + k) {
                psize++;
            }
            
            dp[i] = PREF(i + k - 1) - PREF(i - 1) + DP(i + 2 * k);
            
            if(psize <= ksize) {
                long long best = S[psize].first;
                dp[i] = max(dp[i], best - PREF(i - 1));
            }
            
            while(ksize >= psize && dp[i] + PREF(i - 2) >= S[ksize].first) {
                ksize--;
            }
            
            if(i > 1) {
                S[++ksize] = {dp[i] + PREF(i - 2), i};
            }
        }
        
        printf("%lld\n", dp[1]);
    }
    
    return 0;
}