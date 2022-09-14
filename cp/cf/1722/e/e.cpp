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

#define int long long
const int oo = 1e18, K = 30;
const int mx = 1e3+7;

void solve(){
	int n, q; cin >> n >> q;
	vector<vector<int>>pref(mx, vector<int>(mx, 0));
	for (int i = 0; i<n; i++){
		int a, b; cin >> a >> b;
		pref[a][b] += a*b;
	}
	for (int i = 1; i<mx; i++){
		for (int j = 1; j<mx; j++){
			pref[i][j] += (pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]);
		}
	}
	while (q--){
		int a, b, c, d; cin >> a >> b >> c >> d;
		a++;b++;c--;d--;
		cout << pref[c][d] - pref[c][b-1] - pref[a-1][d] + pref[a-1][b-1] << "\n";
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