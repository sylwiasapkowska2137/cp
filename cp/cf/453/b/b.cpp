//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

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
const int oo = 1e18, K = 30;

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	vector<int>p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
	int P = (int)p.size();
	const int N = 60;
	vector<int>F(N);
	for (int i = 1; i<N; i++){
		int k = 0;
		for (auto d: p){
			if (i%d == 0){
				F[i] |= (1<<k);
			}
			k++;
		}
	}
	vector<vector<int>>dp(n+1, vector<int>((1<<P)+1, oo));
	for (int mask = 0; mask<(1<<P); mask++) dp[0][mask] = 0;
	//dp[i][mask] = min imbalance
	for (int i = 1; i<=n; i++){
		for (int mask = 0; mask<(1<<P); mask++){
			for (int val = 1; val<N; val++){
				if ((mask&F[val]) == F[val]){
					dp[i][mask] = min(dp[i][mask], dp[i-1][mask^F[val]]+abs(a[i]-val));
				}
			}
			//debug(i, mask, dp[i][mask]);
		}
	}
	int val = oo, maska = 0;
	for (int mask = 0; mask<(1<<P); mask++){
		if (dp[n][mask] < val){
			val = dp[n][mask];
			maska = mask;
		}
	}
	debug(val, maska);
	vector<int>b;
	for (int i = n; i>0; i--){
		int curr = oo, newmask = maska;
		for (int val = 1; val<N; val++){
			if ((maska&(F[val])) == F[val]){
				if (dp[i][maska] == dp[i-1][maska^F[val]]+abs(a[i]-val)){
					if (abs(curr-a[i]) > abs(val-a[i])){
						curr = val;
						newmask = maska^F[val];
					}
				}
			}
		}
		b.emplace_back(curr);
		maska = newmask;
	}
	reverse(b.begin(), b.end());
	for (auto x: b) cout << x << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}