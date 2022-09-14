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
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++)cin >> a[i];
	if (n&1){
		int ans = 0;
		for (int i = 1; i<n-1; i+=2){
			ans += max(0LL, max(a[i-1], a[i+1])+1-a[i]);
		}
		cout << ans << "\n";
	} else {
		int tmp = oo;
		vector<vector<int>>ans(n+1, vector<int>(2, 0));
		for (int s = 1; s<n-1; s+=2){
			ans[s][0] = (s>=2?ans[s-2][0]:0) + max(0LL, max(a[s-1], a[s+1])+1-a[s]);
		}
		for (int s = n-2; s>=1; s-=2){
			ans[s][1] = ans[s+2][1] + max(0LL, max(a[s-1], a[s+1])+1-a[s]);
		}
		// for (int i = 1; i<n-1; i++){
			// debug(i, ans[i][0], ans[i][1]);
		// }
		for (int s = 1; s<n-1; s+=2){
			// debug(s, ans[s][0], ans[s+3][1]);
			tmp = min(tmp, ans[s][0]+ans[s+3][1]);
		}
		// debug(ans[2][1], ans[n-3][0]);
		tmp = min(tmp, ans[2][1]);
		tmp = min(tmp, ans[n-3][0]);
		cout << tmp << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}