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
const int oo2 = 1e9;
vector<int>f = {1, 1};
vector<int>pref;
map<pair<int, int>, int>dp;

int rec(int num, int last){
	if (num < 0 || last < 0) return -1;
	if (num == 0) return 0;
	if (dp.find({num, last}) != dp.end()) return dp[{num, last}];
	int x = (int)(lower_bound(f.begin(), f.end(), num)-f.begin());
	if (x < (int)f.size() && f[x] == num){
		dp[{num, last}] = (1<<x);
		return dp[{num, last}];
	}
	for (int i = last-2; i>=0; i--){
		int c = rec(num-f[i], i);
		if (c != -1){
			dp[{num, last}] = c|(1<<x);
			return dp[{num, last}];
		}
	}
	return -1;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	
	int s = 0;
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		s += a[i];
	}
	bool ok = 0;
	int ile = 0;
	for (int i = 0; i<(int)pref.size(); i++){
		if (s == pref[i]){
			ok = 1;
			ile = i+1;
		}
	}
	if (!ok){
		cout << "NO\n";
		return;
	}
	sort(a.begin()+1, a.end());
	debug(a);
	// debug(ile);
	// vector<vector<int>>m(n+1);
	// for (int i = 1; i<=n; i++){
	// 	for (int j = 0; j<45; j++){
	// 		int x = rec(a[i], j);
	// 		// debug(a[i], j, x);
	// 		if (x != -1){
	// 			m[i].emplace_back(x);
	// 		}
	// 	}
	// }
	// for (int i = 1; i<=n; i++){
	// 	sort(m[i].begin(), m[i].end());
	// 	m[i].erase(unique(m[i].begin(), m[i].end()), m[i].end());
	// 	debug(i, m[i]);
	// }
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (f.back() < oo2){
		f.push_back(f[f.size()-1] + f[f.size()-2]);
	}
	pref.resize(f.size());
	for (int i = 0; i<(int)f.size(); i++){
		pref[i] = (i ? pref[i-1] : 0) + f[i];
	}
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}