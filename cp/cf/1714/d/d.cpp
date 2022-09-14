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
	string t; cin >> t;
	int n; cin >> n;
	int T = (int)t.size();
	t = '$'+t;
	
	vector<string>tab(n+1);
	map<string, int>cnt;
	for (int i = 0; i<n; i++){
		string s; cin >> s;
		reverse(s.begin(), s.end());
		cnt[s] = i+1;
		tab[i+1] = s;
	}
	vector<int>dp(T+1, oo);
	vector<pair<int, int>>from(T+1);
	dp[0] = 0;
	for (int i = 1; i<=T; i++){
		string curr;
		int mn = oo;
		int pos = oo;
		for (int j = i; j>=1; j--){
			curr += t[j];
			if (mn >= dp[j-1]){
				pos = j-1;
			}
			mn = min(mn, dp[j-1]);
			// debug(j, i, curr);
			if (cnt.find(curr) != cnt.end()){
				// debug(j, i);
				if (mn + 1 < dp[i]){
					dp[i] = mn + 1;
					from[i] = {cnt[curr], pos};
				}
				// dp[i] = min(dp[i], dp[j-1] + 1);
			}
		}
	}
	// debug(dp);
	// debug(from);
	if (dp[T] == oo){
		cout << "-1\n";
		return;
	}
	cout << dp[T] << "\n";
	int pos = T;
	while (dp[T]--){
		cout << from[pos].first << " " << pos-tab[from[pos].first].size()+1 << "\n";
		pos = from[pos].second;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}	