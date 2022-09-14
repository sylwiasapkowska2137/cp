#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<string>tab(n);
    for(int i = 0; i<n; i++){
        cin >> tab[i];
        reverse(tab[i].begin(), tab[i].end());
    }
    int ans = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (i == j) continue;
            //z i usunac literki zeby zrobic j
            if (tab[j].size() > tab[i].size()) continue;
            bool ok = 1;
            for (int k = 0; k<(int)tab[j].size()-1; k++){
                if (tab[j][k]!=tab[i][k]){
                    ok = 0;
                    break;
                }
            }
            if (!ok) continue;
            ok = 0;
            for (int k = tab[j].size()-1; k<(int)tab[i].size(); k++){
                ok |= (tab[i][k] == tab[j].back());
            }
            ans += ok;
        }
    }
    cout << ans << "\n";
}

int main(){
    solve();
}