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

bool check(int mid, int&n, vector<int>&curr, vector<int>&a, vector<vector<int>>&g){
	vector<int>good;
	vector<int>now = curr;
	for (int i = 1; i<=n; i++) if (curr[i] <= mid) good.emplace_back(i);
	vector<int>vis(n+1);
	while (good.size()){
		int v = good.back();
		good.pop_back();
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto x: g[v]){
			if (!vis[x]){
				now[x] -= a[v];
				if (now[x] <= mid) good.emplace_back(x);
			}
		}
	}
	int sum = accumulate(vis.begin(), vis.end(), 0);
	return sum == n;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	vector<vector<int>>g(n+1);
	set<pair<int, int>>s;
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<int>curr(n+1);
	for (int i = 1; i<=n; i++){
		for (auto x: g[i]){
			curr[i] += a[x];
		}
	}
	int L = 0, R = oo, ans = oo;
	while (R >= L){
		int mid = (L+R)/2;
		if (check(mid, n, curr, a, g)){
			ans = mid;
			R = mid-1;
		} else L = mid+1;
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
