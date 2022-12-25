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
	int n, k; cin >> n >> k;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	int L = 0, R = oo;
	int ans = 0;
	while (R >= L){
		int mid = (L+R)/2;
		//czy przejscie mid razy w kółko zje wiecej niz K jablek
		int cnt = 0;
		for (int i = 0; i<n; i++){
			cnt += min(mid, a[i]);
		}
		if (cnt <= k){
			ans = mid;
			L = mid+1;
		} else {
			R = mid-1;
		}
	}
	for (int i = 0; i<n; i++){
		int x = min(ans, a[i]);
		k -= x;
		a[i] -= x;
	}
	for (int i = 0; i<n; i++){
		if (a[i] && k){
			a[i]--;
			k--;
		}
	}
	for (int i = 0; i<n; i++) cout << a[i] << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
