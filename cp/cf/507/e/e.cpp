/*
	Author: sysia
	12.01.2022 22:31:57
*/

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

const int MAX = 1e5+7, INF = 1e9+7;
vpii graf[MAX];
int dist[MAX][2];
vi dp, parent;
vb vis;

void bfs(int src, int n, int k){
	rep(i, 1, n+1) dist[i][k] = INF;
	vis.assign(n+1, 0);
	dist[src][k] = 0;
	vis[src] = 1;
	queue<int>q;
	q.push(src);
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (auto [x, c]: graf[v]){
			if (!vis[x]){
				vis[x] = 1;
				dist[x][k] = dist[v][k]+1;
				q.push(x);
			}
		}
	}
}

void restore(int n){
	dp.assign(n+1, 0);
	parent.assign(n+1, 0);
	queue<int>q;
	q.push(n);
	while (!q.empty()){
		int v = q.front();q.pop();
		for (auto [x, c]: graf[v]){
			if (dist[x][0]+dist[x][1] == dist[n][0] && dist[x][0]==dist[v][0]+1){
				if (dp[v] <= dp[x]+c) {
					dp[v] = dp[x]+c;
					parent[v] = x;
				}
			} else if (dist[x][0] < dist[v][0]) q.push(x);
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	int sum = 0;
	rep(i, 0, m){
		int a, b, c; cin >> a >> b >> c;
		graf[a].pb({b, c});
		graf[b].pb({a, c});
		sum+=c;
	}
	bfs(1, n, 0);
	bfs(n, n, 1);
	restore(n);

	cout << sum+dist[n][0]-2*dp[1] << "\n";
	
	set<pii>safe;
	int v = 1;
	while (v != n){
		pii x = {v, parent[v]};
		if (x.st > x.nd) swap(x.st, x.nd);
		safe.insert(x);
		v = parent[v];
	}
	rep(v, 1, n+1){
		for (auto [x, c]: graf[v]){
			if (x < v){
				if (safe.find({x, v}) == safe.end() && c){
					cout << x << " " << v << " " << 0 << "\n";
				}
				if (safe.find({x, v}) != safe.end() && !c){
					cout << x << " " << v << " " << 1 << "\n";
				}
			}
		}
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
