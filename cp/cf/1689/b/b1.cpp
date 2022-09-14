//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

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

#define int long long
const int oo = 1e18, K = 30;

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	vector<bool>vis(n+2);
	vis[n+1] = 0;
	int ptr = 1, ptr2 = 2;
	for (int i = 0; i<n; i++){
		cin >> a[i];
	}
	if (n == 1){
		cout << "-1\n";
		return;
	}
	vector<int>ans(n);
	for (int i = 0; i<n; i++){
		if (!vis[ptr] && a[i] != ptr){
			ans[i] = ptr;
			vis[ptr] = 1;
			ptr++;
			while (vis[ptr]) ptr++;
			if (ptr == ptr2){
				ptr2++;
				while (vis[ptr2]) ptr2++;
			}
		} else {
			ans[i] = ptr2;
			vis[ptr2] = 1;
			ptr2++;
			while (vis[ptr2]) ptr2++;
		}
	}
	if (ans.back() > n) ans.back() = n;
	if (ans.back() == a.back()){
		swap(ans[ans.size()-1], ans[ans.size()-2]);
	}
	for (auto x: ans) cout << x << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}