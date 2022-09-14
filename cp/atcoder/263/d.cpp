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
const int oo = 1e18, K = 30;

void solve(){
	int n, L, R; cin >> n >> L >> R;
	vector<int>a(n+1), pref(n+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		pref[i] = pref[i-1]+a[i];
	}
	int ans = pref[n];
	ans = min(ans, n*min(L, R));
	
	vector<int>p(n+1);
	for (int i = 1; i<=n; i++){
		p[i] = i*L - pref[i];
		p[i] = min(p[i], p[i-1]);
	}
	vector<int>s(n+1);
	for (int i = 1; i<=n; i++){
		s[i] = (n-i+1)*R-(pref[n]-pref[i-1]);
		if (s[i] < n) s[i] = min(s[i], s[i+1]);
	}
	// debug(p, s);
	for (int i = 1; i<n; i++){
		ans = min(ans, pref[n]+p[i]+s[i+1]);
	}
	for (int i = 1; i<=n; i++){
		ans = min(ans, pref[n]+s[i]);
		ans = min(ans, pref[n]+p[i]);
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
