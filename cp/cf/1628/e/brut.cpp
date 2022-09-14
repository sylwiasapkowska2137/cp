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

const int MAX = 3e5+7;
vector<pair<int, int>>graf[MAX];
vector<bool>mozna;
vector<int>curr;

void dfs(int v, int pa){
	for (auto [x, c]: graf[v]){
		if (x != pa){
			curr[x] = max(curr[v], c);
			dfs(x, v); 
		}
	}
}

void solve(){
	int n, q; cin >> n >> q;
	mozna.assign(n+1, 0);
	for (int i = 1; i<n; i++){
		int a, b, c; cin >> a >> b >> c;
		graf[a].push_back({b, c});
		graf[b].push_back({a, c});
	}
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int l, r; cin >> l >> r;
			for (int i = l; i<=r; i++) mozna[i] = 1;
		} 
		if (t == 2){
			int l, r; cin >> l >> r;
			for (int i = l; i<=r; i++) mozna[i] = 0;
		}
		if (t == 3){
			int x; cin >> x;
			curr.assign(n+1, -1);
			dfs(x, x);
			int ans = -1;
			for (int i = 1; i<=n; i++){
				if (mozna[i]) ans = max(ans, curr[i]);
			}
			cout << ans << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
