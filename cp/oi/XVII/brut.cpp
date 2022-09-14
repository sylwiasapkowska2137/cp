#include<bits/stdc++.h>
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

const int MAX = 1007, INF = 1e9+7;
vector<int>deg;
vector<pair<int, int>> graf[MAX];

struct Edge{
    int a, b, c, d;
    void read(){
        cin >> a >> b >> c >> d;
        deg[a]++;
        deg[b]++;
    }
};

vector<int> eulerian(){
    stack<pair<int, int>> s;
    int curr = 1, idx = -1;
    vector<int> ans;
    s.push({curr, -1});
    while (!s.empty()){
        if ((int)graf[curr].size() > 0){
            s.push({curr, idx});
            int nextv = graf[curr].back().first;
            int nexti = graf[curr].back().second;
            graf[curr].pop_back();
            curr = nextv;
            idx = nexti;
        } else {
            ans.push_back(idx);
            //{curr, idx} = s.top();
            curr = s.top().first;
            idx = s.top().second;
            s.pop();
        }
    }
    return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    deg.assign(n+1, 0);
    vector<Edge>edges(m);
    for (int i = 0; i<m; i++){
        edges[i].read();
    }
    for (int i = 1; i<=n; i++){
        if (deg[i]&1){
            cout << "NIE\n";
            return;
        }
    }
    vector<int>out;
    int ans = INF;
    for (long long mask = 0; mask<(1LL<<m); mask++){
        for (int i = 1; i<=n; i++) graf[i].clear();
        vector<int>degin(n+1, 0), degout(n+1, 0);
        int curr = 0;
        for (int i = 0; i<m; i++){
            int a = edges[i].a;
            int b = edges[i].b;
            if (mask&(1<<i)){
                graf[a].push_back({b, i});
                degin[b]++;
                degout[a]++;
                curr = max(curr, edges[i].c);
            } else {
                graf[b].push_back({a, i});
                degin[a]++;
                degout[b]++;
                curr = max(curr, edges[i].d);
            }
        }
        //debug(degin, degout);
        bool ok = 1;
        for (int i = 1; i<=n; i++){
            if (degin[i] != degout[i]){
                ok = 0;
            }
        }
        if (!ok) continue;
       
        vector<int>tmp = eulerian();
        //debug(mask, tmp.size());
        if ((int)tmp.size() == m+1 && ans > curr){
            tmp.pop_back();
            reverse(tmp.begin(), tmp.end());
            ans = curr;
            out = tmp;
        }
    }
    if (ans == INF){
        cout << "NIE\n";
        return;
    }
    cout << ans << "\n";
    for (auto x: out) cout << x+1 << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();

    return 0;
}