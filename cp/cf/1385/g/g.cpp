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
	vector<int>a(n), b(n), cc(n+1);
	for (int i = 0; i<n; i++){
		cin >> a[i];
		cc[a[i]]++;
	}
	for (int i = 0; i<n; i++){
		cin >> b[i];
		cc[b[i]]++;
	}
	for (int i = 1; i<=n; i++){
		if (cc[i] != 2){
			cout << "-1\n";
			return;
		}
	}
	vector<vector<int>>g(n+1);
	map<pair<int, int>, vector<int>>cnt;
	for (int i = 0; i<n; i++){
		g[a[i]].emplace_back(b[i]);
		g[b[i]].emplace_back(a[i]);
		cnt[{a[i], b[i]}].emplace_back(i+1);
	}
	vector<int>ord;
	vector<bool>vis(n+1, 0);

	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		ord.emplace_back(v);
		for (auto x: g[v]){
			if (!vis[x]){
				dfs(x);
				return;
			}
		}
	};

	vector<int>ans;
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			ord.clear();
			dfs(i);
			//debug(ord);
			vector<int>A, B;
			for (int i = 0; i<(int)ord.size(); i++){
				int nxt = ((i==ord.size()-1)?0:i+1);
				if (cnt[{ord[i], ord[nxt]}].size()){
					A.emplace_back(cnt[make_pair(ord[i], ord[nxt])].back());
					cnt[make_pair(ord[i], ord[nxt])].pop_back();
				} else {
					B.emplace_back(cnt[make_pair(ord[nxt], ord[i])].back());
					cnt[make_pair(ord[nxt], ord[i])].pop_back();
				}
			}
			if (A.size() < B.size()){
				for (auto x: A) ans.emplace_back(x);
			} else {
				for (auto x: B) ans.emplace_back(x);
			}
		}
	}
	cout << (int)ans.size() << "\n";
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