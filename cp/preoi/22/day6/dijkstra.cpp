//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
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
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x, val) memset(x, val, sizeof(x))
#define PI 3.14159265359

int p(int a, int b){
	return a+rng()%(b-a+1);
}

const int MAX = 2e6+7;
const LL INF = 1e18;
vpii graf[MAX];
vll dist;

void dijkstra(int Z, int n){
	set<pll>s;
	dist.assign(2*n+1, INF);
	dist[Z] = 0;
	s.insert({0, Z});
	while (!s.empty()){
		LL d = s.begin()->st;
		int v = s.begin()->nd;
		s.erase(s.begin());
		if (d > dist[v]) continue;
		for (auto [x, c]:graf[v]){
			if (dist[x] > d+c){
				dist[x] = d+c;
				s.insert({dist[x], x});
			}
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	rep(i, 0, m){
		int a,b, c; cin >> a >> b >> c;
		graf[a].pb({b+n, c});
		graf[b].pb({a+n, c});
		graf[a+n].pb({b, c});
		graf[b+n].pb({a, c});
	}
	int Z, D; cin >> Z >> D;
	dijkstra(Z, n);
	if (dist[D]>=INF) dist[D] = -1;
	if (dist[D+n]>=INF) dist[D+n] = -1;
	cout << dist[D] << " " << dist[D+n] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
