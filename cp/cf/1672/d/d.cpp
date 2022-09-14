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
	vector<int>a(n), b(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	for (int i = 0; i<n; i++) cin >> b[i];
	vector<int>prev(n+1, -1), pos(n);
	for (int i = 0; i<n; i++){
		pos[i] = prev[b[i]];
		prev[a[i]] = i;
	}
	if (a.back() != b.back()) {
		cout << "NO\n";
		return;
	}
	vector<bool>vis(n, 0);
	int curr = n-1;
	for (int i = n-1; i>=0; i--){
		if (b[i] == a[curr]){
			debug(i, curr, b[i], a[curr]);
			curr--;
			while (curr>=0 && vis[curr]) curr--;
			if (curr < 0) break;
			continue;
		}
		debug(i, curr, b[i], a[curr]);
		//trzeba wykonac swap
		//znalezc pierwszy na lewo element b[i]
		//i usunac go 
		int x = pos[i];
		while (x>=0 && vis[x]) x = pos[x];
		debug(x);
		if (x == -1 || b[i+1] != b[i]){
			cout << "NO\n";
			return;
		}
		vis[x] = 1;
		while (curr>=0 && vis[curr]) curr--;
		if (curr < 0) break;
	}
	if (curr >= 0) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}