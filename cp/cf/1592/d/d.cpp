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
	vector<vector<int>>g(n+1);
	for (int i = 1; i<n; i++){
		int a, b; cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	auto query = [&](vector<int>v){
		cout << "? " << (int)v.size() << " ";
		for (auto x: v) cout << x << " ";
		cout << "\n";
		cout.flush();
		int x; cin >> x;
		return x;
	};

	vector<int>used(n+1), sub(n+1);
	vector<int>all(n);
	iota(all.begin(), all.end(), 1);
	int what = query(all);

	function<int(int, int)>dfs = [&](int v, int pa){
		sub[v] = 1;
		for (auto x: g[v]){
			if (x == pa || used[x]) continue;
			sub[v] += dfs(x, v);
		}
		return sub[v];
	};

	function<int(int, int, int)>get_centroid = [&](int v, int ms, int pa){
		for (auto x: g[v]){
			if (x == pa || used[x]) continue;
			if (sub[x] * 2 > ms){
				return get_centroid(x, ms, v);
			}
		}
		return v;
	};

	function<void(int)>centroid = [&](int v){
		v = get_centroid(v, dfs(v, v), v);
		dfs(v, v);
		if (sub[v] == 2){
			for (auto x: g[v]){
				if (!used[x]){
					cout << "! " << v << " " << x << "\n";
					cout.flush();
					exit(0);
				}
			}
		}

		vector<int>ask;

		function<void(int, int)>DFS = [&](int w, int pa){
			ask.emplace_back(w);
			for (auto x: g[w]){
				if (x == pa || used[x]) continue;
				DFS(x, w);
			}
		};

		vector<int>a, b;
		vector<pair<int, vector<int>>>s;
		for (auto x: g[v]){
			if (!used[x]){
				ask.clear();
				DFS(x, v);
				s.emplace_back(x, ask);
			}
		}
		sort(s.begin(), s.end(), [](auto c, auto d){return c.second.size() > d.second.size();});
		for (auto [x, idx]:s){
			if (a.size() < b.size()){
				for (auto u: idx){
					a.emplace_back(u);
				}
			} else {
				for (auto u: idx){
					b.emplace_back(u);
				}
			}
		}
		a.emplace_back(v);
		int curr = query(a);
		if (curr == what){
			for (auto x: b){
				used[x] = 1;
			}
		} else {
			a.pop_back();
			for (auto x: a){
				used[x] = 1;
			}
		}
		// used[v] = 1;
		centroid(v);
	};

	centroid(1);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}