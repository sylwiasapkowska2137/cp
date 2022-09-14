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
const int base = 1e6+3;


vector<int> kmp(const string& s) {
	vector<int>p(s.size());
	for (int i = 1;i<(int)s.size(); i++){
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}


void solve(){
	string s, t; cin >> s >> t;
	int S = (int)s.size();
	int T = (int)t.size();
	
	map<char, int>cnt, cnt2;
	for (auto c: t){
		cnt2[c]++;
	}
	
	for (auto c: s){
		cnt[c]++;
	}
	for (auto x: cnt2){
		if (cnt.find(x.first) == cnt.end() || cnt[x.first] == 0){
			cout << "-1\n";
			return;
		}
	}

	
	string u = s+"#"+t;
	vector<int>pi = kmp(u);
	for (int i = S+1; i<(int)pi.size(); i++){
		if (!pi[i]){
			cout << "-1\n";
			return;
		}
	}
	debug(pi);
	vector<int>dp(T+1);
	for (int i = 1; i<=T; i++){
		dp[i] = dp[i-pi[i+S]]+1;
	}
	// debug(dp);
	cout << dp[T] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
