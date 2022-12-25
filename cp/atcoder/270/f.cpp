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

struct FAU{
	vector<int>rep, sz;

	FAU(int n){
		rep.assign(n+1, 0);
		iota(rep.begin(), rep.end(), 0);
		sz.assign(n+1, 1);
	}

	int f(int a){return a == rep[a] ? a : rep[a] = f(rep[a]);}
	bool u(int a, int b){
		a = f(a); b = f(b);
		if (a == b) return 0;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		rep[b] = a;
		return 1;
	}
};

struct T{
	int a, b, c;
	T(){}
	T(int _a, int _b, int _c){
		a = _a, b = _b, c = _c;
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vector<T>edges;
	for (int rep = 1; rep <= 2; rep++){
		for (int i = 1; i<=n; i++){
			int x; cin >> x;
			edges.emplace_back(i, n+rep, x);
		}
	}
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		edges.emplace_back(a, b, c);
	}
	sort(edges.begin(), edges.end(), [&](auto x, auto y){return x.c < y.c;});
	int ans = oo;
	for (int rep1 = 0; rep1 < 2; rep1++){
		for (int rep2 = 0; rep2 < 2; rep2++){
			int curr = 0;
			FAU dsu(n+3);
			for (auto [a, b, c]:edges){
				if (rep1 && b == n+1) continue;
				if (rep2 && b == n+2) continue;
				if (dsu.u(a, b)) curr += c;
			}
			// debug(curr);
			for (int i = 1; i<=n; i++) {
				if (dsu.sz[i] >= n){
					ans = min(ans, curr);
				}
			}
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
