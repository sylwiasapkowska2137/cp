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

int dist(pair<int, int>x, pair<int, int>y){
	int a = x.first-y.first;
	int b = x.second-y.second;
	// debug(x, y, a, b);
	return a*a+b*b;
}

void solve(){
	int n; cin >> n;
	int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
	vector<int>x(n), y(n), r(n);
	for (int i = 0; i<n; i++){
		cin >> x[i] >> y[i] >> r[i];
	}
	vector<vector<int>>g(n+1);
	int start = 0;
	for (int i = 0; i<n; i++){
		if (dist({x[i], y[i]}, {sx, sy}) == r[i]*r[i]){
			start = i;
		}
	}
	int koniec = 0;
	for (int i = 0; i<n; i++){
		if (dist({x[i], y[i]}, {tx, ty}) == r[i]*r[i]){
			koniec = i;
		}
	}
	// debug(start, koniec);
	for (int i = 0; i<n; i++){
		for (int j = i+1; j<n; j++){
			if (dist({x[i], y[i]}, {x[j], y[j]}) <= (r[i]+r[j])*(r[i]+r[j])){
				long double X = sqrt(dist({x[i], y[i]}, {x[j], y[j]}));
				int a = min(r[i], r[j]);
				int b = max(r[i], r[j]);
				if (X + a < b) continue;
				// debug(X, a, b);
				// debug(i, j);
				g[i].emplace_back(j);
				g[j].emplace_back(i);
			}		
		}
	}
	vector<bool>vis(n+1);

	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		for (auto x: g[v]){
			if (!vis[x]){
				dfs(x);
			}
		}
	};

	dfs(start);
	if (vis[koniec]) cout << "Yes\n";
	else cout << "No\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
