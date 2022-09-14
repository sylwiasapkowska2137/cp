#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int>tab(n+1);
    for (int i = 1; i<=n; i++) cin >> tab[i];
    int q; cin >> q;
    for (int i = 0; i<q; i++){
        int a, b, s; cin >> a >> b >> s;
        int l = b-a+1;
        bool ok = 0;
        for (int mask = 0; mask<(1<<l); mask++){
            int sum = 0;
            for (int j = 0; j<l; j++){
                if (mask&(1<<j)){
                    sum += tab[a+j];
                }
            }
            if (sum == s){
                ok = 1;
                break;
            }
        }
        if (ok) cout << "TAK\n";
        else cout << "NIE\n";
    }
}

int main(){
    solve();
}