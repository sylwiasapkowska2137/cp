#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int p(int a, int b){
    return a+rng()%(b-a+1);
}

void solve(){
    int n = p(1, 500);
    int k = p(1, 1e9);
    cout << n << " " << k << "\n";
    for (int i = 0; i<n; i++) cout << p(1, 1e9) << " ";
    cout << "\n";
}

int main(){
    solve();
}