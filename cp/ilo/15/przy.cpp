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
const int oo = 1e9+7, K = 30;
const int mod = 998244353;
const int nax = 101;
const int mx = 1e5+7;
vector<pair<int, int>>g[mx];
int dist[mx];
typedef pair<int, int> T;
priority_queue<T, vector<T>, greater<T>>s;

inline void read(int &x){
    int c = getchar_unlocked();
    x = 0;
    while(c<48 || c>57) c=getchar_unlocked();
    for (; c>47 && c<58; c = getchar_unlocked()){
        x=(x<<1)+(x<<3)+(c-48);
    }
}

int n;

int dijkstra(int ignore){
	s.push({0, 1});
	for (int i = 2; i<=n; i++) dist[i] = oo;
	while (s.size()){
		int v = s.top().second;
		int d = s.top().first;
		s.pop();
		if (dist[v] < d) continue;
		for (auto [x, c]: g[v]){
			if (c > ignore) continue;
			if (dist[x] > dist[v] + c){
				dist[x] = dist[v]+c;
				s.push({dist[x], x});
			}
		}
	}
	return dist[n];
}

void solve(){
	int m; read(n); read(m);
	if (n == 1){
		cout << "0\n";
		return;
	}
	for (int i = 0; i<m; i++){
		int a, b, c; read(a); read(b); read(c);
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	
	int ans = oo;
	for (int i = 100; i>1; i--){
		int x = dijkstra(i);
		if (x == oo) break;
		ans = min(ans, x+i);
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
