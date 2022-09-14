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

void solve(){
	short int n; cin >> n;
	vector<int>a(n+1);
	const int S = 1e4;
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
	}
	vector<vector<short int>>dp(n+1, vector<short int>(S+1, 0));
	for (short int i = 1; i<=n; i++){
		dp[i] = dp[i-1];
		if (a[i]>S) continue;
		for (short int s = 0; s<=S; s++){
			if (a[dp[i][s]] == a[i]) dp[i][s] = max(dp[i][s], dp[i-1][s-a[i]]);
			if (dp[i-1][s] > 0 && s+a[i]<=S) dp[i][s+a[i]] = max(dp[i][s+a[i]], dp[i-1][s]);
		}
		dp[i][a[i]] = i;
	}
	int q; cin >> q;
	while (q--){
		short int a, b, s; cin >> a >> b >> s;
		cout << ((dp[b][s] >= a)?"TAK\n":"NIE\n");
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
