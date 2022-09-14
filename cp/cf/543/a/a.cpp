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

int mod;

void add(int &a, int b){
	a += b;
	a %= mod;
}

void solve(){
	int n, m, bug; cin >> n >> m >> bug >> mod;
	vector<int>a(n+1);
	vector<vector<int>>help(m+1, vector<int>(bug+1, 0));
	help[0][0] = 1;
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			for (int b = 0; b<=bug; b++){
				if (b >= a[i]) add(help[j][b], help[j-1][b-a[i]]);
			}
		}
	}
	int ans = 0;
	for (int b = 0; b<=bug; b++){
		add(ans, help[m][b]);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}