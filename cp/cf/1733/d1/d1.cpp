//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
	int n, x, y; cin >> n >> x >> y;
	string s, t; cin >> s >> t;
	int cnt = 0;
	for (int i = 0; i<n; i++){
		if (s[i] != t[i]){
			cnt++;
		}
	}
	if (cnt&1) {
		cout << "-1\n";
		return;
	}
	if (x >= y){
		x = min(x, 2*y);
		// debug(x, y);
		if (cnt == 2){
			for (int i = 1; i<n; i++){
				if (s[i] != t[i] && s[i-1] != t[i-1]){
					cout << x << "\n";
					return;
				}
			}
			cout << y << "\n";
			return;
		} else {
			cout << cnt*y/2 << "\n";
		}
		return;
	} 
	//x < y
	if (s == t){
		cout << "0\n";
		return;
	}
	vector<int>pos;
	for (int i = 0; i<n; i++){
		if (s[i] != t[i]){
			pos.emplace_back(i);
		}
	}
	
	int m = (int)pos.size();
	auto cost = [&](int a, int b){
		return min(abs(a-b)*x, y);
	};
	vector<vector<int>>dp(m+1, vector<int>(m+1, oo));
	for (int i = 0; i<m-1; i++){
		dp[i][i+1] = cost(pos[i], pos[i+1]);
	}
	for (int len = 4; len<=m; len+=2){
		for (int L = 0; L<m; L++){
			int R = L+len-1;
			int mn = oo;
			if (R >= m) break;
			dp[L][R] = min(dp[L+1][R-1] + cost(pos[L], pos[R]), mn);
			for (int k = L; k<R; k++){
				dp[L][R] = min(dp[L][R], dp[L][k]+dp[k+1][R]);
			}
		}
	}
	cout << dp[0][m-1] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}