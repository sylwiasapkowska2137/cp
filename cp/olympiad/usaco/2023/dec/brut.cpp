//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
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
typedef pair<int, int> T;

int cross(T a, T b, T c){
	b.first -= a.first;
	b.second -= a.second;
	c.first -= a.first;
	c.second -= a.second;
	return b.first * c.second - b.second * c.first;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	int q; cin >> q;
	while (q--){
		int pos, val; cin >> pos >> val;
		a[pos] += val;
		int ans = 0;
		for (int l = 1; l <= n; l++){
			for (int r = l+1; r <= n; r++){
				bool ok = 1;
				for (int k = l+1; k < r; k++){
					if (cross(make_pair(l, a[l]), make_pair(r, a[r]), make_pair(k, a[k])) > 0){
						ok = 0;
						break;
					}
				}
				if (ok) ans++;
			}
		}
		cout << ans << "\n";
	}	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
