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

struct que{
	int a, b, v;
	que(){}
	que(int _a, int _b, int _v){
		a = _a, b = _b, v = _v;
	}
};

struct DSU{
	int n;
	vector<int>sz, rep;

	DSU(int nn){
		n = nn;
		rep.assign(n+1, 0);
		sz.assign(n+1, 1);
		iota(rep.begin(), rep.end(), 0);
	}

	void clear(){
		sz.assign(n+1, 1);
		iota(rep.begin(), rep.end(), 0);
	}

	int f(int a){
		return a == rep[a] ? a : rep[a] = f(rep[a]);
	}

	void u(int a, int b){
		a = f(a);b = f(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		rep[b] = a;
		return;
	}

	bool sameset(int a, int b){
		return f(a) == f(b);
	}
};

void solve(){
	int n, k; cin >> n >> k;
	int N = n+n;
	vector a(2, vector<int>(n+1));
	vector<vector<int>>g(N+2);
	vector<que>b;
	for (int ck = 0; ck < 2; ck++){
		for (int i = 1; i<=n; i++){
			cin >> a[ck][i];
		}
	}	
	for (int ck = 0; ck < 2; ck++){
		for (int i = 1; i<=n; i++){
			g[a[ck][i]].emplace_back(a[ck^1][i]);
			g[a[ck][i]].emplace_back(a[ck][i == n ? 1 : i+1]);
			g[a[ck][i]].emplace_back(a[ck][i == 1 ? n : i-1]);
		}
	}
	vector<vector<pair<int, int>>>edges(N+2);
	for (int i = 1; i<=N; i++){
		debug(i, g[i]);
		for (auto x: g[i]){
			if (i < x) edges[i].emplace_back(i, x);
		}
		for (int j = 0; j<(int)g[i].size(); j++){
			for (int k = j+1; k<(int)g[i].size(); k++){
				b.emplace_back(g[i][j], g[i][k], i);
			}
		}
	}
	int m = (int)b.size();
	vector<int>L(m, 1), R(m, n);
	DSU dsu(N+1);
	// while (1){
	// 	bool any = 0;
	// 	for (int i = 0; i<m; i++){
	// 		if (R[i] - L[i] > 1){
	// 			any = 1;
	// 			break;
	// 		}
	// 	}
	// 	if (!any) break;
	// 	vector<vector<int>>at(N+1);
	// 	for (int i = 0; i<m; i++){
	// 		if (R[i] - L[i] > 1){
	// 			at[(L[i]+R[i])/2].emplace_back(i);
	// 		}
	// 	}
	// 	dsu.clear();
	// 	for (int i = N; i>=1; i--){
	// 		debug(i, edges[i]);
	// 		for (auto [x, y]:edges[i]){
	// 			dsu.u(x, y);
	// 		}
	// 		debug(at[i]);
	// 		for (auto idx: at[i]){
	// 			if (dsu.sameset(b[idx].a, b[idx].b)){
	// 				L[idx] = i;
	// 			} else {
	// 				R[idx] = i-1;
	// 			}
	// 		}
	// 	}
	// }
	// for (int i = 0; i<m; i++){
	// 	cerr << b[i].a << " " << b[i].b << " " << b[i].v << " " << R[i] << "\n";
	// }
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
