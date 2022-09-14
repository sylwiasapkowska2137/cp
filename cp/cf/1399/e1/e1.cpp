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
	int n, S; cin >> n >> S;
	vector<vector<pair<int, int>>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	vector<int>sub(n+1), sum(n+1), val(n+1);
	set<pair<int, int>>s;
	int ans = 0, ret = 0;

	function<void(int, int)>dfs = [&](int v, int pa){
		if ((int)g[v].size() == 1) {
			sub[v]++;
			ans += sum[v];
		}
		for (auto [x, c]:g[v]){
			if (x == pa) continue;
			sum[x] = sum[v]+c;
			val[x] = c;
			dfs(x, v);
			sub[v] += sub[x];
			s.insert({sub[x]*(c+1)/2, x});
		}
	};

	dfs(1, 1);
	while (ans > S){
		assert(s.size());
		auto it = prev(s.end());
		int x = it->second;
		ans -= sub[x] * (val[x] - val[x]/2);
		val[x] /= 2;
		ret++;
		s.erase(it);
		s.insert({sub[x] * (val[x] - val[x]/2), x});
	}
	cout << ret << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}