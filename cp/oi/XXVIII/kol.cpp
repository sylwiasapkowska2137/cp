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
const int mx = 5e5+7, K = 22;
int st[mx][K], lg2[mx];

int gcd(int a, int b){
    while (b){
        a %= b;
        swap(a, b);
    }
    return a;
}

int query(int l, int r){
    int k = lg2[r-l+1];
    return gcd(st[l][k], st[r-(1<<k)+1][k]);
}

void solve(){
    int n; cin >> n;
    int ans = 0;
    int curr = 0;
    lg2[1] = 0;
    for (int i = 2; i<mx; i++) lg2[i] = lg2[i/2]+1;
    for (int i = 1; i<=n; i++){
        int a, b; cin >> a >> b;
        ans = gcd(ans, b);
        curr = gcd(curr, a);
        st[a][0] = gcd(st[a][0], b);
    }
    
    for (int j = 1; j<K; j++){
        for (int i = 0; i + (1<<j) - 1 < mx; i++){
            st[i][j] = gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    ans = max(ans, curr);
    for (int i = 1; i<mx; i++){
        int now = i;
        for (int j = 0; j+1<mx; j+=i){
            now = gcd(now, query(j+1, min(mx-1, j+i-1)));
        }
        ans = max(ans, now);
    }
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}