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
	vector<int>b(n+1);
	int root;
	vector<vector<int>>g(n+1);
	vector<int>par(n+1);
	for (int i = 1; i<=n; i++) {
		int p; cin >> p;
		par[i] = p;
		if (p == i) root = i;
		else {
			g[p].emplace_back(i);
			g[i].emplace_back(p);
		}
	}
	vector<int>p(n+1), pos(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	if (p[1] != root){
		cout << "-1\n";
		return;
	}

	vector<int>depth(n+1, -1);
	depth[root] = 0LL;
	vector<int>edge(n+1);
	for (int i = 2; i<=n; i++){
		int v = p[i];
		if (depth[par[v]] == -1){
			cout << "-1\n";
			return;
		}
		depth[v] = i-1;
		edge[v] = depth[v]-depth[par[v]];
	}
	for (int i = 1; i<=n; i++) cout << edge[i] << " ";
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