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
const int mod = 1e9+7;

int calc(string &s){
	int n = (int)s.size();
	vector<vector<int>>new_dp(2, vector<int>(n+1, 0));
	vector<vector<int>>dp(2, vector<int>(n+1, 0));
	for (int i = 0; i<n; i++){
		int x = (s[i] == 'L') ? 1 : -1;
		int y = (s[i] == 'L') ? 0 : 1;
		for (int j = n-1; j>=0; j--){
			if (x == -1 && j == 0) continue;
			new_dp[y][j+x] = dp[0][j] + dp[1][j];
			if (new_dp[y][j+x] >= mod){
				new_dp[y][j+x] -= mod;
			}
		}
		if (x == 1) {
			new_dp[y][1] += 1;
			if (new_dp[y][1] >= mod){
				new_dp[y][1] -= mod;
			}
		}
		new_dp[1-y] = dp[1-y];
		swap(dp, new_dp);
		new_dp.assign(2, vector<int>(n+1, 0));
	}
	return dp[1][0];
}

void solve(){
	int n; cin >> n;
	vector<string>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	for (int i = 0; i<n; i++){
		string t = a[i];
		for (int j = 0; j<n; j++){
			t += a[j];
			cout << calc(t) << " ";
			for (int ck = 0; ck<(int)a[j].size(); ck++) t.pop_back();
		}
		cout << "\n";
	}	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
