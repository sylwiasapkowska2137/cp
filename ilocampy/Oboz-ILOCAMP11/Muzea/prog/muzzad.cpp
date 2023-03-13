#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

const int MAXN = 300 * 1000;
const int MAXV = 300 * 1000;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    assert(1 <= n && n <= MAXN);
    assert(1 <= m && m <= MAXN);

    int x;
    std::vector<int> muzeum1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        assert(1 <= x && x <= MAXV);
        muzeum1.push_back(x);
    }

    std::vector<int> muzeum2;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        assert(1 <= x && x <= MAXV);
        muzeum2.push_back(x);
    }

    std::sort(muzeum1.begin(), muzeum1.end());
    std::sort(muzeum2.begin(), muzeum2.end());

    int result = -1;
    int pos2 = 0;

    for (int i = 0; i < muzeum1.size(); i++) {
        while (pos2 + 1 < muzeum2.size() && muzeum2[pos2] < muzeum1[i]) {
            pos2++;
        }

        if (muzeum1[i] == muzeum2[pos2]) {
            result = muzeum1[i];
        }
    }

    printf("%d", result);

    return 0;
}