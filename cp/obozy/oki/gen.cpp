#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
    return a+rng()%(b-a+1);
}

void solve(){
    int n = p(1, 4);
    cout << n << "\n";
    for (int i = 0; i<n; i++){
        cout << p(1, 100) << " " << p(-100, 100) << "\n";
    }
    int q = p(1, 5);
    map<int, string>type;
    type[0] = "JOIN";
    type[1] = "MASA";
    type[2] = "IQ_MIN";
    type[3] = "IQ_MAX";
    while (q--){
        int t = p(0, 3);
        cout << type[t] << " ";
        if (t == 0) cout << p(1, n) << " " << p(1, n) << "\n";
        else cout << p(1, n) << "\n";
    }
}

int main(){
    solve();
}