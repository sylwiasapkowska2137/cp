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
const int oo = 1e18, oo2 = 1e9+7, K = 4;
const int mod = 1e9+7, base = (1<<K);

void add(int &a, int b){
	a += b;
	if (a >= mod) a-=mod;
}

void solve(){
	int n; cin >> n;
	vector<int>dp(base), cnt(base);
	int a = (1<<K)-1;
	for (int i = 0; i<n; i++){
		int x; cin >> x;
		dp[x]++;
		cnt[x]++;
		a &= x;
	}
	if (a){
		cout << "-1\n";
		return;
	}
	if (cnt[0]){
		cout << "0 0\n";
		return;
	}
	for (int i = 0; i<K; i++){
		for (int mask = 0; mask<base; mask++){
			if (mask&(1<<i)){
				cnt[mask^(1<<i)] += cnt[mask];
			}
		}
	}
	debug(cnt);
	// return;
	for (int ile = 1; ; ile++){
		for (int mask = base-1; mask >= 0; mask--){
			for (int i = 0; i<K; i++){
				if (!(mask&(1<<i))){
					add(dp[mask], dp[mask^(1<<i)]);
				}
			}
		}
		for (int mask = 0; mask<base; mask++) dp[mask] *= cnt[mask];
		debug(ile, dp);
		if (dp[0]){
			cout << ile << " " << dp[0] << "\n";
			return;
		}
	}
	assert(false);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
