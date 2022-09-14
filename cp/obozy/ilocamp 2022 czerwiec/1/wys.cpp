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
	vector<vector<int>>pos(4);
	for (int i = 0; i<n; i++){
		int d; char c; cin >> d >> c;
		if (c == 'R') pos[0].emplace_back(d);
		if (c == 'B') pos[1].emplace_back(d);
		if (c == 'K') pos[2].emplace_back(d);
		if (c == 'I') pos[3].emplace_back(d);
	}
	int q; cin >> q;
	while (q--){
		int S, E; cin >> S >> E;
		int ans = oo;
		for (int mask = 0; mask<(1<<4); mask++){
			//1 - w prawo, 0 - w lewo
			int s = S, e = E;
			int curr = 0;
			for (int i = 0; i<4; i++){
				if (mask&(1<<i)){
					int L = 0, R = pos[i].size()-1;
					int p = oo;
					while (R>=L){
						int mid = (L+R)/2;
						if (pos[i][mid] >= s){
							p = mid;
							R = mid-1;
						} else L = mid+1;
					}
					if (p == oo){
						curr = oo;
						break;
					} 
					curr += abs(pos[i][p]-s);
					s = pos[i][p];
				} else {
					int L = 0, R = pos[i].size()-1;
					int p = oo;
					while (R>=L){
						int mid = (L+R)/2;
						if (pos[i][mid] <= s){
							p = mid;
							L = mid+1;
						} else R = mid-1;
					}
					if (p == oo){
						curr = oo;
						break;
					} 
					curr += abs(pos[i][p]-s);
					s = pos[i][p];
				}
			}
			if (curr >= oo) continue; 
			curr += abs(s-e);
			ans = min(curr, ans);
		}
		cout << ans << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();
	
	return 0;
}
