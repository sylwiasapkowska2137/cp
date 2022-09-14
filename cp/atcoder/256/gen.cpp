#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
    return a+rng()%(b-a+1);
}

void solve(){
    int n = p(1, 5);
    int q = p(1, 5);
    cout << n << " " << q << "\n";
    for (int i = 0; i<n; i++) cout << p(1, 5) << " ";
    cout << "\n";
    while (q--){
        int t = p(1, 3);
        int a = p(1, n);
        int b = p(1, n);
        if (a > b) swap(a, b);
        cout << t << " " << a << " " << b << " ";
        if (t == 1){
            cout << p(2, 5) << "\n";
        } else if (t == 2){
            cout << p(1, 5) << "\n";
        } else {
            cout << "\n";
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