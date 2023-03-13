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
ll dist[mx][mx];

void solve(){
    int n, m; cin >> n >> m;
    vector<T>costs;
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            dist[i][j] = oo;
        }
    }
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
    priority_queue<F, vector<F>, greater<F>>s;
    dist[1][1] = 0;
    s.push({0, 0, 0});
    while (s.size()){
        auto [d, v1, v2] = s.top();
        v1 = topo[v1], v2 = topo[v2];
        s.pop();
        if (dist[v1][v2] < d) continue;
        if (v1 == v2){
            for (int rep = 0; rep < (int)g[v1].size(); rep++){
                auto &[x1, i] = g[v1][rep];
                ll C = dist[v1][v1] + costs[i].first + costs[i].second;
                if (dist[x1][x1] > C){
                    dist[x1][x1] = C;
                    s.push({C, pos[x1], pos[x1]});
                }
                for (int rep2 = rep+1; rep2 < (int)g[v1].size(); rep2++){
                    auto &[x2, i2] = g[v1][rep2];
                    C = dist[v1][v1] + costs[i].first + costs[i2].first;
                    if (dist[x1][x2] > C){
                        dist[x1][x2] = C;dist[x2][x1] = C;
                        s.push({C, pos[x1], pos[x2]});
                    }
                }
            }
        } else {
            if (pos[v1] > pos[v2]) swap(v1, v2);
            for (auto &[x, i]: g[v1]){
                ll C = dist[v1][v2] + costs[i].first;
                if (dist[x][v2] > C){
                    dist[x][v2] = C;dist[v2][x] = C;
                    s.push({C, pos[x], pos[v2]});
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