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
	int n; cin >> n;
	vector<int>d(n+1);
	for (int i = 1; i<=n; i++) cin >> d[i];
	vector<vector<pair<int, int>>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	vector<vector<int>>dp(n+1, vector<int>(2, 0));
	
	for (int i = 1; i<=n; i++){
		if (!d[i]) {
			dp[i][0] = -oo;
		}
	}

	function<void(int, int)>dfs = [&](int v, int pa){
		vector<pair<int, int>>tmp;
		int curr = 0;
		for (auto [x, c]:g[v]){
			if (x == pa) continue;
			dfs(x, v);
			tmp.emplace_back(dp[x][1], dp[x][0]+max(0LL, c));
		}
		if (tmp.empty()) return;
		int c = 0;
		for (auto x: tmp){
			if (x.first < x.second) c++;
			curr += max(x.first, x.second);
		}
		sort(tmp.begin(), tmp.end(), [](auto a, auto b){return a.first-a.second < b.first - b.second;});
		int t = (int)tmp.size()-1;
		while (c > d[v]){
			if (t < 0) break;
			if (tmp[t].second > tmp[t].first){
				curr -= tmp[t].second;
				curr += tmp[t].first;
				c--;
			}
			t--;
		}
		if (c <= d[v]) dp[v][1] = curr;
		while (c == d[v]){
			if (t < 0) break;
			if (tmp[t].second > tmp[t].first){
				curr -= tmp[t].second;
				curr += tmp[t].first;
				c--;
			}
			t--;
		}
		if (c < d[v]) dp[v][0] = curr;
	};

	dfs(1, 1);
	// for (int i = 1; i<=n; i++){
	// 	cout << i << " " << dp[i][0] << " " << dp[i][1] << "\n";
	// }
	cout << max(dp[1][1], dp[1][0]) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
