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

void solve(){
	int n, q; cin >> n;
	vector<int>a(n+1);
	int T = -1;
	int val;
	vector<int>czas(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	cin >> q;
	for (int i = 0; i<q; i++){
		int t; cin >> t;
		if (t == 1){
			int v; cin >> v;
			T = i;
			val = v;
		} else if (t == 2){
			int pos, val; cin >> pos >> val;
			if (czas[pos] < T){
				a[pos] = 0;
			}
			a[pos] += val;
			czas[pos] = i;
		} else {
			int ans = 0;
			int idx; cin >> idx;
			if (T != -1){
				ans = val;
			}
			if (czas[idx] > T){
				ans += a[idx];
			}
			cout << ans << "\n";
		}
	}

}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
