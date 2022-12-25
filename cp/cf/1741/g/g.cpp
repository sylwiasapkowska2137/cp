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
	int n, m; cin >> n >> m;
	vector<vector<int>>g(n+1);
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	int f; cin >> f;
	vector<int>a(f);
	for (int i = 0; i<f; i++) cin >> a[i];
	int k; cin >> k;
	vector<int>sad(k), idx(k);
	for (int i = 0; i<k; i++) {
		cin >> idx[i];
		sad[i] = a[idx[i]-1];
	}
	vector<vector<int>>dist(n+1, vector<int>(k+1, oo));
	for (int i = 0; i<k; i++){
		queue<int>q;
		q.push(sad[i]);
		dist[sad[i]][i] = 0;
		while (q.size()){
			int v = q.front();q.pop();
			for (auto x: g[v]){
				if (dist[x][i] == oo){
					dist[x][i] = dist[v][i]+1;
					q.push(x);
				}
			}
		}
	}
	queue<int>q;
	q.push(1);
	dist[1][k] = 0;
	while (q.size()){
		int v = q.front();q.pop();
		for (auto x: g[v]){
			if (dist[x][k] == oo){
				dist[x][k] = dist[v][k]+1;
				q.push(x);
			}
		}
	}


	// debug(sad);
	int base = (1<<k);
	vector<int>dp(base);
	dp[0] = 1;
	for (int ii = 0; ii<f; ii++){
		int v = a[ii];
		bool ok = 0;
		for (auto x: idx) if (x-1 == ii) ok = 1;
		if (ok) continue;
		
		vector<int>new_dp = dp;

		for (int mask = 0; mask<base; mask++){
			bool can = 1;
			
			for (int i = 0; i<k; i++){
				if (mask&(1<<i)){
					can &= (dist[v][i] + dist[sad[i]][k] == dist[v][k]);
					for (int j = 0; j<k; j++){
						if (i == j) continue;
						if (mask&(1<<j)){
							can &= (
								(dist[v][j] + dist[sad[i]][j] + dist[sad[i]][k] == dist[v][k]) || 
								(dist[v][i] + dist[sad[j]][i] + dist[sad[j]][k] == dist[v][k])
								);
						}
					}
					if (!can) break;
				}
				
			}
			if (can){
				// debug(mask);
				for (int mask2 = 0; mask2 < base; mask2++){
					new_dp[(mask2|mask)] |= dp[mask2];
				}
			}
		}
		dp = new_dp;
	}
	// debug(idx);
	int ans = k;
	for (int mask = 0; mask<base; mask++){
		if (!dp[mask]) continue;
		int l = __builtin_popcountll(mask);
		// debug(mask, l);
		ans = min(ans, k-l);
	}
	cout << ans << "\n";
	// exit(0);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}