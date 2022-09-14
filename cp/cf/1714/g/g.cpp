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
const int oo = 1e18, K = 20;

struct edge{
	int x, a, b;
	edge(){}
	edge(int _x, int _a, int _b){
		x = _x, a = _a, b = _b;
	}
};

void solve(){
	int n; cin >> n;
	vector<vector<edge>>g(n+1);
	for (int i = 2; i<=n; i++){
		int p, a, b;
		cin >> p >> a >> b;
		g[p].emplace_back(i, a, b);
		// g[y].emplace_back(x, a, b);
	}

	vector<int>depth(n+1);
	vector<int>A(n+1), B(n+1);
	vector<vector<int>>up(n+1, vector<int>(K));

	function<void(int, int)>dfs = [&](int v, int pa){
		up[v][0] = pa;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
		for (auto [x, a, b]:g[v]){
			if (x == pa) continue;
			A[x] = A[v]+a;
			B[x] = B[v]+b;
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	};

	dfs(1, 1);
	// return;
	// debug(A);
	auto jump = [&](int v, int j){
		for (int i = K-1; i >= 0; i--){
			if (j&(1<<i)){
				v = up[v][i];
			}
		}
		return v;
	};
	vector<int>ans(n+1);
	for (int curr = 2; curr<=n; curr++){
		// if (curr != 3) continue;
		int l = 0, r = depth[curr];
		while (r>=l){
			int mid = (l+r)/2;
			if (B[jump(curr, mid)] <= A[curr]){
				ans[curr] = mid;
				r = mid-1;
			} else {
				l = mid+1;
			}
		}
		ans[curr] = depth[curr]-ans[curr];
	}
	for (int i = 2; i<=n; i++) cout << ans[i] << " ";
	cout << "\n"; 
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}