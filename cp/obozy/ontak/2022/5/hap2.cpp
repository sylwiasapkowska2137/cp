//Sylwia Sapkowska
#include <bits/stdc++.h>
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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
const int oo = 1e18, K = 30;

struct e{
	int a, b, c;
	e(int _a = 0, int _b = 0, int _c = 0){
		a = _a, b = _b, c = _c;
	}
};

void solve(){
	int n, m, Q; cin >> n >> m >> Q;
	vector<vector<pair<int, int>>>g(n+1);
	vector<e>edges;
	int mm = 0;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		edges.emplace_back(a, b, c);
		mm = max(mm, c);
	}
	if (n <= 2000 && Q <= 2000 && mm == 1){
		while (Q--){
			int a, b; cin >> a >> b;
			set<pair<int, int>>s;
			vector<int>d(n+1, oo);
			d[a] = 0;
			vector<bool>vis(n+1, 0);
			s.insert({0, a});
			while (s.size()){
				int v = s.begin()->second;
				int dd = s.begin()->first;
				s.erase(s.begin());
				if (vis[v]) continue;
				vis[v] = 1;
				for (auto [x, c]:g[v]){
					if (dd+c < d[x]){
						d[x] = dd+c;
						s.insert({d[x], x});
					}
				}
			}
			if (d[b] == oo) cout << "-1\n";
			else cout << d[b] << "\n";
		}
		return;
	}
	vector<int>d(n+1, oo);
	set<pair<int, int>>s;
	s.insert({0, 1});
	d[1] = 0;
	while (s.size()){
		int v = s.begin()->second;
		int dist = s.begin()->first;
		s.erase(s.begin());
		if (d[v] < dist) continue;
		for (auto [x, c]:g[v]){
			if (dist+c < d[x]){
				d[x] = dist+c;
				s.insert({d[x], x});
			}
		}
	}
	for (int i = 1; i<=n; i++) g[i].clear();
	vector<vector<pair<int, int>>>G(n+1);
	vector<int>in(n+1);
	for (auto [a, b, c]:edges){
		if (d[a] + c == d[b] || d[b] + c == d[a]){
			G[a].emplace_back(b, c);
			G[b].emplace_back(a, c);
			g[a].emplace_back(b, c);
			in[b]++;
			// debug(a, b, c);
		}
	}
	queue<int>q;
	for (int i = 1; i<=n;i++) if (!in[i]) q.push(i);
	vector<int>pos(n+1), topo;
	while (q.size()){
		int v = q.front();q.pop();
		topo.emplace_back(v);
		pos[v] = (int)topo.size();
		for (auto [x, c]:g[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	// debug(topo);

	vector<vector<int>>up(n+1, vector<int>(K));
	vector<int>depth(n+1);

	function<void(int, int)>dfs = [&](int v, int pa){
		up[v][0] = pa;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto [x, c]:G[v]){
			if (x == pa) continue;
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	};

	dfs(1, 1);

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
	// debug(topo);
	// debug(pos);
	while (Q--){
		int a, b; cin >> a >> b;
		if (pos[a] > pos[b]) {
			cout << "-1\n";
			continue;
		}
		int l = lca(a, b);
		// debug(a, b, l);
		if (l == a)	cout << d[b]-d[a] << "\n";
		else cout << "-1\n";
	}

	dfs(1, 1);
	// debug(d);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
