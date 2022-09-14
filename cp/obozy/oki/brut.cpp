#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve(){
    int n, k; cin >> n >> k;
    vector<string>tab(n);
    for (int i = 0; i<n; i++){
        cin >> tab[i];
    }
    LL ans = 0LL;
    for (int i = 0; i<n; i++){
        for (int j = i+1; j<n; j++){
            bool ok = 0;
            for (int K = 0; K<k; K++){
                if (tab[i][K] == '1' && tab[j][K] == '1'){
                    ok = 1;
                    break;
                }
            }
            if (ok) ans++;
        }
    }
    cout << ans << "\n";
}

int main(){
    solve();
}