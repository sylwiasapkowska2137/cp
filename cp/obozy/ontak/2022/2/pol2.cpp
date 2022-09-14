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
const int oo = 1e18, K = 30;

typedef double ld;

struct edge{
	ld w = oo;
	int to = -1;
};

void solve(int P){
	int n; cin >> n;
	vector<pair<int, int>>p(n);
	for (int i = 0; i<n; i++){
		cin >> p[i].first >> p[i].second;
	}
	vector<vector<ld>>d(n, vector<ld>(n));
	for (int i = 0; i<n; i++){
		for (int j = i+1; j<n; j++){
			d[i][j] = d[j][i] = sqrt((p[i].first-p[j].first)*(p[i].first-p[j].first) + (p[i].second-p[j].second)*(p[i].second-p[j].second));
		}
	}
	ld all = 0;
	vector<bool>vis(n);
	vector<edge>min_e(n);
	min_e[0].w = 0;
	vector<vector<int>>g(n);
	for (int i = 0; i<n; i++){
		int v = -1;
		for (int j = 0; j<n; j++){
			if (!vis[j] && (v == -1 || min_e[j].w < min_e[v].w)){
				v = j;
			}
		}
		vis[v] = 1;
		all += min_e[v].w;
		if (min_e[v].to != -1 && P == 2) {
			g[v].emplace_back(min_e[v].to);
			g[min_e[v].to].emplace_back(v);
		}
		for (int to = 0; to < n; to++){
			if (d[v][to] < min_e[to].w){
				min_e[to] = {d[v][to], v};
			}
		}
	}
	if (P == 1) cout << all << "\n";
	else {
		

		function<void(int, int)>dfs = [&](int v, int pa){
			vector<int>a, b;
			for (auto x: g[v]){
				if (x == pa) continue;
				if (x < v) a.emplace_back(x);
				else b.emplace_back(x);
			}
			sort(a.begin(), a.end());
			sort(b.begin(), b.end());
			reverse(a.begin(), a.end());
			for (auto x: a){
				dfs(x, v);
				cout << x+1 << " " << v+1 << "\n";
			}
			for (auto x: b){
				dfs(x, v);
				cout << x+1 << " " << v+1 << "\n";
			}
		};
		

		dfs(0, 0);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed << setprecision(12);
	int p; cin >> p;
	int t = 1; cin >> t;
	while (t--) solve(p);
	
	return 0;
}