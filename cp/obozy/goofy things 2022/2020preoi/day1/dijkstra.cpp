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

const int MAX = 1e5+7;
vector<LL>dist[MAX];
vector<pair<int, int>>graf[MAX];

void dijkstra(int n){
	multiset<pair<LL, int>>s;
	s.insert({0, 1});
	while (!s.empty()){
		LL d = s.begin()->first;
		int v = s.begin()->second;
		//debug(v, d);
		s.erase(s.begin());
		dist[v].push_back(d);
		if (dist[v].size() > 2) continue;
		for (auto [x, c]:graf[v]){
			if (dist[x].size() >= 2) continue;
			s.insert({d+c, x});
		}
	}
	//debug(dist[n]);
	if (dist[n].size() < 2) cout << "-1\n";
	else cout << dist[n][1] << "\n";
}

void solve(){
	int n, m; cin >> n >> m;
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		graf[a].push_back({b, c});
		//graf[b].push_back({a, c});
	}
	dijkstra(n);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
