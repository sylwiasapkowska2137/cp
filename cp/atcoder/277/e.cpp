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

void solve(){
	int n, m, k; cin >> n >> m >> k;
	typedef pair<int, int>T;
	vector<vector<T>>g(n+1);
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	vector<vector<int>>dist(n+1, vector<int>(2, oo));
	dist[1][0] = 0;
	queue<T>q;
	vector<int>big(n+1);
	q.push({1, 0});
	for (int i = 0; i<k; i++){
		int v; cin >> v;
		big[v] = 1;
	}
	while (q.size()){
		auto [v, rev] = q.front();q.pop();
		for (auto [x, c]:g[v]){
			if (c != rev){
				if (dist[x][rev] == oo){
					dist[x][rev] = dist[v][rev]+1;
					q.push({x, rev});
				}
			}
			if (c == rev){
				if (big[v]){
					if (dist[x][rev^1] == oo){
						dist[x][rev^1] = dist[v][rev]+1;
						q.push({x, rev^1});
					}
				}
			}
			
		}
	}
	int ans = min(dist[n][0], dist[n][1]);
	if (ans == oo) cout << "-1\n";
	else cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
