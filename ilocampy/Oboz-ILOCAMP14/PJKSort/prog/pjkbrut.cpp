#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n, m, tab[N], tab2[N];

int simulate() {
    for (int i = 1; i <= n; i++) {
        tab2[i] = tab[i];
    }
    int ans = 0;
    while (true) {
        vector<int> swaps;
        for (int i = 1; i < n; i++) {
            if (tab[i] == 1 && tab[i + 1] == 0) {
                swaps.push_back(i);
            }
        }
        for (int i = 0; i < swaps.size(); i++) {
            swap(tab[swaps[i]], tab[swaps[i] + 1]);
        }
        if (swaps.size())  {
            ans++;
        } else {
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        tab[i] = tab2[i];
    }
    return ans;
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }

    printf("%d\n", simulate());

    while (m--) {
        int pos;
        scanf("%d", &pos);
        tab[pos] ^= 1;
        printf("%d\n", simulate());
    }

    return 0;
}