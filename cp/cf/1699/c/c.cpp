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
const int mod = 1e9+7;

int mul(int a, int b){
	return (a*b)%mod;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	vector<int>pos(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	int ans = 1;
	int l = pos[0], r = pos[0];
	int cnt = 0;
	for (int i = 1; i<n; i++){
		if (pos[i] > l && pos[i] < r){
			ans = mul(ans, cnt);
		} else {
			cnt += l - min(l, pos[i]);
			cnt += max(r, pos[i]) - r;
			l = min(l, pos[i]);
			r = max(r, pos[i]);
		}
		cnt--;
		// debug(l, r, cnt);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
