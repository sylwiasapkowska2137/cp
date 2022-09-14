//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "
#define PI 3.14159265359

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const LL INF = 1e18;
const int MAX = 5e5+7;
vpii graf[MAX];
vll dist;
vb vis;

void dijkstra(int v){
	dist[v] = 0;
	set<pll>s;
	s.insert({0LL, v});
	while (!s.empty()){
		int v = s.begin()->nd;
		LL d = s.begin()->st;
		s.erase(s.begin());
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto x: graf[v]){
			if (dist[x.st] > d+x.nd){
				dist[x.st] = d+x.nd;
				s.insert({dist[x.st], x.st});
			}
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	dist.assign(n+1, INF);
	vis.assign(n+1, 0);
	rep(i, 0, m){
		int a, b, c; cin >> a >> b >> c;
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	dijkstra(1);
	rep(i, 1, n+1) {
		if (dist[i] == INF) cout << "-1\n";
		else cout << dist[i] << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
