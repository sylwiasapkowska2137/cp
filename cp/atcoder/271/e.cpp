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
	int b, c, i;
	T(){}
	T(int _b, int _c, int _i): b(_b), c(_c), i(_i) {}
};

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<vector<T>>g(n+1);
	for (int i = 1; i<=m; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].emplace_back(b, c, i);
	}
	vector<vector<int>>idx(m+1);
	for (int i = 1; i<=k; i++){
		int x; cin >> x;
		idx[x].emplace_back(i);
	}
	typedef pair<int, int> F;
	set<pair<F, int>>s;
	s.insert({{0, 0}, 1});
	vector<F>dist(n+1, {oo, oo});
	dist[1] = {0, 0};
	while (s.size()){
		auto v = s.begin()->second;
		auto [d, i] = s.begin()->first;
		s.erase(s.begin());
		if (dist[v].first < d || (dist[v].first == d && dist[v].second < i)) continue;
		for (auto [x, c, id]: g[v]){
			int xx = (lower_bound(idx[id].begin(), idx[id].end(), i)-idx[id].begin());
			if (xx >= (int)idx[id].size()) continue;
			if (dist[x].first > dist[v].first + c || (dist[x].first == dist[v].first + c && dist[x].second >= idx[id][xx])){
				dist[x].first = dist[v].first + c;
				dist[x].second = idx[id][xx];
				s.insert({dist[x], x});
			}
		}
	}
	if (dist[n].first == oo) cout << "-1\n";
	else cout << dist[n].first << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
