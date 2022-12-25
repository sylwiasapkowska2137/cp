#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<pair<pair<long double, long double>, int>>a(n);
    for (int i = 0; i<n; i++){
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i+1;
    }
    sort(a.rbegin(), a.rend(), [&](auto x, auto y){return x.first.first * y.first.second < x.first.second * y.first.first;});
    for (auto [x, y]:a) cout << y << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;
}