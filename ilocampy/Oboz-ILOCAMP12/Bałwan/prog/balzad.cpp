#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, size;
int tab[N], pref[N], S[N];

int search(int w) {
    int poc = 1;
    int kon = size;
    int ret = size + 1;
    while (poc <= kon) {
        int sr = (poc + kon) / 2;
        if (S[sr] >= w) {
            kon = sr - 1;
            ret = sr;
        } else {
            poc = sr + 1;
        }
    }
    return ret;
}

int main() {
    S[0] = -1e9 - 5;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        pref[i] = search(tab[i]);
        S[pref[i]] = tab[i];
        if (pref[i] > size) {
            size = pref[i];
        }
    }
    
    size = 0;
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        int s = search(-tab[i - 1] - 1);
        ans = max(ans, pref[i - 1] + s);
        s = search(-tab[i]);
        S[s] = -tab[i];
        if (s > size) {
            size = s;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}