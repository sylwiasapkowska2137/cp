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
const int oo = 1e9, K = 30;

void solve(){
	int n, m, q; cin >> n >> m >> q;
	vector<tuple<int, int, int>>edges;
	for (int i = 0; i<m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges.emplace_back(a, b, c);
	}
	vector<pair<int, int>>Q;
	for (int i = 0; i<q; i++){
		int a, b; cin >> a >> b;
		Q.emplace_back(a, b);
	}
	vector<int>L(q, 1), R(q, oo), ans(q, oo);
	while (1){
		bool any = 0;
		map<int, vector<pair<int, int>>>event;
		for (auto [a, b, c]:edges) event[c].emplace_back(a, b);
		for (int i = 0; i<q; i++){
			if (R[i] >= L[i]){
				int mid = (L[i]+R[i])/2;
				any = 1;
				event[mid].emplace_back(i, 0);
			}
		}
		if (!any) break;

		vector<int>rep(n+1), sz(n+1, 1);
		iota(rep.begin(), rep.end(), 0);
		function<int(int)>f = [&](int a){return a = rep[a] ? a : rep[a] = f(rep[a]);};
		function<bool(int, int)>u = [&](int a, int b){
			a = f(a); b = f(b);
			if (a == b) return 0;
			if (sz[a] < sz[b]) swap(a, b);
			sz[a] += sz[b];
			rep[b] = a;
			return 1;
		};
		function<bool(int, int)>sameset = [&](int a, int b){return f(a) == f(b);};
		
		vector<int>ok(q, -1);
		for (auto x: event){
			for (auto [a, b]: x.second){
				if (b){
					if (!u(a, b)){
						
					}
				} else {
					if (!sameset(Q[a].first, Q[a].second)){
						ok[a] = 0;
					}
				}
			}
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
