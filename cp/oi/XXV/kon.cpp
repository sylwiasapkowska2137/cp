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
const int mod = 1e9+7;

int mul(int a, int b){
    return (a*b)%mod;
}

void add(int &a, int b){
    a += b;
    if (a >= mod) a -= mod;
}

struct Tree{
    vector<int>tab;
    int size = 1;

    Tree(int n){
        while (size < n) size*=2;
        tab.assign(2*size, 0);
    }

    int query(int l, int r){
        int ans = 0;
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = max(ans, tab[l+1]);
            if (r&1) ans = max(ans, tab[r-1]);
        }
        return ans;
    }

    void update(int x, int v){
        x += size;
        tab[x] = max(tab[x], v);
        while (x){
            x/=2;
            tab[x] = max(tab[2*x], tab[2*x+1]);
        }
    }
};

void solve(){
    int n, m; cin >> m >> n;
    vector<T>a;
    vector<int>ss = {-oo};
    for (int i = 0; i<n; i++){
        int l, r; cin >> l >> r;
        a.emplace_back(l, r);
        ss.emplace_back(l);
        ss.emplace_back(r);
    } 
    sort(a.begin(), a.end(), [](auto x, auto y){
        return x.second == y.second ? x.first < y.first : x.second < y.second;});
    sort(ss.begin(), ss.end());
    ss.erase(unique(ss.begin(), ss.end()), ss.end());
    Tree t((int)ss.size()+4);
    auto get = [&](int x){return lower_bound(ss.begin(), ss.end(), x) - ss.begin();};
    vector<vector<int>>group(n+2);
    for (int i = 0; i<n; i++){
        auto &[l, r] = a[i];
        int dp = t.query(0, get(l))+1;
        group[dp].emplace_back(i);
        t.update(get(r), dp);
    }
    map<int, int>dp;
    vector<T>common(n+2, {-oo, oo});
    for (int i = 1; i<=n; i++){
        for (auto idx: group[i]){
            common[i] = {max(common[i].first, a[idx].first), min(common[i].second, a[idx].second)};
        }
        if (common[i].first == -oo){
            common[i] = {oo, -oo};
        }
    }
    vector<int>dp2(n+2);
    dp[common[1].second] = (common[1].second - common[1].first);
    dp2[1] = dp[common[1].second];
    
    for (int i = 1; i<=n; i++){
        if (group[i+1].empty()) break;
        if (a[group[i].back()].second <= a[group[i+1][0]].first){
            dp2[i] = dp2[i];
            dp[common[i+1].second] = dp[common[i].second];
            continue;
        }
        debug(i, group[i]);
        //mergujemy i+1 z i;
        int k = (int)group[i].size();
        vector<T>pref(k), suf(k);
        for (int j = 0; j<k; j++){
            if (j == 0) pref[j] = a[group[i][j]];
            else pref[j] = {max(pref[j-1].first, a[group[i][j]].first), min(pref[j-1].second, a[group[i][j]].second)};
        }
        for (int j = k-1; j>=0; j--){
            if (j == k-1) suf[j] = a[group[i][j]];
            else suf[j] = {max(suf[j+1].first, a[group[i][j]].first), min(suf[j+1].second, a[group[i][j]].second)};
        }

        for (int j = 0; j<k-1; j++){
            T maybe = {max(suf[j+1].first, common[i+1].first), min(suf[j+1].second, common[i+1].second)};
            if (maybe.first <= maybe.second){
                add(dp[maybe.second], mul(pref[j].second - pref[j].first, maybe.second - maybe.first));
                add(dp2[i+1], dp[maybe.second]);
            }
        }
        if (suf.back().second <= common[i+1].second) {
            add(dp[common[i+1].second], mul(dp[common[i].second], (common[i+1].second - suf.back().second)));
            add(dp2[i+1], dp[common[i+1].second]);
        }
        debug(pref);
        debug(suf);
        debug(dp);
        debug();
    }
    debug(dp2);
    cout << t.query(0, (int)ss.size()-1) << " " << *max_element(dp2.begin(), dp2.end()) << "\n";
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