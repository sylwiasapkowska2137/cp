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
	int n, m; cin >> n >> m;
	vector<int>a(n+1);
	vector<vector<int>>g(n+1);
	vector<pair<int, int>>edges;
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		edges.emplace_back(a, b);
	}
	if (m % 2 == 0){
		cout << "0\n";
		return;
	}
	vector<int>numer(n+1, -1);
	int curr = 0, all = 0;
	vector<int>inter(n+1);

	function<void(int)>dfs = [&](int v){
		numer[v] = curr;
		all += (int)g[v].size();
		for (auto x: g[v]){
			if (numer[x] == -1){
				dfs(x);
			}
		}
	};

	for (int i = 1; i<=n; i++){
		if (numer[i] == -1){
			all = 0;
			curr++;
			dfs(i);
			all/=2;
			if (all&1) inter[curr] = 1;
		}
	}

	int ans = oo;
	for (int i = 1; i<=n; i++){
		if (inter[i] && g[i].size() % 2 == 1){
			ans = min(ans, a[i]);
		}
	}
	for (auto [x, y]:edges){
		if (inter[numer[x]]){
			if (((int)g[x].size()-(int)g[y].size())%2 == 0){
				ans = min(ans, a[x]+a[y]);
			}
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}