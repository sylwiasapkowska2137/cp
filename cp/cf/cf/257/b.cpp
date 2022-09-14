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
const LL INF = 1e18;
const int MAX = 1e5+7;
vpii graf[MAX];
vll dist;
vb vis;
int ans;
set<pair<pll, bool>>s;

void dijkstra(int S, int n){
	dist.assign(n+1, INF);
	vis.assign(n+1, 0);
	dist[S] = 0;
	s.insert({{0LL, S}, 0});
	while (!s.empty()){
		int v = s.begin()->st.nd;
		LL d = s.begin()->st.st;
		bool k = s.begin()->nd;
		s.erase(s.begin());
		if (vis[v]) continue;
		if (k) ans++;
		vis[v] = 1;
		for (auto x: graf[v]){
			if (d+x.nd < dist[x.st]){
				dist[x.st] = x.nd+d;
				s.insert({{dist[x.st], x.st}, 0});
			}
		}
	}
}

void solve(){
	int n, m, k; cin >> n >> m >> k;
	rep(i, 0, m){
		int a,b, c; cin >> a >> b >> c;
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	rep(i, 0, k){
		int a, b; cin >> a >> b;
		s.insert({{b, a}, 1});
	}
	dijkstra(1, n);
	cout << k-ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
