//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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

void solve(){
	int n; cin >> n;
	vector<int>cnt(n+1, 0);
	vector<vector<int>>g(n+1);
	bool ok = 1;
	for (int i = 0; i<n; i++){
		int a, b; cin >> a >> b;
		cnt[a]++;cnt[b]++;
		if (a == b){
			ok = 0;
		}
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	if (!ok || *max_element(cnt.begin(), cnt.end()) > 2){
		cout << "NO\n";
		return;
	}
	vector<int>color(n+1);
	vector<bool>vis(n+1);
	function<void(int, int)>dfs = [&](int v, int c){
		vis[v] = 1;
		color[v] = c;
		for (auto x: g[v]){
			if (vis[x]) {
				if (color[v] == color[x]){
					ok = 0;
				}
				continue;
			}
			dfs(x, (c^1));
		}
	};

	
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			dfs(i, 0);
		}
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}