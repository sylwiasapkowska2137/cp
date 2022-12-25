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

//zamiast sztucznie dodawać 1 w miejscu gdy pojawi nam się pojedynczy 
//"(" lub ")", to zmieniamy delikatnie postać dp
//wciąz n^4, ale z nadzieją na poprawę

void solve(){
	int n; cin >> n;
	vector<string>tab(n);
	for (int i = 0; i<n; i++) cin >> tab[i];
	auto count = [](string &s){
		int n = (int)s.size();
		vector dp(n+1, vector<vector<int>>(n+2, vector<int>(2)));
		dp[0][0][0] = 1;
		for (int i = 1; i<n; i++){
			for (int b = 0; b <= n; b++){
				if (s[i] == 'L'){
					dp[i][b][1] = dp[i-1][b][1];
					dp[i][b][0] = b ? dp[i-1][b-1][0]+dp[i-1][b-1][1] : dp[i-1][b][0];
				} else {
					dp[i][b][0] = dp[i-1][b][0];
					dp[i][b][1] = dp[i-1][b+1][0] + dp[i-1][b+1][1];
				}
			}
		}
		return dp[n-1][0][1];
	};
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			string t = "$" + tab[i] + tab[j];
			cout << count(t) << " ";
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
