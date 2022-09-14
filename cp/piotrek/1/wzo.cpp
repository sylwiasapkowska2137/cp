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

void solve(){
	int n, m; cin >> n >> m;
	vector<int>cnt(n+m+1);
	vector<vector<bool>>good(n+2, vector<bool>(m+2));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cnt[i+j]++;
			good[i][j] = 1;
		}
	}
	function<void(int, int, int)>dfs = [&](int x, int y, int f){
		if (x < 1 || y < 1 || x > n || y > m) return;
		if (!good[x][y]) return;
		if (good[x+f][y] || good[x][y+f]) return;
		good[x][y] = 0;
		cnt[x+y]--;
		dfs(x-f, y, f);
		dfs(x, y-f, f);
	};

	auto update = [&](int x, int y){
		if (!good[x][y]) return 1;
		if (cnt[x+y] == 1) return 0;
		good[x][y] = 0;
		cnt[x+y]--;
		for (int f: {-1, 1}){
			dfs(x-f, y, f);
			dfs(x, y-f, f);
		}
		return 1;
	};
	
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			int c; cin >> c;
			if (c) update(i, j);
		}
	}
	int q; cin >> q;
	while (q--){
		int x, y; cin >> x >> y;
		cout << update(x, y) << "\n";
	}
	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
