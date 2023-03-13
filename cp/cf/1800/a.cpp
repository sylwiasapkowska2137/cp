//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
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
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
typedef pair<int, int> T;
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    for (auto &c: s){
        if (c == 'M') c = 'm';
        if (c == 'E') c = 'e';
        if (c == 'O') c = 'o';
        if (c == 'W') c = 'w';
    }
    vector<char>ok = {'m', 'e', 'o', 'w'};
    
    for (auto x: ok){
        int cnt = 0;
        for (auto c: s){
            if (c == x) {
                cnt++;
            }
        }
        if (!cnt){
            cout << "NO\n";
            return;
        }
    }
    for (auto c: s){
        bool now = 0;
        for (auto x: ok){
            now |= (c == x);
        }
        if (!now){
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i<4; i++){
        for (int j = i+1; j<4; j++){
            int last = -oo, fst = oo;
            for (int k = 0; k<n; k++){
                if (s[k] == ok[i]){
                    last = k;
                }
                if (s[k] == ok[j]){
                    if (fst == oo){
                        fst = k;
                    }
                }
                if (last > fst){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}