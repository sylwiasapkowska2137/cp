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

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	int v = 1, d = 0, cnt = 1;
	vector<int>par(2), deg(2);
	for (int i = 1; i<=n; i++){
		while (d < a[i]){
			if ((int)par.size() <= cnt+1) {
				par.resize(cnt+2);
				deg.resize(cnt+2);
			}
			cnt++;
			par[cnt] = v;
			deg[v]++;
			v = cnt;
			d++;
		}
		v = par[v];
		d--;
		while (v && deg[v] != 1) {
			v = par[v];
			d--;
		}
	}
	int m = (int)par.size();
	vector<vector<int>>g(m+2);
	for (int i = 2; i<m; i++) {
		g[par[i]].emplace_back(i);
		if (!par[i]){
			cout << "NIE\n";
			return;
		}
	}
	for (int i = 1; i<m; i++){
		if (deg[i] != 0 && deg[i] != 2){
			cout << "NIE\n";
			return;
		}
	}
	string ans;
	function<void(int)> dfs = [&](int v){
		ans += '(';
		for (auto x: g[v]){
			dfs(x);
		}
		ans += ')';
	};

	dfs(1);
	for (int i = 1; i<m; i++) cout << par[i] << " ";
	cout << "\n" << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
