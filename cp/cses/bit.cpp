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
const int oo = 1e18, K = 30;

void solve(){
	int n; cin >> n;
	const int M = 20;
	vector<int>dp(1<<M), dp2(1<<M);
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		dp[a[i]]++;
		dp2[a[i]]++;
	}
	for (int i = 0; i<M; i++){
		for (int mask = 0; mask<(1<<M); mask++){
			if (mask&(1<<i)){
				dp[mask] += dp[mask^(1<<i)];
			}
		}
	}
	for (int i = 0; i<M; i++){
		for (int mask = (1<<M)-1; mask >= 0; mask--){
			if (!(mask&(1<<i))){
				dp2[mask] += dp2[mask|(1<<i)];
			}
		}
	}
	auto rev = [&](int x){
		int v = 0;
		for (int i = 0; i<M; i++){
			if (x&(1<<i)) {
				;
			} else v += (1<<i);
		}
		return v;
	};
	for (int i = 1; i<=n; i++){
		cout << dp[a[i]] << " " << dp2[a[i]] << " " << n-dp[rev(a[i])] << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
