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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

struct T{
	int to, c, idx;
	T(){}
	T(int _to, int _c, int _idx):to(_to), c(_c), idx(_idx){}
	bool operator <(const T &he){
		return c < he.c;
	}
};

struct E{
	int a, b, c;
	E(){}
	E(int _a, int _b, int _c): a(_a), b(_b), c(_c){}
};

void solve(){
	int n, m, k; cin >> n >> m >> k;
	
	vector<E>edges;
	map<pair<int, int>, vector<pair<int, int>>>cnt;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		edges.emplace_back(a, b, c);
		if (a > b) swap(a, b);
		cnt[{a, b}].emplace_back(c, i);
	}
	for (auto &x: cnt) sort(x.second.begin(), x.second.end());
	for (auto x: cnt){
		debug(x.first, x.second);
	}
	vector<int>vis(m), ans(m);
	for (int curr = 1; curr <= k; curr++){
		vector<vector<int>>g(n+1, vector<int>(n+1));
		debug(curr);
		for (int i = 0; i<m; i++){
			if (!vis[i]){
				auto [a, b, c] = edges[i];
				g[a][b] = max(g[a][b], c);
				g[b][a] = max(g[b][a], c);
				debug(a, b, c);
			}
		}
		vector<bool>used(n+1);
		vector<pair<int, int>>mn(n+1, {-oo, -1});
		mn[1].first = 0;
		for (int i = 1; i<=n; i++){
			int v = -1;
			for (int j = 1; j<=n; j++){
				if (!used[j] && (v == -1 || mn[j].first > mn[v].first)){
					v = j;
				}
			}
			if (v == -1) break;
			used[v] = 1;
			if (mn[v].second != -1){
				int a = v, b = mn[v].second;
				if (a > b) swap(a, b);
				int idx = cnt[{a, b}].back().second;
				ans[idx] = curr;
				vis[idx] = 1;
				cnt[{a, b}].pop_back();
			
				debug(v, mn[v].second);
			}
			for (int to = 1; to <= n; to++){
				if (g[v][to] > mn[to].first){
					mn[to] = {g[v][to], v};
				}
			}
		}
		// break;
	}
	for (int i = 0; i<m; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
