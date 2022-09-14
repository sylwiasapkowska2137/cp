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
	vector<int>rep(n+1), sz(n+1, 1);
	iota(rep.begin(), rep.end(), 0);
	function<int(int)>f = [&](int a){return rep[a] == a ? a : rep[a] = f(rep[a]);};
	function<void(int, int)>Union = [&](int a, int b){
		a = f(a); b = f(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		rep[b] = a;
	};
	set<pair<int, int>>s;
	for (int i = 0; i<m; i++){
		int x, y; cin >> x >> y;
		s.insert({x, y});
		while (1){
			bool any = 0;
			set<pair<int, int>>tmp;
			for (auto [a, b]:s) tmp.insert({f(a), f(b)});
			for (auto [a, b]:tmp){
				if (a < b && tmp.find({b, a}) != tmp.end()){
					// debug(a, b);
					Union(a, b);
					any = 1;
				}
			}
			if (!any) break;
		}
		// debug(s, rep);
		set<pair<int, int>>tmp3;
		for (auto [a, b]:s) if (f(a) != f(b)) tmp3.emplace(a, f(b));
		int ans = 0;
		for (auto [a, b]:tmp3) ans += sz[f(b)];
		for (int v = 1; v<=n; v++){
			if (v == f(v)){
				ans += sz[v]*(sz[v]-1);
			}
		}
		cout << ans << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
