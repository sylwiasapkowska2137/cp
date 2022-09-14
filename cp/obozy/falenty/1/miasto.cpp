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
const int oo = 1e18, oo2 = 1e9+7, K = 20;
const int mod = 998244353;

void solve(){
	int n; cin >> n;
	
	vector<vector<int>>up(n+1, vector<int>(K));
	int L = 0, R = 0, curr = 0;
	vector<int>depth(n+1);

	auto lca = [&](int a, int b){
		if (depth[a] < depth[b]) swap(a, b);
		for (int i = K-1; i>=0; i--){
			if (depth[a] - (1<<i) >= depth[b]){
				a = up[a][i];
			}
		}
		if (a == b) return a;
		for (int i = K-1; i>=0; i--){
			if (up[a][i] != up[b][i]){
				a = up[a][i];
				b = up[b][i];
			}
		}
		return up[a][0];
	};

	auto dist = [&](int a, int b){
		return depth[a] + depth[b] - 2*depth[lca(a, b)];
	};


	for (int v = 1; v<=n; v++){
		int pa; cin >> pa;
		up[v][0] = pa;
		depth[v] = depth[pa]+1;
		for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];

		int d1 = dist(L, v);
		if (d1 > curr){
			curr = d1;
			R = v;
		}
		int d2 = dist(v, R);
		if (d2 > curr){
			curr = d2;
			L = v;
		}
		cout << curr << "\n";
	}

}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
