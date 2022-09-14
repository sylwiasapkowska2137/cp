//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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
	int root = -1;
	vector<int>pa(n+1);
	vector<vector<int>>g(n+1);
	for (int i = 1; i<=n; i++){
		cin >> pa[i];
		if (i == pa[i]) root = i;
		else {
			//g[i].emplace_back(pa[i]);
			g[pa[i]].emplace_back(i);
			debug(i, pa[i]);
		}
	}
	cerr << endl;

	vector<vector<int>>ans;
	vector<int>curr;
	vector<int>depth(n+1);
	function<void(int, int)>dfs = [&](int v, int pa){
		for (auto x: g[v]){
			if (x!=pa){
				depth[x] = depth[v]+1;
				dfs(x, v);
			}
		}
	};
	vector<bool>vis(n+1, 0);
	function<void(int, int)>dfs2 = [&](int v, int pa){
		vis[v] = 1;
		curr.emplace_back(v);
		for (auto x: g[v]){
			if (x!=pa){
				dfs2(x, v);
				return;
			}
		}
	};
	dfs(root, -1);
	vector<int>ord(n);
	iota(ord.begin(), ord.end(), 1);
	sort(ord.begin(), ord.end(), [&](auto a, auto b){return depth[a] < depth[b];});
	for (int i = 0; i<n; i++){
		if (!vis[ord[i]]){
			curr.clear();
			dfs2(ord[i], -1);
			ans.emplace_back(curr);
		}
	}
	cout << (int)ans.size() << "\n";
	for (auto x: ans){
		cout << x.size() << "\n";
		for (auto y:x) cout << y << " ";
		cout << "\n";
	}
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