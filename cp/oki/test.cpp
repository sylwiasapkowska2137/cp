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

// #define int long long
// const int oo = 1e18, oo2 = 1e9+7, K = 30;
// const int mod = 998244353;

void solve(){
	int n; cin >> n;
	map<int, vector<int>>idx;
	for (int i = 1; i<=n; i++){
		int x; cin >> x;
		idx[x].emplace_back(i);
	}
	int q; cin >> q;
	while (q--){
		int k; cin >> k;
		int st = 0;
		bool ok = 1;
		for (int i = 0; i<k; i++){
			int v; cin >> v;
			if (!ok) continue;
			int x = (int)(lower_bound(idx[v].begin(), idx[v].end(), st)-idx[v].begin());
			if (x >= (int)idx[v].size() || idx[v][x] < st) ok = 0;
			else st = idx[v][x]+1;
		}
		cout << (ok ? "TAK" : "NIE") << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
