//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

const int MAX = 2e5+7;
vector<int>graf[MAX];
vector<bool>vis;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]){
			dfs(x);
		}
	}
}

void solve(){
	int n, m, q; cin >> n >> m >> q;
	vector<pair<int, int>>edges;
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		edges.push_back({a, b});
	}
	vector<pair<int, int>>paths;
	for (int i = 0; i<q; i++){
		int a, b; cin >> a >> b;
		paths.emplace_back(a, b);
	}
	for (int mask = 0; mask<(1<<m); mask++){
		for (int i = 1; i<=n; i++) graf[i].clear();
		for (int i = 0; i<m; i++){
			auto [a, b] = edges[i];
			if (mask&(1<<i)){
				graf[a].push_back(b);
			} else graf[b].push_back(a);
		}
		bool ok = 1;
		for (auto [a, b]:paths){
			vis.assign(n+1, 0);
			dfs(a);
			if (!vis[b]) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
