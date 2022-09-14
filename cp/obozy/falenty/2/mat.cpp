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
const int mod = 1e9+7;

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

int mul(int a, int b){
	return (a*b)%mod;
}

void solve(){
	int k, p; cin >> k >> p;
	vector<bool>check(p+2);
	check[2] = 0;	
	int X = (int)check.size();
	int P = 1;
	for (int i = 2; i<X; i++){
		if (check[i]) continue;
		if (i <= p) P++;
		for (int j = i*i; j<X; j+=i){
			check[j] = 1;
		}
	}
	if (p == 1){
		if (k == 1){
			cout << "1\n";
			return;
		}
		cout << "0\n";
		return;
	}
	vector<int>div;
	for (int d = 1; d*d <= k; d++){
		if (k % d != 0) continue;
		div.emplace_back(d);
		if (k/d != d) div.emplace_back(k/d);
	}
	sort(div.begin(), div.end());
	int D = (int)div.size();
	vector<vector<int>>dp(P+1, vector<int>(D+1));
	vector<vector<int>>curr(D+1);
	for (int d = 1; d < D; d++){
		for (int d2 = 0; d2 <= d; d2++){
			if (div[d] % div[d2] == 0){
				curr[d].emplace_back(d2);
			}
		}
	}
	for (int i = 1; i<P; i++){
		for (int d = 1; d < D; d++){
			add(dp[i][d], 1);
			for (auto d2: curr[d]) add(dp[i][d], dp[i-1][d2]);
		}
	}
	cout << dp[P-1][D-1] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
