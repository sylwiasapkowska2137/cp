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
const int mod = 998244353;

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	int idx = -1;
	for (int i = 1; i<=n; i++){
		char c; cin >> c;
		if (a[i] == 2 && idx == -1){
			a.clear();
			idx = i;
			a.emplace_back(0);
			a.emplace_back(2);
		}
	}
	if (idx == -1 || is_sorted(a.begin(), a.end())){
		cout << "0\n";
		return;
	}
	vector<int>dp(n+1);
	int cnt = 0, what = 0, ans = 0;
	debug(idx);
	a[idx-1] = 0;
	for (int i = 1; i<(int)a.size(); i++){
		if (a[i] == 1){
			cnt++;
			dp[i] = i-idx-cnt+1;
			if (a[i-1] == 1) dp[i] = max(dp[i], dp[i-1]+1);
		}
	} 
	debug(dp);
	cout << *max_element(dp.begin(), dp.end()) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
