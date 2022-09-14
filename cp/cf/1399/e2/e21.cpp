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
	vector<vector<tuple<int, int, int>>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b, c, cost; cin >> a >> b >> c >> cost;
		cost--;
		g[a].emplace_back(b, c, cost);
		g[b].emplace_back(a, c, cost);
	}
	vector<int>sub(n+1), sum(n+1), val(n+1), cost(n+1);
	set<pair<int, int>>s;
	int ans = 0;

	function<void(int, int)>dfs = [&](int v, int pa){
		if ((int)g[v].size() == 1) {
			sub[v]++;
			ans += sum[v];
		}
		for (auto [x, c, co]:g[v]){
			if (x == pa) continue;
			sum[x] = sum[v]+c;
			val[x] = c;
			cost[x] = co;
			dfs(x, v);
			sub[v] += sub[x];
			s.insert({sub[x]*(c+1)/2, x});
		}
	};

	dfs(1, 1);
	vector<vector<int>>v(2);
	while (ans > 0){
		assert(s.size());
		auto it = prev(s.end());
		int x = it->second;
		v[cost[x]].emplace_back(sub[x] * (val[x] - val[x]/2));
		ans -= sub[x] * (val[x] - val[x]/2);
		val[x] /= 2;
		s.erase(it);
		s.insert({sub[x] * (val[x] - val[x]/2), x});
	}
	v[0].emplace_back(0);
	v[1].emplace_back(0);
	reverse(v[0].begin(), v[0].end());
	reverse(v[1].begin(), v[1].end());
	// debug(v[0]);
	// debug(v[1]);
	for (int i = 1; i<(int)v[0].size(); i++) v[0][i] += v[0][i-1];
	for (int i = 1; i<(int)v[1].size(); i++) v[1][i] += v[1][i-1];
	int ret = oo;
	for (int i = 0; i<(int)v[0].size(); i++){
		int l = 0, r = (int)v[1].size()-1, tmp = -1;
		while (r>=l){
			int mid = (l+r)/2;
			if (v[0][i] + v[1][mid] <= S){
				tmp = mid;
				l = mid+1;
			} else r = mid-1;
		}
		if (tmp != -1){
			// debug(i, tmp);
			ret = min(ret, (int)v[0].size() - i - 1 + 2 * ((int)v[1].size() - tmp - 1) );
		}
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