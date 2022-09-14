#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
    return a+rng()%(b-a+1);
}

void solve(){
    int n = p(1, 1000);
    int m = p(1, 10);
    cout << n << " " << m << "\n";
    for (int i = 0; i<n; i++) cout << p(1, m) << " ";
    cout << "\n";
}

void solve2(){
    int n =p(1, 10000);
    int q = p(1, 10000);
    cout << n << " " << q << "\n";
    for (int i = 0; i<n; i++) cout << p(1, 100) << " ";
    cout << "\n";
    while (q--){
        int t = p(1, 2);
        cout << t << " ";
        if (t == 1){
            int l = p(1, n);
            int r = p(1, n);
            if (l > r) swap(l, r);
            cout << l << " " << r << " " << p(1, 10) << '\n';
        } else {
            cout << p(1, 30) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve2();

    return 0;
}