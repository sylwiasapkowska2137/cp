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
	vector<int>bad;
	for (int i = 0; i<m; i++){
		int a, b; cin >> a >> b;
		if (!a) {
			bad.emplace_back(b);
		} else{
			g[a].emplace_back(b);
			g[b].emplace_back(a);
		}
	}

	vector<int>dist1(n+1, oo), distN(n+1, oo);
	// debug(69);
	queue<int>q;
	q.push(1);
	dist1[1] = 0;
	while (q.size()){
		int v = q.front();q.pop();
		for (auto x: g[v]){
			if (dist1[x] == oo){
				dist1[x] = dist1[v]+1;
				q.push(x);
			}
		}
	}
	q.push(n);
	distN[n] = 0;
	while (q.size()){
		int v = q.front();q.pop();
		for (auto x: g[v]){
			if (distN[x] == oo){
				distN[x] = distN[v]+1;
				q.push(x);
			}
		}
	}

	// debug(dist1);
	// debug(distN);
	int mn = oo, mn2 = oo;
	for (auto x: bad){
		mn = min(mn, dist1[x]);
		mn2 = min(mn2, distN[x]);
	}
	// debug(bad);
	if (bad.empty()){
		for (int i = 1; i<=n; i++){
			cout << (dist1[n] == oo ? -1 : dist1[n]) << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i<=n; i++){
		int ans = min({oo, dist1[n], mn+1+distN[i], mn2+1+dist1[i], mn+mn2+2});
		if (ans == oo) cout << "-1 ";
		else cout << ans << " ";
	}
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
