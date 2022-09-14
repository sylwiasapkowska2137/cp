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

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	a.emplace_back(oo);
	vector<int>w(n+1);
	int ans = 0;
	for (int i = 1; i<=n; i++){
		w[i] = i*(n-i+1);
		if (a[i] != a[i+1]) ans += w[i];
	}
	debug(ans);
	debug(w);
	while (q--){
		int x, val; cin >> x >> val;
		if (a[x] == val){
			cout << ans << "\n";
			continue;
		}
		if (x > 1 && a[x-1] != a[x]){
			ans -= w[x-1];
		}
		if (a[x] != a[x+1]){
			ans -= w[x];
		}
		debug(ans);
		a[x] = val;
		if (x > 1 && a[x-1] != a[x]){
			ans += w[x-1];
		}
		if (a[x] != a[x+1]){
			ans += w[x];
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