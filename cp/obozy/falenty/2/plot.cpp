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
const int oo = 1e18, oo2 = 1e9+7, K = 20;
const int mod = 998244353;

void solve(){
	int n; cin >> n;
	vector<int>a(n+1), pos(n+1);
	vector<vector<int>>st(n+1, vector<int>(K));
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	vector<int>lg(n+2);
	lg[1] = 0;
	for (int i = 2; i<=n; i++) lg[i] = lg[i/2]+1;
	for (int i = 1; i<=n; i++){
		st[i][0] = a[i];
	}
	for(int h = 1; h < K; h++){
		for(int i = 1; i <= n - (1 << h) + 1; i++){
			st[i][h] = max(st[i][h - 1], st[i + (1 << (h - 1))][h - 1]);
		}
	}
	auto query = [&](int l, int r){
		int len = lg[r-l+1];
		return max(st[l][len], st[r-(1<<len)+1][len]);
	};
	int ans = 0;
	function<void(int, int)> rec = [&](int l, int r){
		if (r-l < 2) return;
		int mx = query(l, r);
		int x = pos[mx];
		int d1 = x-l+1, d2 = r-x+1;
		if (d1 < d2){
			for (int i = l; i<x; i++){
				if (pos[mx-a[i]] > x && pos[mx-a[i]] <= r){
					ans++;
				}
			}
		} else {
			for (int i = x+1; i<=r; i++){
				if (pos[mx-a[i]] < x && pos[mx-a[i]] >= l){
					ans++;
				}
			}
		}
		rec(x+1, r);
		rec(l, x-1);
	};
	rec(1, n);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
