//Sylwia Sapkowska
#include <bits/stdc++.h>
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

void solve(){
	int n; cin >> n;
	vector<vector<int>>a(4, vector<int>(n+1, 0));
	for (int i = 1; i<=3; i++){
		for (int j = 1; j<=n; j++){
			char c; cin >> c;
			if (c == '1') a[i][j] = 1;
		}
	}
	vector<int>sum(n+2, 0), s(n+2, 0), L(n+2, 0), R(n+2, 0);
	for (int i = 1; i<=n; i++) sum[i+1] = sum[i]+a[1][i]+a[2][i]+a[3][i]-(a[1][i]&a[2][i])-(a[2][i]&a[3][i]);
	for (int i = 1; i<n; i++){
		int u = a[1][i]&a[1][i+1];
		int m = a[2][i]&a[2][i+1];
		int d = a[3][i]&a[3][i+1];
		s[i+1] = s[i]-u-m-d+(u&m)+(m&d);
	}
	int l, r; 
	for (l = 1; l<n; l++){
		if (a[1][l]&a[2][l]&a[3][l]){
			r = l+1;
			while (r<=n && (a[1][r]&a[3][r]) && !a[2][r]) r++;
			if (r<=n && (r>l+1) && a[1][r]&a[2][r]&a[3][r]) R[r]++, L[l+1] += (l<n);
			l = r-1;
		}
	}
	for (int i = 2; i<=n; i++){
		L[i] += L[i-1];
		R[i] += R[i-1];
	}
	int q; cin >> q;
	while (q--){
		int l, r; cin >> l >> r;
		cout << sum[r+1]-sum[l]+s[r]-s[l]+max(0LL, R[r]-L[l]) << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; //cin >> t;
	while (t--) solve();
	
	return 0;
}
