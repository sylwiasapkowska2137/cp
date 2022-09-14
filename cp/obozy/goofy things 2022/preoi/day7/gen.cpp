#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p(int a, int b){
    return a+rng()%(b-a+1);
}

void solve(){
    int n = p(1, 100);
    for (int i = 0; i<n; i++) cout << (char)(p(0, 25)+'a');
    cout << "\n";
    cout << p(1, 26) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}