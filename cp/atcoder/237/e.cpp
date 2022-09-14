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

const int MAX = 2e5+7;
const LL INF = 1e18;
vpll graf[MAX];

void dijkstra(int S, int n){
	vll dist(n+1, INF);
	set<pll>s;
	s.insert({0LL, S});
	dist[S] = 0LL;
	while (!s.empty()){
		LL d = s.begin()->st;
		int v = s.begin()->nd;
		s.erase(s.begin());
		if (dist[v] < d) continue;
		for (auto [x, c]: graf[v]){
			if ((LL)c+d < dist[x]){
				dist[x] = (LL)c+d;
				s.insert({dist[x], x});
			}
		}
	}
	debug(dist);
	LL ans = 0;
	rep(i, 1, n+1) ans = max(ans, -dist[i]);
	cout << ans << "\n";
}

void solve(){
	int n, m; cin >> n >> m;
	vll val(n+1);
	rep(i, 1, n+1) cin >> val[i];
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		if (val[a] < val[b]) swap(a, b);
		graf[b].pb({a, 2LL*(val[a]-val[b])});
		graf[a].pb({b, val[b]-val[a]});
	}
	rep(v, 1, n+1){
		for (auto [x, c]: graf[v]){
			debug(v, x, c);
		}
	}
	dijkstra(1, n);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
