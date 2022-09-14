//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
	return a+rng()%(b-a+1);
}

void solve(){
	int n = p(1, 3);
	int q = p(1, 10);
	cout << n << " " << q << "\n";
	for (int i = 0; i<n; i++) cout << p(1, 10) << " ";
	cout << "\n";
	while (q--){
		int t = p(0, 3);
		cout << t << " ";
		if (t){
			int l = p(1, n);
			int r = p(1, n);
			if (l > r) swap(l, r);
			cout << l << " " << r << " " << p(1, 10) << "\n";
		} else {
			int l = p(1, n);
			int r = p(1, n);
			if (l > r) swap(l, r);
			cout << l << " " << r << " ";
			l = p(1, n);
			r = p(1, n);
			if (l > r) swap(l, r);
			cout << l << " " << r << endl;
		}
	}
}

void solve2(){
	int n = p(2, 5);
	int m = p(1, 5);
	cout << n << " " << m << endl;
	set<pair<int, int>>s;
	while (s.size() < n+m){
		int x = p(1, 10);
		int y = p(1, 10);
		s.insert({x, y});
	}
	vector<pair<int, int>>p;
	for (auto [x, y]:s){
		p.emplace_back(x, y);
	}
	shuffle(p.begin(), p.end(), rng);
	for (auto [x, y]:p) cout << x << " " << y << "\n";
}

void solve3(){
	int n = p(1, 10);
	int m = p(n-1, n+5);
	int q = p(1, 1);
	cout << n << " " << m << " " << q << "\n";
	vector<vector<int>>g(n+1);
	for (int i = 2; i<=n; i++){
		int a = i;
		int b = p(1, a-1);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	vector<int>par(n+1);
	function<void(int, int)> dfs = [&](int v, int pa){
		par[v] = pa;
		for (auto x: g[v]){
			if (x == pa) continue;
			dfs(x, v);
		}
	};

	dfs(1, 1);
	for (int i = 2; i<=n; i++){
		cout << par[i] << " " << i << " " << 1 << "\n";
	}
	for (int i = n-1; i<m; i++){
		cout << p(1, n) << " " << p(1, n) << " " << 1 << "\n";
	}
	while (q--){
		cout << p(1, n) << " " << p(1, n) << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve3();
	
	return 0;
}
