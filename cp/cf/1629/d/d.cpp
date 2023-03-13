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

#define Y cout << "YES\n";\
        return;
#define N cout << "NO\n";\
        return;

void solve(){
    int n; cin >> n;
    vector<string>s(n+1);
    for (int i = 1; i<=n; i++) cin >> s[i];
    for (int i = 1; i<=n; i++){
        if (s[i].size() == 1){
            Y
        }
        if (s[i].size() == 2 && s[i][0] == s[i][1]){
            Y
        }
        if (s[i].size() == 3 && s[i][0] == s[i][2]){
            Y
        }
    }
    set<string>secik;
    for (int i = n; i>=1; i--){
        string t = s[i];
        reverse(t.begin(), t.end());
        if (secik.find(t) != secik.end()){
            Y
        }
        secik.insert(s[i]);
    }
    //2 3
    secik.clear();
    for (int i = n; i>=1; i--){
        if (s[i].size() == 3) {
            string t; t += s[i][1]; t += s[i][2];
            reverse(t.begin(), t.end());
            secik.insert(t);
        } else {
            if (secik.find(s[i]) != secik.end()){
                Y
            }
        }
    }
    //3 2
    secik.clear();
    for (int i = 1; i<=n; i++){
        if (s[i].size() == 3) {
            string t; t += s[i][0]; t += s[i][1];
            reverse(t.begin(), t.end());
            secik.insert(t);
        } else {
            if (secik.find(s[i]) != secik.end()){
                Y
            }
        }
    }
    N
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