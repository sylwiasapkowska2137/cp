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
	vector<vector<int>>g(n+1);
	vector<int>in(n+1);
	for (int i = 1; i<n; i++){
		int k; cin >> k;
		for (int j = 0; j<k; j++){
			int v; cin >> v;
			g[i].emplace_back(v);
			in[v]++;
			// cerr << i << " " << v << endl;
		}
	}
	vector<int>curr(n+1);
	curr[1] = m;
	queue<int>q;
	vector<int>topo;
	for (int i = 1; i<=n; i++) if (!in[i]) q.push(i);
	while (q.size()){
		int v = q.front();q.pop();
		topo.emplace_back(v);
		for (auto x: g[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	int ans = 0;
	for (auto v: topo){
		if (v == n) continue;
		int k = (int)g[v].size();
		int ile = curr[v]/k;
		// debug(v, ile);
		for (auto x: g[v]){
			curr[x] += ile;
			ans += ile;
		}
		curr[v] %= k;
		for (int i = 0; i<curr[v]; i++){
			curr[g[v][i]]++;
			ans++;
			// debug(v, g[v][i]);
		}
	}
	cout << ans << endl;
	// debug(curr);
	// debug(topo);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
