//Sylwia Sapkowska
#include <bits/stdc++.h>
// #include <bits/extc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
// using namespace __gnu_pbds;

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
int n;

void rec(vector<T>&X, vector<int>&ret){
    if ((int)X.size() == 2){
        ret = {X[0].first, X[0].second};
        if (__builtin_popcount(X[1].first ^ X[0].second) == 1){
            ret.emplace_back(X[1].first);
            ret.emplace_back(X[1].second);
        } else {
            ret.emplace_back(X[1].second);
            ret.emplace_back(X[1].first);
        }
        return;
    }
    int t = X.back().first ^ X.back().second;
    int b = -1;
    for (int i = n-1; i>=0; i--){
        if (t&(1<<i)){
            b = i;
            break;
        }
    }
    // gp_hash_map<int, int>partner;
    unordered_map<int, int>partner;
    vector<int>D1, C[2], ord;
    vector<T>subX[2];
    for (auto &[x, y]: X) {
        partner[x] = y;
        partner[y] = x;
    }
    assert(b != -1);
    debug(b, X);
    for (auto &[x, y]: X){
        if (x&(1<<b)){
            if (y&(1<<b)) subX[1].emplace_back(x, y);
            else D1.emplace_back(y);
        } else {
            if (y&(1<<b)) D1.emplace_back(x);
            else subX[0].emplace_back(x, y);
        }
    }
    debug(D1);
    for (int i = 1; i<(int)D1.size(); i+=2){
        subX[0].emplace_back(D1[i-1], D1[i]);
    }
    bitset<(1<<19)+1>leftover;
    // vector<bool>leftover((1<<n));
    for (auto &x: D1) leftover[x] = 1;
    rec(subX[0], C[0]);
    debug(C[0]);
    for (auto v: C[0]){
        if (leftover[v]){
            ord.emplace_back(v);
        }
    }
    debug(ord);
    for (int i = 1; i<(int)ord.size(); i+=2){
        int j = (i == (int)ord.size() - 1 ? 0 : i+1);
        subX[1].emplace_back(partner[ord[i]], partner[ord[j]]);
    }
    debug(subX[1]);
    rec(subX[1], C[1]);
    debug(C[1]);
    unordered_map<int, int>jump;
    // vector<int>jump((1<<n), -1);
    for (int rep = 0; rep < 2; rep++){
        for (int i = 1; i<(int)C[rep].size(); i+=2){
            int j = (i == (int)C[rep].size() - 1 ? 0 : i+1);
            jump[C[rep][i]] = C[rep][j];
            jump[C[rep][j]] = C[rep][i];
        }
    }
    // vector<int>ret;
    int m = (int)C[1].size();
    int ptr = C[0][0];
    while ((int)ret.size() < 2*m){
        ret.emplace_back(ptr);
        ret.emplace_back(partner[ptr]);
        ptr = jump[partner[ptr]];
    }
    debug(ret);
}

void solve(){
    cin >> n;
    int M = (1<<(n-1));
    vector<T>X(M);
    for (int i = 0; i<M; i++) cin >> X[i].first >> X[i].second;
    vector<int>ans;
    rec(X, ans);
    for (auto x: ans) cout << x << " ";
    cout << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}