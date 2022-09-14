//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

void solve(){
	int n, m; cin >> n >> m;
	vector<int>a(n+1);
	LL ans = 0LL;
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int l = 1; l<=n; l++){
		for (int r = l; r<=n; r++){
			vector<int>cnt(m+1, 0);
			for (int k = l; k<=r; k++){
				cnt[a[k]]++;
			}
			bool ok = 1;
			for (int i = 2; i<=m; i++){
				if (cnt[i] != cnt[i-1]){
					ok = 0;
					break;
				}
			}
			if (ok){
				ans++;
			}
		}
	}
	cout << ans << "\n";
}

void solve2(){
	int n, q; cin >> n >> q;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i];
	}
	const int INF = 1e9+7;
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int l, r, v; cin >> l >> r >> v;
			for (int i = l; i<=r; i++) a[i]+=v;
		} else {
			int x; cin >> x;
			int L = INF, R = -1;
			for (int i = 1; i<=n; i++){
				if (a[i] == x){
					L = min(L, i);
					R = max(R, i);
				}
			}
			if (L == INF){
				cout << "-1\n";
			} else cout << R-L << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve2();
	
	return 0;
}
