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

const LL INF = 1e18;

LL dijkstra(int A, int B, vector<vector<pair<int, int>>>&graf, int n){
	vector<LL>dist(n+1, INF);
	set<pair<LL, int>>s;
	dist[A] = 0;
	s.insert({0, A});
	while (!s.empty()){
		LL d = s.begin()->first;
		int v = s.begin()->second;
		s.erase(s.begin());
		if (dist[v] < d) continue;
		for (auto [x, c]:graf[v]){
			if (d+c < dist[x]){
				dist[x] = d+c;
				s.insert({dist[x], x});
			}
		}
	}
	return dist[B];
}

void solve(){
	int n, m; cin >> n >> m;
	vector<vector<pair<int, int>>>graf(n+1);
	for (int i = 0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		graf[a].push_back({b, c});
	}
	int A, B; cin >> A >> B;
	LL ans = dijkstra(A, B, graf, n);
	if (ans == INF) cout << "NO\n";
	else cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << "Zrobiłem to zadanie i się z tego cieszę";
	return 0;
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
