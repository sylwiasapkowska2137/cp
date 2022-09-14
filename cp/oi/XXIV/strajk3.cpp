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
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<int>alive(n+1, 1), alive_children(n+1);
	for (int i = 1; i<=n; i++) alive_children[i] = (int)g[i].size()-1;
	alive_children[1]++;
	vector<int>par(n+1, -1);
	queue<int>q;
	q.push(1);
	while (q.size()){
		int v = q.front(); q.pop();
		for (auto x:g[v]){
			if (par[x] == -1){
				par[x] = v;
				q.push(x);
			}
		}
	}
	int Q; cin >> Q;
	int ans = 1;
	while (Q--){
		int z; cin >> z;
		if(z > 0) {
			alive[z] = 0;
			if(z != 1) {
				alive_children[par[z]]--;
				ans += alive_children[z]+alive[par[z]]-1;
			} else ans += alive_children[z] - 1;
		} else {
			z = -z;
			alive[z] = 1;
			if(z != 1) {
				alive_children[par[z]]++;
				ans -= alive_children[z]+alive[par[z]]-1;
			} else ans -= alive_children[z]-1;
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
