#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+10;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

char c[N][N];
int n, m;

bool valid(int i, int j) {
    return (1 <= i && i <= n) && (1 <= j && j <= m);
}

int main() {
    cin>>n>>m;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            cin>>c[i][j];
        }
    }

    bool ok=true;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            if (c[i][j] != 'S') continue;
            for (int k=0; k<4; ++k) {
                int ni=i+di[k], nj=j+dj[k];
                if (valid(ni, nj) && c[ni][nj] == 'W') {
                    ok=false;
                }
            }
        }
    }

    if (ok) cout<<"TAK\n";
    else cout<<"NIE\n"; 
}