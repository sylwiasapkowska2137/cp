#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, q; cin >> n >> q;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    while (q--){
        int t; cin >> t;
        if (t == 1){
            int l, r, x; cin >> l >> r >> x;
            for (int i = l; i<=r; i++) a[i]/=x;
        } else if (t == 2){
            int l, r, y; cin >> l >> r >> y;
            for (int i = l; i<=r; i++) a[i] = y;
        } else {
            int l, r; cin >> l >> r;
            int ans = 0;
            for (int i = l; i<=r; i++) ans += a[i];
            cout << ans << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}