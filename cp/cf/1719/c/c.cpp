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
	int n, Q; cin >> n >> Q;
	vector<int>a(n+1);
	deque<int>q;
	int mx = 1;
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		if (a[i] == n){
			mx = i;
		}
		q.push_back(i);
	}
	vector<vector<int>>win(n+1);
	for (int i = 1; i<mx; i++){
		int v = q.front();q.pop_front();
		int x = q.front();q.pop_front();
		if (a[v] > a[x]) swap(x, v);
		q.push_front(x);
		q.push_back(v);
		win[x].emplace_back(i);
	}
	while (Q--){
		int i, k; cin >> i >> k;
		int ans = 0;
		if (a[i] == n){
			ans = max(0LL, k-mx+1);
		} 
		for (auto x: win[i]){
			if (x <= k){
				ans++;
			}
		}
		cout << ans << "\n";
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