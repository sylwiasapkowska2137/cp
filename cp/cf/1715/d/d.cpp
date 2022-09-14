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
	int n, q; cin >> n >> q;
	vector<tuple<int, int, int>>tab;
	while (q--){
		int i, j, x; cin >> i >> j >> x;
		if (i > j) swap(i, j);
		tab.emplace_back(i, j, x);
	}
	vector<int>ret(n+1);
	for (int b = K-1; b >= 0; b--){
		vector<int>fix(n+1), sure(n+1);
		vector<vector<int>>curr(n+1);
		for (auto [i, j, x]: tab){
			if (x&(1<<b)){
				curr[min(i, j)].emplace_back(max(i, j));
			} else {
				sure[i] = sure[j] = 1;
			}
		}
		for (int i = 1; i<=n; i++){
			for (auto x: curr[i]){
				if (sure[i]){
					fix[x] = 1;
					continue;
				}
				if (fix[i] || fix[x]) continue;
				fix[x] = 1;
			}
		}
		// debug(fix, sure);
		for (int i = 1; i<=n; i++) if (fix[i]) ret[i] += (1<<b);
	}
	for (int i = 1; i<=n; i++) cout << ret[i] << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}