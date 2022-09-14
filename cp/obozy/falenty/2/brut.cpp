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
	int n; cin >> n;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) {
		char c; cin >> c;
		a[i] = (c-'0');
	}
	if (n == 1){
		cout << "0\n";
		return;
	}
	int ans = 0;
	while (1){
		vector<int>b(n+1);
		bool any = 0;
		for (int i = 1; i<n; i++){
			if (a[i] == 2 && a[i+1] == 1){
				b[i] = 1, b[i+1] = 2;
				any = 1;
			}
		}
		if (!any) break;
		for (int i = 1; i<=n; i++){
			if (!b[i]){
				b[i] = a[i];
			}
		}
		swap(a, b);
		ans++;
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
