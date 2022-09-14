//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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

// #define int long long
const int K = 30;
vector<vector<int>>trie;
vector<int>A, B;
int sz = 1;
bool ok;

void add(int x, int b){
	int v = 0;
	int msb = -1;
	for (int i = K-1; i>=0; i--){
		if (x&(1<<i)){
			msb = i;
			break;
		}
	}
	for (int i = msb; i>=0; i--){
		int s = ((x&(1<<i))?1:0);
		if (trie[v][s] == -1) trie[v][s] = sz++;
		v = trie[v][s];
	}
	if (!b) A[v]++;
	else B[v]++;
}

void dfs(int v, int up = -1){
	for (int k = 0; k<2; k++){
		if (trie[v][k] != -1){
			dfs(trie[v][k], k);
			A[v] += A[trie[v][k]];
			B[v] += B[trie[v][k]];
		}
	}
	int t = min(A[v], B[v]);
	A[v] -= t;
	B[v] -=t;
	if (up == 1 && B[v]){
		ok = 0;
	}
}

void solve(){
	int n; cin >> n;
	int M = 2*n*K+7;
	trie.assign(M, vector<int>(2, -1));
	A.assign(M, 0);
	B.assign(M, 0);
	sz = 1;
	for (int i = 0; i<n; i++) {
		int x; cin >> x;
		add(x, 1);
	}
	for (int i = 0; i<n; i++) {
		int x; cin >> x;
		add(x, 0);
	}
	ok = 1;
	dfs(0);
	if (ok) cout << "YES\n";
	else cout << "NO\n";	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}