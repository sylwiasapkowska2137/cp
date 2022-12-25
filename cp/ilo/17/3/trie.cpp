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

struct T{
	int a, b; char c;
	T(){}
	T(int _a, int _b, char _c){
		a = _a, b = _b, c = _c;
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<T>edge;
	vector<vector<pair<int, char>>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; char c; cin >> c;
		edge.emplace_back(a, b, c);
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	
	vector<int>order, pre(n+1), post(n+1);
	int t = 0;
	set<pair<int, int>>s;
	vector<vector<int>>cnt(n+1, vector<int>(K));
	int bad = 0;
	auto ti = [&](char c){
		return (int)(c-'a');
	};

	function<void(int, int)>dfs = [&](int v, int pa){
		pre[v] = t++;
		order.emplace_back(v);
		for (auto [x, c]:g[v]){
			if (x == pa) {
				cnt[v][ti(c)]++;
				continue;
			}
			cnt[v][ti(c)]++;
			dfs(x, v);
		}
		post[v] = t++;
		order.emplace_back(v);
	};

	dfs(1, 1);
	for (int v = 1; v <= n; v++){
		for (int i = 0; i<K; i++){
			if (cnt[v][i] >= 3){
				bad++;
			}
		}
	}

	while (q--){
		int idx; char d; cin >> idx >> d;
		--idx;
		auto [a, b, c] = edge[idx];
		cnt[a][ti(c)]--;
		if (cnt[a][ti(c)] < 3) bad--;
		cnt[b][ti(c)]--;
		if (cnt[b][ti(c)] < 3) bad--;

		cnt[a][ti(d)]++;
		if (cnt[a][ti(d)] >= 3) bad++;
		cnt[b][ti(d)]++;
		if (cnt[b][ti(d)] >= 3) bad++;
		
		if (bad){
			cout << "0\n";
			continue;
		}
	}

}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
