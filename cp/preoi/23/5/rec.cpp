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

typedef pair<int, int> T;
const int mx = 4e3+7;
bitset<mx> X[mx];
bitset<mx>what;

long long C2(int x){
    return (long long)x * (x-1)/2LL;
}

void solve(){
    int n; cin >> n;
    vector<int>sx;
    vector<T>points;
    for (int i = 0; i<n; i++){
        int x, y; cin >> x >> y;
        points.emplace_back(x, y);
        sx.emplace_back(x);
        sx.emplace_back(y);
    }
    sort(sx.begin(), sx.end());
    sx.erase(unique(sx.begin(), sx.end()), sx.end());
    for (auto &[x, y]: points){
        x = lower_bound(sx.begin(), sx.end(), x) - sx.begin()+1;
        y = lower_bound(sx.begin(), sx.end(), y) - sx.begin()+1;
        debug(x, y);
        X[y].set(x, 1);
        what.set(y, 1);
    }
    bitset<mx>now;
    long long ans = 0;
    for (int i = 1; i<mx; i++){
        if (!what[i]) continue;
        for (int j = i+1; j<mx; j++){
            if (!what[j]) continue;
            now = (X[i] & X[j]);
            debug(i, j, (int)now.count());
            ans += C2((int)now.count());
        }
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