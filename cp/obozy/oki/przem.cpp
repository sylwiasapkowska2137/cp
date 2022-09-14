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

const int MAX = 1e4+7;
vector<pair<int, int>>graf[MAX];

void dijkstra(int S, int n){
	set<pair<LL, int>>s;
	const LL INF = 1e18;
	vector<LL>dist(2*n+1, INF);
	dist[S] = 0;
	s.insert({0, S});
	while (!s.empty()){
		LL d = s.begin()->first;
		int v = s.begin()->second;
		s.erase(s.begin());
		if (d > dist[v]) continue;
		for (auto [x, c]:graf[v]){
			if (d+c < dist[x]){
				dist[x] = d+c;
				s.insert({dist[x], x});
			}
		}
	}
	cout << dist[1+n] << "\n";
}

void solve(){
	int n; cin >> n;
	vector<int>val(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> val[i];
		graf[i].push_back({i+n, val[i]/2});
	}
	if (n <= 1){
		cout << val[1]/2 << "\n";
		return;
	}
	int m; cin >> m;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		graf[a].push_back({b, c});
		graf[a+n].push_back({b+n, c});
	}
	dijkstra(1, n);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
