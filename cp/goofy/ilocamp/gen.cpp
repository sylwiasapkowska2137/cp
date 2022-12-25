#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
    return a+rng()%(b-a+1);
}

void solve(){
    int n = p(1, 5);
    int q = p(1, 5);
    int k = p(1, 10);
    cout << n << " " << k << " " << q << "\n";
    for (int i = 0; i<n; i++) cout << p(1, k) << " ";
    cout << "\n";
    while (q--) cout << p(1, n) << " " << p(1, k) << "\n";
}

int main(){
    solve();
}