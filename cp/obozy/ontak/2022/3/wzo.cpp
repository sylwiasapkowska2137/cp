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

// #define int long long
const int oo = 2e9+1, K = 30;

struct edge{
	int a, b, c;
	edge(int _a = 0, int _b = 0, int _c = 0){
		a = _a;
		b = _b;
		c = _c;
	}
};

vector<int>rep, sz;
	
int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

const int M = 6001;
int d[M][M][2];
vector<vector<int>>tab;

bool Union(int a, int b, int c, int ww){
	a = Find(a);
	b = Find(b);
	if (a == b) return 0;
	if (tab[a].size() < tab[b].size()) swap(a, b);
	for (auto x: tab[b]){
		for (auto y: tab[a]){
			d[x][y][ww] = c;
			d[y][x][ww] = c;
		}
	}
	for (auto x: tab[b]) tab[a].emplace_back(x);
	rep[b] = a;
	return 1;
}


void solve(){
	int n, m; cin >> n >> m;
	vector<edge>e[2];
	for (int i = 0; i<m; i++){
		int a, b, w, c; cin >> a >> b >> w >> c;
		e[c].emplace_back(a, b, w);
	}
	tab.resize(n+1);
	for (int ww = 0; ww<2; ww++){
		rep.resize(n+1);
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=n; j++){
				d[i][j][ww] = -1;
			}
		}
		for (int i = 1; i<=n; i++) tab[i] = {i};
		iota(rep.begin(), rep.end(), 0);	
		sort(e[ww].begin(), e[ww].end(), [&](auto a, auto b){return a.c < b.c;});
		for (auto [a, b, c]:e[ww]) Union(a, b, c, ww);
	}
	int ans = oo;
	for (int i = 1; i<=n; i++){
		for (int j = i+1; j<=n; j++){
			if (d[i][j][0] == -1 || d[i][j][1] == -1) continue;
			ans = min(ans, d[i][j][0]+d[i][j][1]);
		}
	}
	if (ans == oo) cout << "-1\n";
	else cout << ans << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}