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

int ti(char c){
	return (int)(c-'a');
}

string s;
vector<int>pref[K];

int cnt(char c, int l, int r){
	return pref[ti(c)][r] - pref[ti(c)][l-1];
}

int rec(int l, int r, char letter){
	if (l > r) return oo;
	if (l == r) return (s[l] != letter);
	//debug(l, r, letter);
	int mid = (l+r)/2;
	int len = (r-l+1)/2;
	return min(len-cnt(letter, l, mid)+rec(mid+1, r, letter+1), len-cnt(letter, mid+1, r)+rec(l, mid, letter+1));
}

void solve(){
	int n; cin >> n;
	cin >> s;
	s = "%"+s;
	for (int i = 0; i<K; i++) pref[i].clear();
	for (char c = 'a'; c<='z'; c++){
		pref[ti(c)].resize(n+1);
		for (int i = 1; i<=n; i++){
			pref[ti(c)][i] += pref[ti(c)][i-1];
			if (s[i] == c) pref[ti(c)][i]++;
		}
	}
	cout << rec(1, n, 'a') << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}