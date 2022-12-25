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
	vector<pair<int, int>>a;
	for (int i = 1; i<=n; i++){
		int x; cin >> x;
		a.emplace_back(x, i);
	}
	sort(a.begin(), a.end());
	vector<int>b(n+1);
	for (int i = 0; i<n; i++) b[a[i].second] = i+1;
	// debug(b);
	vector<int>vis(n+1);
	vector<vector<int>>cycles;
	vector<int>curr;
	function<void(int)>dfs = [&](int v){
		vis[v] = 1;
		curr.emplace_back(v);
		if (!vis[b[v]]) dfs(b[v]);
	};
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			curr.clear();
			dfs(i);
			cycles.emplace_back(curr);
		}
	}
	// debug(cycles);
	int mx = 0;
	for (auto x: cycles) mx = max(mx, (int)x.size());
	if (mx == 1){
		cout << "0\n";
		return;
	}
	// cerr << "--------\n";
	if (mx > 2){
		cout << "2\n";
		vector<pair<int, int>>swaps;
		for (auto x: cycles){
			// debug(x);
			int L = 0, R = (int)x.size()-1;
			while (R-L>=1){
				swaps.emplace_back(x[L], x[R]);
				L++;R--;
			}
		}
		// debug(swaps);
		vector<int>pos(n+1);
		for (int i = 1; i<=n; i++) pos[b[i]] = i;
		cout << (int)swaps.size()*2 << "\n";
		for (int i = 0; i<(int)swaps.size(); i++) cout << pos[swaps[i].first] << " ";
		for (int i = (int)swaps.size()-1; i>=0; i--) cout << pos[swaps[i].second] << " ";
		cout << "\n";
		for (auto [x, y]: swaps) swap(b[pos[x]], b[pos[y]]);
		// debug(b);
	} else {
		cout << "1\n";
	}
	vector<int>ans;
	for (int i = 1; i<=n; i++){
		if (b[b[i]] == i && b[i] < i){
			ans.emplace_back(i);
		}
	}
	int m = (int)ans.size();
	for (int i = m-1; i>=0; i--) ans.emplace_back(b[ans[i]]);
	for (int i = 0; i<m; i++){
		swap(b[ans[i]], b[ans[(int)ans.size()-1-i]]);
	}
	cout << (int)ans.size() << "\n";
	for (auto x: ans) cout << x << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
