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
	vector<int>r(n), c(n);
	for (int i = 0; i<n; i++){
		cin >> c[i] >> r[i];
	}
	vector<int>curr = c;
	int q; cin >> q;
	vector<int>que(12, -1);
	for (int i = 0; i<q; i++){
		int t, h; cin >> t >> h;
		que[t] = h;
	}
	int ans = 0;
	for (int i = 0; i<que.size(); i++){

		if (que[i] != -1){
			debug(c);
			int v = que[i];
			for (int j = 0; j<n; j++){
				int x = min(c[j], v);
				c[j] -= x;
				v -= x;
			}
			if (v){
				debug(i, v);
			}
			ans += v;
		}
		for (int j = 0; j<n; j++) c[j] = min(curr[j], c[j]+r[j]);
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