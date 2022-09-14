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

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<pair<int, int>>k;
	for (int i = 0; i<3; i++){
		int x, y; cin >> x >> y;
		k.emplace_back(x, y);
	}
	set<pair<int, int>>bad;
	for (int i = 0; i<m; i++){
		int x, y; cin >> x >> y;
		bad.emplace(x, y);
	}
	map<pair<int, int>,int>dp;
	dp[{0, 0}] = 1;
	for (int i = 0; i<n; i++){
		map<pair<int, int>, int>new_dp;
		for (auto curr: dp){
			auto [x, y] = curr.first;
			for (int mv = 0; mv<3; mv++){
				pair<int, int>u = {x + k[mv].first, y + k[mv].second};
				if (bad.find(u) == bad.end()){
					add(new_dp[u], curr.second);
				}
			}
		}
		swap(dp, new_dp);
	}
	int ans = 0;
	for (auto v: dp){
		add(ans, v.second);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
