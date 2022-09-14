#include<bits/stdc++.h>
using namespace std;

const int MAX = 150000;
vector<int>graf[MAX];

void solve(){
    int n, q; cin >> n >> q;
    for (int i = 1; i<n; i++){
        int a, b; cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    while (q--){    

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}