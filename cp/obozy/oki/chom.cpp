#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int x = 0;
    for (int i = 1; i<=n; i++){
        x^=i;
    }
    for (int i = 1;i<n; i++){
        int y; cin >> y;
        x^=y;
    }
    cout << x << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}