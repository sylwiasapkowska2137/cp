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
	vector<int>a(n), b(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	for (int i = 0; i<n; i++) cin >> b[i];
	vector<vector<int>>g(n+1);
	for (int i = 0; i<n; i++){
		g[a[i]].emplace_back(b[i]);
	}

	int cnt;
	vector<bool>vis(n+1);

	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		cnt++;
		for (auto x: g[v]){
			if (!vis[x]){
				dfs(x);
			}
		}
	};

	vector<int>tab;
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			cnt = 0;
			dfs(i);
			tab.emplace_back(cnt);
		}
	}
	sort(tab.begin(), tab.end());
	int ans = 0;
	int L = 1, R = n;
    vector<vector<int>>cycle;
	for (auto &x: tab){
		vector<int>curr;
        if (x&1){
            x--;
            curr.emplace_back(-1);
        }
		for (int j = x; j>0; j--){
			if ((j-x)&1){
				curr.emplace_back(L++);
			} else {
				curr.emplace_back(R--);
			}
		}
        cycle.emplace_back(curr);
    }
    for (auto x: cycle){
        if (x[0] == -1){
            x[0] = R--;
        }
        for (int i = 0; i<(int)x.size(); i++){
            int nxt = (i==(int)x.size()-1?0:i+1);
            ans += abs(x[i]-x[nxt]);
        }
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