//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;
#define N cout << "No\n"; return;

void solve(){
    string s; cin >> s;
    if (s.size() != 8){
        N
    }
    bool ok = 1;
    ok &= (s[0] >= 'A' && s[0] <= 'Z');
    if (!ok){
        N
    }
    ok &= (s.back() >= 'A' && s.back() <= 'Z');
    int x = 0;
    for (int i = 1; i<=6; i++){
        x*=10;
        ok &= (s[i] >= '0' && s[i] <= '9');
        x += (int)(s[i]-'0');
    }
    ok &= (x >= 100000 && x <= 999999);
    if (!ok){
        N
    }
    cout << "Yes\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}