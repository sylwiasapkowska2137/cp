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
	int d, v, mask;
	T(){}
	T(int _d, int _v, int _mask): d(_d), v(_v), mask(_mask) {}
	bool operator < (const T &he)const {return d == he.d ? mask < he.mask : d < he.d;}
	bool operator == (const T &he) const {return d == he.d && mask == he.mask && v == he.v;}
};

struct edge{
	int v, mask, c;
	edge(){}
	edge(int _v, int _mask, int _c){v = _v, mask = _mask, c = _c;}
};

void solve(){
	int n, e, p, k; cin >> n >> e >> p >> k;
	vector<int>m(n+1);
	for (int i = 0; i<k; i++){
		int v, ile; cin >> v >> ile;
		int curr = 0;
		for (int j = 0; j<ile; j++){
			int x; cin >> x;
			curr += (1<<(x-1));
		}
		m[v] |= curr;
	}
	
	vector<vector<edge>>g(n+1);
	for (int i = 0; i<e; i++){
		int a, b, c, s; cin >> a >> b >> c >> s;
		int mask = 0;
		for (int j = 0; j<s; j++){
			int x; cin >> x; 
			mask += (1<<(x-1));
		}
		g[a].emplace_back(b, c, mask);
		g[b].emplace_back(a, c, mask);
	}
	multiset<T>s;
	s.insert(T(0, 1, m[1]));
	vector<vector<int>>dist(n+1, vector<int>((1<<p)+3, oo));
	dist[1][m[1]] = 0;
	while (s.size()){
		auto [d, v, mask] = *s.begin();
		s.erase(s.begin());
		if (dist[v][mask] < d) continue;
		for (auto [x, c, mask2]: g[v]){
			if ((mask&mask2) == mask2){
				int newmask = (mask|m[x]);
				if (dist[x][newmask] > d + c){
					dist[x][newmask] = d+c;
					s.insert(T(dist[x][newmask], x, newmask));
				}
			}
		}
	}
	int ans = oo;
	for (int i = 0; i<(1<<p); i++) ans = min(ans, dist[n][i]);
	if (ans == oo) cout << "-1\n";
	else cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
