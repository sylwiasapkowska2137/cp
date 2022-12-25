#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<pair<int, int>>b;
    for (int i = 1; i<=n; i++){
        int x; cin >> x;
        if (i > 1 && i < n){
            b.emplace_back(x, i);
        }
    }
    sort(b.begin(), b.end());
    for (auto [x, y]: b){
        cerr << x << " " << y << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}