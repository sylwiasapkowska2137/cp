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
const int M = 18;
const int mod = 998244353;

void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}

int mul(int a, int b){
	return (a*b)%mod;
}

int power(int a, int b){
	if (!b) return 1LL;
	int k = power(a, b/2);
	k = mul(k, k);
	if (b&1) k = mul(k, a);
	return k;
}

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	int all = 0;
	for (auto c: s) all += (c == '?');
	int q; cin >> q;
	auto ti = [](char c){return (int)(c-'a');};
	vector<vector<pair<int, int>>>que(M);
	vector<int>ans(q);
	for (int i = 0; i<q; i++){
		string t; cin >> t;
		int mask = 0;
		for (auto c: t) mask |= (1<<ti(c));
		que[(int)t.size()].emplace_back(mask, i);
	}
	auto bin = [&](int mask){
		string c; 
		for (int i = 3-1; i>=0; i--){
			if (mask&(1<<i)) c += '1';
			else c += '0';
		}
		return c;
	};
	
	auto count = [&](int p){
		vector<int>dp(1<<M);
		for (int k = 0; k<2; k++){
			for (int i = 0; i<n; i++){
				int free = 0, inside = 0, mask = 0;
				for (int l = i, r = i+k; l >= 0 && r < n; l--, r++){
					inside += (s[l] == '?');
					inside += (s[r] == '?');
					if (l == r && s[l] == '?') inside--;
					if (s[l] == s[r]){
						if (s[l] == '?') free++;
					} else {
						if (s[l] == '?') mask |= (1<<ti(s[r]));
						else if (s[r] == '?') mask |= (1<<ti(s[l]));
						else break;
					}
					// debug(l, r, bin(mask));
					add(dp[mask], power(p, all-inside+free));
				}
			}
		}
		// debug(dp);
		for (int i = 0; i<M; i++){
			for (int mask = 0; mask < (1<<M); mask++){
				if (mask&(1<<i)){
					add(dp[mask], dp[mask^(1<<i)]);
				}
			}
		}
		// debug(dp);
		// debug(que[p]);
		for (auto [mask, idx]: que[p]){
			add(ans[idx], dp[mask]);
		}
	};
	for (int p = 1; p<M; p++) {
		count(p);
	}
	
	for (int i = 0; i<q; i++) cout << ans[i] << "\n";
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
