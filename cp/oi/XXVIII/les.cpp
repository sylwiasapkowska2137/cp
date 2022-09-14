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

#define int long long
const int oo = 1e18;

void solve(){
	int n, d; cin >> n >> d;
	vector<vector<int>>s(n);
	for (int i = 0; i<n; i++){
		int x; cin >> x;
		for (int j = 0; j<x; j++) {
			int v; cin >> v;
			s[i].emplace_back(v);
		}
	}

	function<int(int)>dist = [&](int X){
		return min(X, d-X);
	};

	for (int z = 1; z<n; z++){
		int a = s[z-1].size();
		int b = s[z].size();
		
		vector<vector<int>>dp(a+1, vector<int>(b+1, oo));
		dp[0][0] = 0;
		for (int i = 0; i<=a; i++){
			for (int j = 0; j<=b; j++){
				if (i+j == 0) dp[i][j] = 0;
				else {
					dp[i][j] = min({
						i?(dp[i-1][j] + dist(s[z-1][i-1])):oo,
						j?(dp[i][j-1] + dist(s[z][j-1])):oo,
						(i&&j)?dp[i-1][j-1] + abs(s[z][j-1]-s[z-1][i-1]):oo
					});
				}
				//debug(i, j, dp[i][j]);
			}
			
		}
		cout << dp[a][b] << "\n";
		//cerr << "\n";
	}

}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
