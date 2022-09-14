#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int MAX = 1007, NAX = 3007;
const int INF = 1e9+7;
vector<pair<int, int>>graf[MAX];
map<pair<int, int>, int>mapa;
int cap[NAX][NAX];
vector<int>fgraf[NAX], deg, cycle[MAX];
vector<pair<int, int>>curr;
int n, m;

struct Edge{
    int a, b, c, d, i; 
    Edge(){}
    Edge(int _a, int _b, int _c, int _d, int _i){
        a = _a, b = _b, c = _c, d = _d, i = _i;
    }
};

vector<Edge>edges;

void eulerian(){
    stack<int>s;
    int curr = 1;
    vector<int> ans;
    s.push(curr);
    while (!s.empty()){
        if (cycle[curr].size()){
            s.push(curr);
            int nextv = cycle[curr].back();
            cycle[curr].pop_back();
            curr = nextv;
        } else {
            ans.push_back(curr);
            curr = s.top();
            s.pop();
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 1; i<(int)ans.size(); i++){
        cout << mapa[{ans[i], ans[i-1]}] << " ";
    }
    cout << "\n";
}


int bfs(int s, int t, vector<int>&parent){
    parent.assign(NAX, -1);
    parent[s] = -2;
    queue<pair<int, int>>q;
    q.push({s, INF});
    while (!q.empty()){
        int v = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (auto x: fgraf[v]){
            if (parent[x] == -1 && cap[v][x]){
                parent[x] = v;
                int new_flow = min(flow, cap[v][x]);
                if (x == t) return new_flow;
                q.push({x, new_flow});
            }
        }
    }
    return 0;
}

int findflow(int mid){
    for (int i = 0; i<NAX; i++) fgraf[i].clear();
    curr.clear();
    memset(cap, 0, sizeof(cap));
    for (auto [a, b, c, d, i]: edges) {
        if (!i) continue;
        if (c > mid && d > mid) return -1;
        if (c <= mid){
            fgraf[a].push_back(i+n);
            fgraf[i+n].push_back(a);
            //debug(a, i+n, 1);
            cap[a][i+n] = 1;
        }
        if (d <= mid){
            fgraf[b].push_back(i+n);
            fgraf[i+n].push_back(b);
            //debug(b, i+n, 1);
            cap[b][i+n] = 1;
        }
        if (c <= mid && d <= mid){
            curr.push_back({a, i+n});
            curr.push_back({b, i+n});
        }
    }
    for (int i = 1; i<=n; i++) {
        fgraf[0].push_back(i);
        fgraf[i].push_back(0);
        //debug(0, i, fgraf[i].size());
        cap[0][i] = deg[i]/2;
    }
    for (int i = 1; i<=m; i++){
        fgraf[i+n].push_back(NAX-1);
        fgraf[NAX-1].push_back(i+n);
        //debug(i+n, NAX-1, 1);
        cap[i+n][NAX-1] = 1;
    }
    int flow = 0;
    vector<int> parent;
    while (1){
        int newflow = bfs(0, NAX-1, parent);
        if (!newflow) break;
        flow += newflow;
        int curr = NAX-1;
        while (curr){
            int prev = parent[curr];
            cap[prev][curr] -= newflow;
            cap[curr][prev] += newflow;
            curr = prev;
        }
    }
    return flow;
}

void solve(){
    cin >> n >> m;
    deg.assign(n+1, 0);
    edges.emplace_back(0, 0, 0, 0, 0);
    int R = 0;
    for (int i = 1; i<=m; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        graf[a].push_back({b, c});
        graf[b].push_back({a, d});
        deg[a]++; deg[b]++;
        mapa[{a, b}] = i;
        mapa[{b, a}] = i;
        edges.emplace_back(a, b, c, d, i);
        R = max(R, max(c, d));
    }
    for (int i = 1; i<=n; i++){
        if (deg[i]&1){
            cout << "NIE\n";
            return;
        }
    }
    int L = 1, ans = (1<<10);
    while (R>=L){
        int mid = (L+R)/2;
        if (findflow(mid) == m){
            ans = mid;
            R = mid-1;
        } else L = mid+1;
    }
    sort(curr.begin(), curr.end());
    cout << ans << "\n";
    findflow(ans);
    for (auto [a, b, c, d, i]: edges){
        if (c <= ans && d <= ans){
            if (cap[a][i+n] == 0) cycle[a].push_back(b);
            else cycle[b].push_back(a);
        } else {
            if (c <= ans) cycle[a].push_back(b);
            if (d <= ans) cycle[b].push_back(a);
        }
    }
    /*
    for (int v = 1; v<=n; v++){
        for (auto x: cycle[v]){
            debug(v, x);
        }
    }
    */
    eulerian();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}