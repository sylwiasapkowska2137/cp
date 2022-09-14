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
	string s; cin >> s;
	map<char, int>cnt;
	for (auto c:s) cnt[c]++;
	s.push_back('2');
	vector<int>a;
	int ile = 1;
	for (int i = 1; i<=n; i++){
		if (s[i] != s[i-1]){
			a.emplace_back(ile);
			ile = 0;
		}
		ile++;
	}
	int ans = 0, ans2 = 0;
	int i = 0;
	while (i < (int)a.size()){
		if (a[i]&1){
			if (i+2 < (int)a.size() && a[i+1] == 2 && (a[i+2]&1)){
				a[i+2]++, a[i+1] = 0, a[i]++; 
				ans2 += 2;	
				ans += 2;
				i+=3;
				continue;
			} else if (i+1 < (int)a.size() && a[i+1] == 1){
				a[i]++, a[i+1]++;
				ans++;
				i+=2;	
			} else {
				a[i]--;
				if (!a[i]) ans2++;
				a[i+1]++;
				ans++;
				i++;
				continue;
			}
		}
		i++;
	}
	//debug(a);
	cout << ans << " " << (int)a.size()-ans2 << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}