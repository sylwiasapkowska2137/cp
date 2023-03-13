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

int ti(char c) {
    return (int)(c-'a');
}

void solve(){
    string s; cin >> s;
    sort(s.begin(), s.end());
    string L, R;
    int n = (int)s.size();
    bool last = 0;
    for (int i = 0; i+1<n; i+=2){
        if (s[i] == s[i+1]){
            L += s[i];
            R += s[i+1];
            if (i + 1 == n-1) last = 1;
        } else {
            if (s.back() == s[i+1]){
                for (int j = i+1; j<n; j++){
                    if (j&1) L += s[j];
                    else R += s[j];
                }
                last = 1;
                L += s[i];
                break;
            }
            for (int j = i+1; j<n; j++){
                L += s[j];
            }
            L += s[i];
            last = 1;
            break;
        }
    }
    if (!last) L += s[n-1];
    reverse(R.begin(), R.end());
    L += R;
    string P = L;
    reverse(P.begin(), P.end());
    cout << max(L, P) << "\n";
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