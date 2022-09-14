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
	vector<tuple<int, int, int>>edges;
	vector<vector<pair<int, int>>>g(n+1);
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		edges.emplace_back(a, b, c);
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	int q; cin >> q;
	vector<int>ans(q, 2);
	vector<pair<int, int>>Q(q);
	for (int i = 0; i<q; i++){
		cin >> Q[i].first >> Q[i].second;
	}
	// vector<vector<int>>can(n+1, vector<int>(K));
	for (int i = 0; i<K; i++){
		vector<int>rep(n+1), sz(n+1, 1);
		iota(rep.begin(), rep.end(), 0);
		function<int(int)>f = [&](int a){return rep[a] == a ? a : rep[a] = f(rep[a]);};
		function<void(int, int)>u = [&](int a, int b){
			a = f(a); b = f(b);
			if (a == b) return;
			if (sz[a] < sz[b]) swap(a, b);
			sz[a] += sz[b];
			rep[b] = a;
		};
		auto sameset = [&](int a, int b){
			return f(a) == f(b);
		};

		for (auto [a, b, c]:edges){
			if (c&(1<<i)){
				u(a, b);
			}
		}
		for (int j = 0; j<q; j++){
			if (sameset(Q[j].first, Q[j].second)) {
				ans[j] = 0;
			}
		}
		if (i == 0) continue;
		vector<int>can(n+1);
		for (auto [a, b, c]:edges){
			if (c % 2 == 0){
				can[f(a)] = 1;
				can[f(b)] = 1;
			}
		}
		for (int j = 0; j<q; j++){
			if (ans[j] != 2) continue;
			auto [a, b] = Q[j];
			if (can[f(a)])	ans[j] = 1;
		}
	}
	for (int i = 0; i<q; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}