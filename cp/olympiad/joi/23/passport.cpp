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
const int oo = 1e9+7;

struct TreeMin{
    vector<T>tab;
    int size = 1;

    TreeMin(int n, vector<int>&a){
        while (size < n) size*=2;
        tab.assign(2*size, {oo, oo});
        for (int i = 1; i<(int)a.size(); i++) tab[i+size] = {a[i], i};
        for (int i = size-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
    }
    
    T query(int l, int r){
        T ans = {oo, oo};
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = min(ans, tab[l+1]);
            if (r&1) ans = min(ans, tab[r-1]);
        }
        return ans;
    }

    void update(int x, int v){
        x += size;
        tab[x].first = v;
        while (x){
            x/=2;
            tab[x] = min(tab[2*x], tab[2*x+1]);
        }
    }
};

struct TreeMax{
    vector<T>tab;
    int size = 1;

    TreeMax(int n, vector<int>&a){
        while (size < n) size*=2;
        tab.assign(2*size, {-oo, -oo});
        for (int i = 1; i<(int)a.size(); i++) tab[i+size] = {a[i], i};
        for (int i = size-1; i>=1; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
    }
    
    T query(int l, int r){
        T ans = {-oo, -oo};
        for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
            if (!(l&1)) ans = max(ans, tab[l+1]);
            if (r&1) ans = max(ans, tab[r-1]);
        }
        return ans;
    }

    void update(int x, int v){
        x += size;
        tab[x].first = v;
        while (x){
            x/=2;
            tab[x] = max(tab[2*x], tab[2*x+1]);
        }
    }
};

void solve(){
    int n; cin >> n;
    vector<int>L(n+1), R(n+1);
    for (int i = 1; i<=n; i++){
        cin >> L[i] >> R[i];
    }
    TreeMin tmin(n+2, L);
    TreeMax tmax(n+2, R);
    int que; cin >> que;
    if (que == 1){
        int v; cin >> v;
        if (v == 1){
            vector<int>dp(n+1, oo);
            queue<int>q;
            dp[R[1]] = 1;
            q.push(R[1]);
            while (q.size()){
                int r = q.front();q.pop();
                T now = tmax.query(1, r);
                if (now.first <= r) {
                    //:(
                } else {
                    if (dp[now.first] == oo){
                        dp[now.first] = dp[r]+1;
                        q.push(now.first);
                    }
                }
            }
            debug(dp);
            if (dp[n] == oo) cout << "-1\n";
            else cout << dp[n] << "\n";
            return;
        }
    }
    while (que--){
        int v; cin >> v;
        vector dp(n+1, vector<int>(n+1, oo));
        dp[L[v]][R[v]] = 1;
        queue<T>q;
        q.push({L[v], R[v]});
        bool done = 0;
        while (q.size()){
            T now = q.front(); q.pop();
            vector<int>valid;
            while (1){
                T curr = tmin.query(now.first, now.second);
                if (curr.first >= now.first) break;
                int j = curr.second;
                valid.emplace_back(j);
                tmin.update(j, oo);
                T tmp = {min(L[j], now.first), max(R[j], now.second)};
                if (dp[tmp.first][tmp.second] == oo){
                    dp[tmp.first][tmp.second] = dp[now.first][now.second]+1;
                    q.push(tmp);
                    if (tmp == make_pair(1, n)) {
                        done = 1;
                        break;
                    }
                }
            }
            for (auto x: valid) tmin.update(x, L[x]);
            valid.clear();
            while (1){
                T curr = tmax.query(now.first, now.second);
                if (curr.first <= now.second) break;
                int j = curr.second;
                valid.emplace_back(j);
                tmax.update(j, -oo);
                T tmp = {min(L[j], now.first), max(R[j], now.second)};
                if (dp[tmp.first][tmp.second] == oo){
                    dp[tmp.first][tmp.second] = dp[now.first][now.second]+1;
                    q.push(tmp);
                    if (tmp == make_pair(1, n)) {
                        done = 1;
                        break;
                    }
                }
            }
            for (auto x: valid) tmax.update(x, R[x]);
            if (done) break;
        }
        int ans = dp[1][n];
        if (dp[1][n] == oo) ans = -1;
        cout << ans << "\n";
    }
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