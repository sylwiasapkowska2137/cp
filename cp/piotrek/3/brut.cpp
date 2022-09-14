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

vector<vector<int>>all;

void rec(vector<int>a, int n, int k){
	if (a.size() == n){
		all.emplace_back(a);
		return;
	}
	for (int i = 1; i<=k; i++){
		a.push_back(i);
		rec(a, n, k);
		a.pop_back();
	}
}

void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) 	cin >> a[i];
	vector<vector<int>>g(n+1);
	vector<pair<int, int>>edges;
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		edges.emplace_back(a, b);
	}
	int ans = oo;
	rec({0}, k+1, k);
	
	vector<int>par(n+1), c(n+1);
	vector<int>cnt(k+1);
	function<void(int, int)>dfs = [&](int v, int pa){
		par[v] = pa;
		cnt[c[v]]++;
		for (auto x: g[v]){
			if (x == pa) continue;
			dfs(x, v);
		}
	};
	// debug((int)all.size());
	
	for (auto x: all){
		vector<int>t(k+1);
		for (int i = 1; i<=n; i++) {
			c[i] = x[a[i]];
			t[c[i]]++;
		}
		bool ok2 = 1;
		for (auto [a, b]:edges){
			bool ok = 1;
			cnt.assign(k+1, 0);
			dfs(a, b);
			for (int i = 1; i<=k; i++){
				if (cnt[i]){
					ok &= (cnt[i] == t[i]);
				}
			}
			cnt.assign(k+1, 0);
			dfs(b, a);
			for (int i = 1; i<=k; i++){
				if (cnt[i]){
					ok &= (cnt[i] == t[i]);
				}
			}
			if (ok){
				ok2 = 0;
				break;
			}
		}
		if (ok2){
			int tmp = 0;
			for (int i = 1; i<=k; i++){
				if (x[i] != i){
					tmp++;
				}
			}
			ans = min(ans, tmp);
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
