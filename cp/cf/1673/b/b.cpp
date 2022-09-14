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
	string s; cin >> s;
	int n = (int)s.size();
	map<char, int>cnt;
	for (auto c: s) cnt[c]++;
	for (char c = 'a'; c<='z'; c++){
		for (char d = c+1; d <= 'z'; d++){
			if (!cnt[c] || !cnt[d]) continue;
			vector<int>a(n+1);
			for (int i = 0; i<n; i++) {
				if (s[i] == c) a[i+1] = 1;
				else if (s[i] == d) a[i+1] = -1;
				else a[i+1] = 0;
			}
		
			for (int i = 1; i<=n; i++) a[i]+=a[i-1];
			int mini = 0, maxi = 0;
			for (int i = 1; i<=n; i++){
				//pref[i] - cos > 1 => cos < pref[i]-1
				//pref[i] - cos < -1 => cos > pref[i]+1
				if (maxi > a[i]+1 || mini < a[i]-1){
					cout << "NO\n";
					return;
				}
				maxi = max(maxi, a[i]);
				mini = min(mini, a[i]);
			}
		}
	}
	cout << "YES\n";
	return;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}