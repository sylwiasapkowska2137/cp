//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

struct E{
	int a, b, w, c;
	E(){}
	E(int _a, int _b, int _w, int _c){
		a = _a, b = _b, w = _w, c = _c;
	}
};

const int MAX = 30;
vector<int>graf[MAX];
vector<bool>vis;
bool tree;

void dfs(int v, int pa = -1){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (x == pa) continue;
		if (vis[x]) {
			tree = 0;
			return;
		}
		dfs(x, v);
	}
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<E>e;
	for (int i = 0; i<m; i++){
		int a, b, w, c; cin >> a >> b >> w >> c;
		e.emplace_back(a, b, w, c);
	}
	const LL INF = 1e9+7;
	LL ans = INF;
	int M;
	for (int mask = 0; mask<(1<<m); mask++){
		for (int i = 1; i<=n; i++) graf[i].clear();
		vector<E>curr;
		for (int j = 0; j<m; j++){
			if (mask&(1<<j)){
				graf[e[j].a].push_back(e[j].b);
				graf[e[j].b].push_back(e[j].a);
				curr.emplace_back(e[j]);
			}
		}
		tree = 1;
		vis.assign(n+1, 0);
		dfs(1);
		bool ok = 1;
		for (int i = 1; i<=n; i++) ok&=vis[i];
		
		if (ok && tree){
			int black = 0;
			LL currans = 0;
			for (int j = 0; j<m; j++){
				if (mask&(1<<j)){
					if (!e[j].c) black++;
					currans += e[j].w;
				}
			}
			if (black == k){
				if (ans > currans){
					ans = min(ans, currans);
					M = mask;
				}
			}
		}

	}
	if (ans == INF) cout << "-1\n";
	else {
		cout << ans << "\n";
		return;
		for (int i = 0; i<m; i++){
			if (M&(1<<i)){
				cerr << e[i].a << " " << e[i].b << " " << e[i].w << " " << e[i].c << "\n";
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
