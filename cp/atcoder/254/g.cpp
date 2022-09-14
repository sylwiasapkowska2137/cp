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
const int oo = 1e18, K = 32;
const int N = 2e5+7;
int trie[N*K+10][2];
int ends_a[N*K+10], ends_b[N*K+10];
int sz = 1;
int ans = 0;

void add(int x, bool ok){
	int msb = -1;
	for (int i = K-1; i>=0; i--){
		if (x&(1<<i)){
			msb = i;
			break;
		}
	}
	int v = 0;
	for (int i = msb; i>=0; i--){
		int s = ((x&(1<<i))?1:0);
		if (trie[v][s] == -1){
			trie[v][s] = sz++;
		} 
		v = trie[v][s];
	}
	if (ok) ends_b[v]++;
	else ends_a[v]++;
}

void dfs(int v, int edgeup = -1){
	if (trie[v][0] != -1) {
		dfs(trie[v][0], 0);
		ends_a[v] += ends_a[trie[v][0]];
		ends_b[v] += ends_b[trie[v][0]];
	}
	if (trie[v][1] != -1) {
		dfs(trie[v][1], 1); 
		ends_a[v] += ends_a[trie[v][1]];
		ends_b[v] += ends_b[trie[v][1]];
	}

	int t = min(ends_a[v], ends_b[v]);
	ends_a[v]-=t;
	ends_b[v]-=t;
	if (ends_b[v] && edgeup == 1){
		cout << "-1\n";
		exit(0);
	}
	ans += ends_b[v];
	ans += ends_a[v];
}

void solve(){
	int n; cin >> n;
	memset(trie, -1, sizeof(trie));
	for (int i = 0; i<n; i++){
		int x; cin >> x;
		add(x, 0);
	}
	for (int i = 0; i<n; i++) {
		int x; cin >> x;
		add(x, 1);
	}
	/*
	for (int i = 0; i<=sz; i++){
		if (trie[i][0] != -1){
			cerr << i << " " << trie[i][0] << " " << "0\n";
		} 
		if (trie[i][1] != -1){
			cerr << i << " " << trie[i][1] << " " << "1\n";
		} 	
	}
	*/
	dfs(0);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
