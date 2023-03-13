//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;
using namespace __gnu_pbds;

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
const int oo2 = 2e9+7, K = 30;
const int mod = 998244353;

typedef tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct F{
    int t, k, i;
    F(int _t = 0, int _k = 0, int _i = 0){
        t = _t, k = _k, i = _i;
    }
};

int sum(int x){
    return x*(x-1)/2;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int>a(n+1);
    for (int i = 1; i<=n; i++) cin >> a[i];
    vector<int>b(n+1);
    vector<vector<int>>g(n+1);
    for (int i = 1; i<n; i++){
        int x, y; cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    for (int v = 1; v <= n; v++){
        if (a[v]){
            for (auto x: g[v]){
                b[x]++;
            }
            b[v]++;
        }
    }
    b.swap(a);
    // debug(a);
    int q; cin >> q;
    vector<vector<F>>que(n+1);
    for (int i = 0; i<q; i++){
        int x, t, k; cin >> x >> t >> k;
        que[x].emplace_back(t, k, i);
    }
    vector<int>ans(q);
    ordered_set s;
    function<void(int, int)>dfs = [&](int v, int pa){
        s.insert(T{a[v], v});
        for (auto [t, k, idx]: que[v]){
            // debug(s);
            if ((int)s.size() >= t){
                auto kth = *s.find_by_order(t-1);
                //kth.first * x * (x-1)/2 >= k
                //x*(x-1) >= (2*k)/kth.first
                if (kth.first){
                    int l = 0, r = oo2;
                    while (r >= l){
                        int mid = (l+r)/2;
                        //check if sum * kth > m
                        if (sum(mid) > (m+kth.first-1)/kth.first) {
                            ans[idx] = mid;
                            r = mid-1;
                            continue;
                        }
                        if (sum(mid)*kth.first >= k){
                            ans[idx] = mid;
                            r = mid-1;
                        } else {
                            l = mid+1;
                        }
                    }   
                }
            }
        }
        for (auto x: g[v]){
            if (x == pa) continue;
            dfs(x, v);
        }
        s.erase(T{a[v], v});
    };
    dfs(1, 1);
    for (int i = 0; i<q; i++) cout << ans[i]-1 << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}