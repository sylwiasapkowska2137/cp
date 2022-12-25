#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
    return a+rng()%(b-a+1);
}

void solve(){
    int n = p(1, 5);
    cout << n << "\n";
    for (int i = 1; i<=n; i++) cout << (char)('a' + p(0, 2));
    cout << "\n";
    for (int i = 1; i<=n; i++) cout << (char)('a' + p(0, 2));
    cout << "\n";
}

int main(){
    solve();
}