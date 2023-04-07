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
const int oo = 1e18;

void solve(){
    int n, m; cin >> n >> m;
    vector<int>a(m+1), mask(n+1);
    for (int i = 1; i<=n; i++){
        for (int j = m-1; j>=0; j--){
            int k; cin >> k;
            if (k == 1){
                mask[i] += (1<<j);
                a[j]++;
            }
        }
    }
    vector<vector<T>>g((1<<m)+1);
    for (int mask = 0; mask<(1<<m); mask++){
        for (int i = 0; i<m; i++){
            if (mask&(1<<i)){
                //zgaszony --> zapalony kosztem 1
                g[mask^(1<<i)].emplace_back(mask, 1);
                // cerr << mask << " " << (mask^(1<<i)) << " " << 0 << "\n";
            } else {
                //zapalony --> zgaszony kosztem 0
                g[mask^(1<<i)].emplace_back(mask, 0);
                // cerr << mask << " " << (mask^(1<<i)) << " " << 1 << "\n";
            }
        }
    }
    deque<int>q;
    vector dist((1<<m), oo);
    for (int i = 1; i<=n; i++){
        q.push_back(mask[i]);
        dist[mask[i]] = 0;
    }
    while (q.size()){
        int v = q.front(); q.pop_front();
        for (auto [x, c]: g[v]){
            if (dist[x] > dist[v]+c){
                dist[x] = dist[v] + c;
                // debug(x, v, dist[v], dist[x]);
                if (c == 0) q.push_front(x);
                else q.push_back(x);
            }
        }
    }
    debug(mask);
    debug(dist);
    
    for (int i = 1; i<=n; i++){
        int nmask = 0, all = 0;
        for (int j = 0; j<m; j++){
            int curr = a[j];
            if (mask[i]&(1<<j)){
                curr--;
            }
            // debug(j, curr);
            if (curr > n/2) all++;  
            if (curr != n/2) nmask += (1<<j);
        }
            
        cout << all-dist[nmask] << "\n";
        debug(all, nmask, dist[nmask]);
        // cout <<  << "\n";
        // return;
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