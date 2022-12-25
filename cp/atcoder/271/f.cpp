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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;
const int mx = 22;
int A[mx][mx];
int ans;
vector<int> values[mx][mx];
int n; 

void backtrack_down(int a, int b, int v){
	if (b == n-a+1){
		values[a][b].emplace_back(v);
		return;
	}
	if (a+1 <= n) backtrack_down(a+1, b, v^A[a+1][b]);
	if (b+1 <= n) backtrack_down(a, b+1, v^A[a][b+1]);
}

void backtrack_up(int a, int b, int v){
	if (b == n-a+1){
		int y = (int)(lower_bound(values[a][b].begin(), values[a][b].end(), (v^A[a][b]))-values[a][b].begin());
		int z = (int)(upper_bound(values[a][b].begin(), values[a][b].end(), (v^A[a][b]))-values[a][b].begin());
		if (y < (int)values[a][b].size()) {
			ans += z-y;
		}
		return;
	}
	if (a - 1 >= 1) backtrack_up(a-1, b, v^A[a-1][b]);
	if (b - 1 >= 1) backtrack_up(a, b-1, v^A[a][b-1]);
}

void solve(){
	cin >> n;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin >> A[i][j];
		}
	}
	backtrack_down(1, 1, A[1][1]);
	for (int a = 1; a <= n; a++){
		for (int b = 1; b <= n; b++){
			sort(values[a][b].begin(), values[a][b].end());
		}
	}
	backtrack_up(n, n, A[n][n]);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
