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

const int MAX = 1e5+7;
vector<int>graf[MAX], ans, val;
map<int, int>color[MAX], ile[MAX];
vector<pair<int, int>>query[MAX];

void dfs(int v, int pa = -1){
	color[v][val[v]]++;
	ile[v][1]++;
	for (auto x: graf[v]){
		if (x!=pa){
			dfs(x, v);
			if ((int)color[v].size() < (int)color[x].size()){
				swap(color[v], color[x]);
				swap(ile[v], ile[x]);
			}
			for (auto e: color[x]){
				for (int i = 1; i<=e.second; i++){
					ile[v][color[v][e.first]+i]++;
				}
				color[v][e.first] += e.second;
			}
		}
	}
	for (auto [k, i]:query[v]){
		ans[i] = ile[v][k];
	}
}

void solve(){
	int n, q; cin >> n >> q;
	val.resize(n+1);
	for (int i = 1; i<=n; i++) cin >> val[i];
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i = 0; i<q; i++){
		int v, k; cin >> v >> k;
		query[v].push_back({k, i});
	}
	ans.resize(q);
	dfs(1);
	for (int i = 0; i<q; i++) cout << ans[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
