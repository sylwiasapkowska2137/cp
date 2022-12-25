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

void solve(){
	int n, m; cin >> n >> m;
	vector<int>a(n+1);
	vector<vector<int>>curr(m+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		int L = max(0LL, (-a[i]+i-1)/i);
		int R = min(m, (n-a[i])/i);
		// debug(L, R);
		for (int day = L; day <= R; day++){
			curr[day].emplace_back(a[i] + day * i);
			// debug(day, a[i] + day*i);
		}
	}
	for (int i = 1; i<=m; i++){
		// debug(i, curr[i]);
		sort(curr[i].begin(), curr[i].end());
		curr[i].erase(unique(curr[i].begin(), curr[i].end()), curr[i].end());
		int ans = curr[i].size();
		for (int j = 0; j<(int)curr[i].size(); j++){
			if (curr[i][j] != j){
				ans = j;
				break;
			}
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
