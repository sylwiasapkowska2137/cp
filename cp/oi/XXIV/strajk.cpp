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


void solve(){
	int n; cin >> n;
	int s = (int)sqrt(n);
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}	
	for (int i = 1; i<=n; i++) sort(g[i].begin(), g[i].end());
	vector<int>del(n+1), big(n+1), V;
	for (int i = 1; i<=n; i++) if ((int)g[i].size() > s) V.emplace_back(i);
	int q; cin >> q;
	int ans = 1;
	while (q--){
		int v; cin >> v;
		int u = abs(v);
		int curr = del[u];
		for (auto x: V){
			if (!big[x]) continue;
			int y = (lower_bound(g[u].begin(), g[u].end(), x)-g[u].begin());
			if (y < (int)g[u].size() && g[u][y] == x) curr++;
		}
		if (v > 0){
			ans += ((int)g[v].size()-curr-1);
			if ((int)g[v].size() > s) big[v] = 1;
			else {
				for (auto x:g[v]){
					del[x]++;
				}
			}
		} else {
			v = -v;
			ans -= ((int)g[v].size()-curr-1);
			if ((int)g[v].size() > s) big[v] = 0;
			else {
				for (auto x:g[v]){
					del[x]--;
				}
			}
		}
		cout << ans << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
