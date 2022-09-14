#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+1;

char c[N][N], r[N][N];
int n;

void rot90() {
    char t[N][N];
    for (int j=1; j<=n; ++j) {
        int x=n;
        for (int i=1; i<=n; ++i, --x) {
            t[j][x]=c[i][j];
        }
    }

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            c[i][j]=t[i][j];
        }
    }
}

void rotox() {
    char t[N][N];
    for (int j=1; j<=n; ++j) {
        for (int i=1; i<=n; ++i) {
            t[n-i+1][j]=c[i][j];
        }
    }

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            c[i][j]=t[i][j];
        }
    }
}

bool check() {
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (c[i][j] != r[i][j]) return false;
        }
    }

    return true;
}

void rotoy() {
    char t[N][N];
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            t[i][n-j+1]=c[i][j];
        }
    }

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            c[i][j]=t[i][j];
        }
    }
}

int main() {
    int t; cin>>t;
    while (t--) {
        cin>>n;
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                cin>>c[i][j];
            }
        }

        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                cin>>r[i][j];
            }
        }

        bool ans=false;
        for (int i=0; i<4; ++i) {
            rot90();
            ans |= check();
            rotox();
            ans |= check();
            rotox();

            rotoy();
            ans |= check();
            rotoy();
        }

        if (ans) cout<<"TAK\n";
        else cout<<"NIE\n";
    }
}