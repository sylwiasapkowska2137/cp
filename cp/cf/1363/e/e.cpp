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
	vector<vector<int>>g(n+1);
	vector<int>a(n+1), b(n+1), c(n+1);
	int X = 0, Y = 0;
	for (int i = 1; i<=n; i++){
		cin >> a[i] >> b[i] >> c[i];
		X += b[i];
		Y += c[i];
	}
	if (X != Y){
		cout << "-1\n";
		return;
	}
	for (int i = 1; i<n; i++){
		int x, y; cin >> x >> y;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}

	int ans = 0;
	function<pair<int, int>(int, int)>dfs = [&](int v, int pa){
		pair<int, int>t = {0, 0};
		if (b[v] != c[v]){
			if (b[v]) t.first++;
			else t.second++;
		}
		for (auto x: g[v]){
			if (x == pa) continue;
			a[x] = min(a[x], a[v]);
			pair<int, int>u = dfs(x, v);
			t.first += u.first;
			t.second += u.second;
		}
		int f = min(t.first, t.second);
		ans += 2 * f * a[v];
		t.first -= f;
		t.second -= f;
		return t;
	};

	dfs(1, 1);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}