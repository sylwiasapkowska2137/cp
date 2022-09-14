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
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}	
	vector<int>used(n+1), sub(n+1);

	function<int(int, int)> dfs = [&](int v, int pa){
		sub[v] = 1;
		for (auto x: g[v]){
			if (x == pa || used[x]) continue;
			sub[v] += dfs(x, v);
		}
		return sub[v];
	};
	vector<char>ans(n+1);

	function<int(int, int, int)>get_centroid = [&](int v, int ms, int pa){
		for (auto x: g[v]){
			if (x == pa || used[x]) continue;
			if (sub[x] * 2 > ms){
				return get_centroid(x, ms, v);
			}
		}
		return v;
	};	

	function<void(int, char)>centroid = [&](int v, char letter){
		v = get_centroid(v, dfs(v, v), v);
		ans[v] = letter;
		used[v] = 1;
		for (auto x: g[v]){
			if (!used[x]){
				centroid(x, letter+1);
			}
		}
	};

	centroid(1, 'A');
	for (int i = 1; i<=n; i++) cout << ans[i] << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}