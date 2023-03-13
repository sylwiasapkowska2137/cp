#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll; 

#define fi first
#define se second
#define mp make_pair
#define pb push_back


int k;
int n, m;
int a[5005], b[5005];
int nextA[5005][5005];
int nextB[5005][5005];

PII dp[5005][5005];

void read() {
    scanf("%d%d", &k, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
}

void calc(int *a, int b[5005][5005], int n) {
    for (int i = 1; i <= k; i++) {
        b[n + 1][i] = b[n][i] = n + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= k; j++) {
            b[i][j] = b[i + 1][j];
        }
        
        b[i][ a[i + 1] ] = i + 1;
    }
}

void solve() {
    calc(a, nextA, n);
    calc(b, nextB, m);
    
    dp[n + 1][m + 1] = mp(0, -1);
    
    for (int i = n + 1; i >= 0; i--) {
        for (int j = m + 1; j >= 0; j--) {
            if (i == n + 1 && j == m + 1) continue;
            dp[i][j] = mp(1 << 30, -1);
            
            if (i <= n - 1 && j <= m - 1) {
                if (dp[i + 1][j].se != a[i + 1]) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j]);
                }
                
                if (dp[i][j + 1].se != b[j + 1]) {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1]);
                }
            }
            
            if (dp[i][j].fi == (1 << 30)) {
                for (int e = 1; e <= k; e++) {
                    int nX = nextA[i][e];
                    int nY = nextB[j][e];
                    
                    dp[i][j] = min(dp[i][j], mp(dp[nX][nY].fi + 1, e));
                }
            }
        }
    }
    
    printf ("%d\n", dp[0][0].fi);
    int x = 0, y = 0;
    int prnt = 0;
    
    while (x != n + 1 || y != m + 1) {
        int e = dp[x][y].se;
        int nX = nextA[x][e];
        int nY = nextB[y][e];
        
        if (prnt) printf (" ");
        prnt = 1;
        printf ("%d", e);
        x = nX;
        y = nY;
    }
    printf ("\n");
}

int main () {
    read();
    solve();
    return 0; 
}
