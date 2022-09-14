//Sylwia Sapkowska
#include <bits/stdc++.h>
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
//aaaa:33

void solve(){
	int n; cin >> n;
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector<int>sub(n+1), par(n+1);
	vector<int>ord(n);
	iota(ord.begin(), ord.end(), 1);
	
	function<void(int, int)>dfs = [&](int v, int pa){
		sub[v] = 1;
		par[v] = pa;
		for (auto x: g[v]){
			if (x == pa) continue;
			dfs(x, v);
			sub[v] += sub[x];
		}
	};

	dfs(1, 0);
	sort(ord.begin(), ord.end(), [&](auto a, auto b){return sub[a] > sub[b];});
	//debug(ord);
	vector<int>who(n+1);
	for (int i = 0; i<n; i++) who[ord[i]] = i;
	vector<int>ans(n+1);

	function<int(int)>solve = [&](int k){
		if (k == 1) return n;
		if (n < k*2) return 1LL;
		int L = 0, R = n-1, idx = 0;
		while (R>=L){
			int m = (L+R)/2;
			if (sub[ord[m]] >= k){
				idx = m;
				L = m+1;
			} else {
				R = m-1;
			}
		}
		//debug(idx);
		vector<int>curr(idx+1);
		for (int i = 0; i<(int)curr.size(); i++) curr[i] = sub[ord[i]];
		//debug(curr);
		int ans = 0;
		for (int i = (int)curr.size()-1; i>=0; i--){
			if (curr[i] >= k){
				curr[i] = 0;
				ans++;
			}
			curr[who[par[ord[i]]]] -= (sub[ord[i]]-curr[i]);
			//debug(curr);
		}
		//debug(ans);
		return ans;
	};
	
	// for (int i = 1; i<=n; i++){
	// 	debug(solve(i));
	// }

	function<void(int, int, int, int)>rek = [&](int l, int r, int lx, int rx){
		//w jakim przedziale jest ans[l...r], wynik znajduje sie w przedziale [lx, rx];
		if (l > r) return;
		if (lx == rx){
			for (int i = l; i<=r; i++) ans[i] = lx;
			return;
		}
		int m = (l+r)/2;
		ans[m] = solve(m);

		rek(l, m-1, ans[m], rx);
		rek(m+1, r, lx, ans[m]);
	};

	rek(1, n, 1, n);
	for (int i = 1; i<=n; i++){
		cout << ans[i] << "\n";
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
