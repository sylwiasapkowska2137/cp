#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
    return a+rng()%(b-a+1);
}

void solve(){  
    int n = p(2e5, 3e5);
    int q = p(2e5, 3e5);
    cout << n << " " << q << "\n";
    for (int i = 1; i<=n; i++) cout << p(0, 1e9) << " ";
    cout << "\n";
    for (int i = 0; i<q; i++){
        int l = p(1, n);
        int r = p(1, n);
        if (l > r) swap(l, r);
        cout << l << " " << r << "\n";
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}