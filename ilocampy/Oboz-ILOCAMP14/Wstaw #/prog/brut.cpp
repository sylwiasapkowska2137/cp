#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, P = 257, M = 1e9 + 7;

int n;
char slowo[N];

int solve() {
    int low = 1;
    int high = n;
    int ret = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        int p = 1;
        int hash = 0;
        map<int, int> cntHash;
        for (int i = 1; i <= mid; i++) {
            hash = ((long long)hash * P + slowo[i]) % M;
            p = (long long)p * P % M;
        }
        bool found = false;
        cntHash[hash]++;
        for (int i = mid + 1; i <= n; i++) {
            hash = ((long long)hash * P + slowo[i]) % M;
            hash = (((hash - ((long long)slowo[i - mid] * p)) % M) + M) % M;
            cntHash[hash]++;
            if (cntHash[hash] > 1) {
                found = true;
                break;
            }
        }
        if (found) {
            ret = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ret;
}

int main() {

    scanf("%d", &n);

    scanf("%s", &slowo[1]);

    int ans = n;
    int ind = 0;
    for (int i = 1; i <= n; i++) {
        char tmp = slowo[i];
        slowo[i] = '#';
        int x = solve();
        cerr << x << " ";
        if (x < ans) {
            ans = x;
            ind = i;
        }
        slowo[i] = tmp;
    }

    printf("%d %d\n", ans, ind);

    return 0;
}