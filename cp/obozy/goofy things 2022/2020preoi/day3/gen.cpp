#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long LL;

LL p(LL a, LL b){
    return a+rng()%(b-a+1);
}

const int MAX = 1000;
set<int>s[MAX];

void solve(){
    int n = p(1, 1000);
    int m = p(1, 10000);
    int q = p(1, 1000);
    cout << n << " " << m << " " << q << "\n";
    for (int i = 1; i<=n; i++){
        int x = p(0, i-1);
        while (s[x].size() == 5){
            x = p(0, i-1);
        }
        int c = p(0, 4);
        while (s[x].find(c) != s[x].end()){
            c = p(0, 4);
        }
        s[x].insert(c);
        cout << x << " " << (char)(c+'a') << "\n";
    }
    for (int i = 0; i<m; i++) cout << (char)(p(0, 4)+'a');
    cout << "\n";
    while (q--){
        int a = p(1, m);
        int b = p(1, m);
        if (b < a) swap(a, b);
        cout << a << " " << b << "\n";
    }
}

void solve2(){
    int n = p(1, 10);
    cout << n << "\n";
    for (int i = 0; i<n; i++) cout << p(1, 10) << ((i!=n-1?" ":""));
    cout << "\n";
    int q = p(1, 10);
    cout << q << "\n";
    for (int i = 0; i<q; i++){
        int l = p(1, n);
        int r = p(1, n);
        if (r < l) swap(l, r);
        cout << l << " " << r << " " << p(1, 10) << "\n";
    }
}

int main(){
    solve2();
}