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
typedef long long ll;
typedef tuple<ll, int, int> F;
const long long oo = 1e18;
const int mx = 2e3+7;
int in[mx], pos[mx];
vector<T>g[mx];

void ckmin(ll &a, ll b){
    a = min(a, b);
}

void solve(){
    int n, m; cin >> n >> m;
    vector<T>costs;
    vector dist(n+1, vector<ll>(n+1, oo));
    for (int i = 0; i<m; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        g[a].emplace_back(b, i);
        costs.emplace_back(c, d);
        in[b]++;
    }
    queue<int>q;
    for (int i = 1; i<=n; i++) if (!in[i]) q.push(i);
    vector<int>topo;
    while (q.size()){
        int v = q.front();q.pop();
        topo.emplace_back(v);
        pos[v] = (int)topo.size()-1;
        for (auto &[x, i]: g[v]){
            if ((--in[x]) == 0){
                q.push(x);
            }
        }
    }
    for (int i = 1; i<=n; i++){
        stable_sort(g[i].begin(), g[i].end(), [&](auto x, auto y){
            return pos[x.first] < pos[y.first];
        });
    }
    dist[1][1] = 0;
    for (int k = 0; k<n; k++){
        for (int l = k; l<n; l++){
            int v1 = topo[k], v2 = topo[l];
            if (dist[v1][v2] == oo) continue;
            if (v1 == v2){
                for (int rep = 0; rep < (int)g[v1].size(); rep++){
                    auto &[x1, i] = g[v1][rep];
                    ckmin(dist[x1][x1], dist[v1][v1] + costs[i].first + costs[i].second);
                    for (int rep2 = rep+1; rep2 < (int)g[v1].size(); rep2++){
                        auto &[x2, i2] = g[v1][rep2];
                        ckmin(dist[x1][x2], dist[v1][v1] + costs[i].first + costs[i2].first);
                    }
                }
            } else {
                for (auto &[x, i]: g[v1]){
                    if (pos[v2] <= pos[x]) ckmin(dist[v2][x], dist[v1][v2] + costs[i].first);
                    else ckmin(dist[x][v2], dist[v1][v2] + costs[i].first);
                }
            }
        }
    }
    cout << dist[n][n] << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}