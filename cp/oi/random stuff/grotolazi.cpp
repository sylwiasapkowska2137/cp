#include <iostream>
#include <vector>

using namespace std;
#define LL long long
#define pb push_back

bool graf[207][207];
vector <bool> up, dw;

void floyd_warshall(int n){
    for (int k = 1; k<n; k++){
        for (int i = 1; i<n; i++){
            if (graf[i][k]){
                for (int j = 1; j<n; j++) graf[i][j] = graf[i][j]|graf[k][j];
            }
        }
    }
    for (int i = 1; i<n; i++) graf[i][i] = 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n;
    for (int i = 1; i<n-1; i++){
        cin >> a;
        while (a--){
            cin >> b;
            graf[i][b] = 1;
        }
    }
    up.assign(n+1, false);
    dw.assign(n+1, false);
    for (int i = 1; i<n; i++){
        up[i] = graf[1][i];
        dw[i] = graf[i][n];
    }

    return 0;
}