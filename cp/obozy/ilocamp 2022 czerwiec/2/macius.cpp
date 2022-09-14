//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long LL;
typedef long double LD;

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

#define int long long
const int oo = 1e18, K = 30;

const int MAX = 2137;
int rep[MAX], sz[MAX];
vector<pair<int, int>>graf[MAX];
//ustaw rep na 1, 2, ..
//sz na 1 

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}


bool Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a == b) return 0;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	rep[b] = a;
	return 1;
}

void dijkstra(int src, int n){
	vector<int>dist(n+1, oo);
	set<pair<int, int>>s; //d, v;
	s.insert({0LL, src});
	dist[src] = 0;
	while (!s.empty()){
		int v = s.begin()->second;
		int d = s.begin()->first;
		s.erase(s.begin());
		if (d > dist[v]) continue;
		for (auto [x, c]:graf[v]){ //wierzcholek, waga
			if (d+c < dist[x]){
				dist[x] = d+c;
				s.insert({dist[x], x});
			}
		}
	}
}

void solve(){
	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}
