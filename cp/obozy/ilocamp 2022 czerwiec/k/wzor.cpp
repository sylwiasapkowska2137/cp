//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

#define int long long
const int oo = 1e18, K = 20;

void solve(){
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	vector<int>pre(n+1), depth(n+1);
	vector<vector<int>>up(n+1, vector<int>(K, 1));
	int czas = 0;

	function<void(int, int)>dfs = [&](int v, int pa){
		pre[v] = ++czas;
		up[v][0] = pa;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto x:g[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	};

	function<int(int, int)>lca = [&](int a, int b){
		if (depth[a] < depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[a]-(1<<i)>=depth[b]){
				a = up[a][i];
			}
		}
		if (a == b) return a;
		for (int i = K-1; i>=0; i--){
			if (up[a][i] != up[b][i]){
				a = up[a][i];
				b = up[b][i];
			}
		}
		return up[a][0];
	};

	dfs(1, 1);

	int q; cin >> q;
	while (q--){
		int k; cin >> k;
		vector<int>v(k), V;
        set<int>good;
		for (int i = 0; i<k; i++) cin >> v[i];
        V = v;
		sort(v.begin(), v.end(), [&](auto a, auto b){return pre[a] < pre[b];});
        for (int i = 0; i<k; i++){
            int p = (i == 0?k-1:i-1);
            v.emplace_back(lca(v[p], v[i]));
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        map<int, int>mapa;
        int s = (int)v.size();
        for (int i = 0; i<s; i++) mapa[v[i]] = i+1;
        for (auto x: V) good.insert(mapa[x]);
        sort(v.begin(), v.end(), [&](auto a, auto b){return pre[a] < pre[b];});
        vector<vector<int>>G(s+1);
        vector<pair<int, int>>edges;
        for (int i = 0; i<s; i++){
            int p = (i == 0?s-1:i-1);
            int x = lca(v[p], v[i]);
            if (x == v[i]) continue;
            G[mapa[x]].emplace_back(mapa[v[i]]);
            G[mapa[v[i]]].emplace_back(mapa[x]);
            edges.emplace_back(x, v[i]);
        }
        vector<int>sub(s+1);
        function<void(int, int)>dfs2 = [&](int vv, int pa){
            if (good.find(vv) != good.end()) sub[vv] = 1;
            for (auto x: G[vv]){
                if (x == pa) continue;
                dfs2(x, vv);
                sub[vv] += sub[x];
            }
        };

        dfs2(1, 1);
        int ans = 0;
        for (auto [a, b]:edges){
            ans += sub[mapa[b]]*(k-sub[mapa[b]])*(depth[b]-depth[a]);
        }
        cout << ans << "\n";
    }
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
