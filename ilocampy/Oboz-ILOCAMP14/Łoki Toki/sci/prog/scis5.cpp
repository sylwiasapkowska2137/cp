#include <stdio.h>
#define ULL unsigned long long

ULL S, A, B, L;
ULL rand() { return S = S * A + B; }

int n;
void multiply(bool **a, bool **b, bool **res) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            res[i][j] = false;
            for (int k=0; k<n; k++) {
                res[i][j] += a[i][k] * b[k][j];
                if (res[i][j]) break;
            }
        }
    }
}

bool **new_tab() {
    bool **res = new bool*[n];
    for (int i=0; i<n; i++) {
        res[i] = new bool[n];
        for (int j=0; j<n; j++) res[i][j] = false;
    }
    return res;
}

void free_tab(bool **t) {
    for (int i=0; i<n; i++) {
        delete[] t[i];
    }
    delete[] t;
}

int main() {
    int m, u, v, q;
    scanf("%d%d", &n,&m);
    bool **t[64];
    for (int i=1; i<64; i++) t[i] = new_tab();
    while (m--) {
        scanf("%d%d", &u,&v);
        t[1][u][v] = true;
    }
    for (int i=2; i<64; i++)
        multiply(t[i-1], t[i-1], t[i]);
    scanf("%d%llu%llu%llu%llu", &q,&S,&A,&B,&L);
    char ans[q/4+1];
    for (int i=0; i<q/4+1; i++) ans[i] = 0;
    int rest = q%4 ? 4-q%4 : 0;
    int first = -1;
    bool **current = new_tab();
    bool **buffer = new_tab();
    for (int z=rest; z<q+rest; z++) {
        u = rand() % n;
        v = rand() % n;
        int k = rand() % L, p=1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) current[i][j] = false;
            current[i][i] = true;
        }
        while (k) {
            if (k % 2) {
                multiply(current, t[p], buffer);
                bool **tmp = current;
                current = buffer;
                buffer = tmp;
            }
            p++;
            k /= 2;
        }
        if (current[u][v]) {
            ans[z/4] |= 1<<(3-(z%4));
            if (first == -1) first = z/4;
        }
    }

    for (int i=1; i<64; i++) free_tab(t[i]);
    free_tab(current);
    free_tab(buffer);
    
    if (first == -1) {
        printf("0\n");
        return 0;
    }
    for (int i=first; i<(q+rest)/4; i++) printf("%x", ans[i]);
    printf("\n");
    return 0;
}
