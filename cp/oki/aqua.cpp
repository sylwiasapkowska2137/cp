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

const int oo = 1e9+7;

void solve(){
	int n, k; cin >> n >> k;
	int m = 2*n;
	vector pref(m+1, vector<long long>(m+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			int x; cin >> x;
			pref[i+j-1][j-i+n] = x;
		}
	}
	// for (int i = 1; i<=m; i++){
	// 	for (int j = 1; j<=m; j++){
	// 		cerr << pref[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	// return;
	for (int i = 1; i<=m; i++){
		for (int j = 1; j<=m; j++){
			pref[i][j] = pref[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
		}
	}
	while (k--){
		int aa, bb, r; cin >> aa >> bb >> r;
		int a = aa+bb-1;
		int b = bb-aa+n;
		int A = max(1, a-r);
		int B = max(1, b-r);
		int C = min(m, a+r);
		int D = min(m, b+r);
		// debug(A, B, C, D);
		cout << pref[C][D] - pref[C][B-1] - pref[A-1][D] + pref[A-1][B-1] << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
