#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9, N = 500005;

int n, m, tab[N];
int tree[3 * N], added[3 * N];
int BASE;

void insert(int pos, int w) {
    pos += BASE;
    tree[pos] = w + 2 * added[pos];
//         cerr << pos << " " << tree[pos] << endl;
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]) + 2 * added[pos];
//         cerr << pos << " " << tree[pos] << endl;
        pos /= 2;
    }
}

void add(int posa, int posb, int w) {
    posa += BASE;
    posb += BASE;
    added[posa] += w;
    if (posa != posb) {
        added[posb] += w;
    }
    while (posa > 1) {
        if (posa / 2 != posb / 2) {
            if (posa % 2 == 0) {
                added[posa + 1] += w;
                tree[posa + 1] += 2 * w;
            }
            if (posb % 2 == 1) {
                added[posb - 1] += w;
                tree[posb - 1] += 2 * w;
            }
        }
        posa /= 2;
        posb /= 2;
        tree[posa] = max(tree[posa * 2], tree[posa * 2 + 1]) + 2 * added[posa];
        tree[posb] = max(tree[posb * 2], tree[posb * 2 + 1]) + 2 * added[posb];
    }
}

int query(int posa, int posb) {
    if (posb < posa) {
        return -INF;
    }
    posa += BASE;
    posb += BASE;
    int retA = tree[posa];
    int retB = tree[posb];

    while (posa > 1) {
        if (posa / 2 != posb / 2) {
            if (posa % 2 == 0) {
                retA = max(retA, tree[posa + 1]);
            }
            if (posb % 2 == 1) {
                retB = max(retB, tree[posb - 1]);
            }
        }
        posa /= 2;
        posb /= 2;
        retA += 2 * added[posa];
        retB += 2 * added[posb];
    }

    return max(retA, retB);
}

int ones;
void setVal(int pos) {
    if (tab[pos] == 1) {
        insert(pos, -pos - 1);
    } else {
        insert(pos, -INF);
    }
}

int main() {

    scanf("%d %d", &n, &m);
    set<int> zeros;
    BASE = 1;
    while (BASE <= n) BASE *= 2;
    for (int i = 1; i < 2 * BASE; i++) {
        tree[i] = -INF;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        if (tab[i]) {
            ones++;
            add(i, n, 1);
        } else {
            zeros.insert(i);
        }
        setVal(i);
    }

    int last = !zeros.empty() ? *(zeros.rbegin()) : 0;
//     cerr << last << " " << query(1, last) << endl;
    printf("%d\n", max(0, n - ones + query(1, last)));
    while (m--) {
        int pos;
        scanf("%d", &pos);
        tab[pos] ^= 1;
        if (tab[pos]) {
            ones++;
            add(pos, n, 1);
            zeros.erase(pos);
        } else {
            ones--;
            add(pos, n, -1);
            zeros.insert(pos);
        }
        setVal(pos);
        int last = !zeros.empty() ? *(zeros.rbegin()) : 0;
//         cerr << last << endl;
        printf("%d\n", max(0, n - ones + query(1, last)));
    }

    return 0;
}