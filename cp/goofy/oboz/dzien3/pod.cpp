#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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

const int MAX = 3e5+7, INF = 1e9+7;
vi graf[MAX], dist;
vb vis;
int n;

void bfs(int src){
	queue<int>q;
	dist.assign(n+1, INF);
	vis.assign(n+1, 0);
	
	dist[src] = 0;
	q.push(src);
	vis[src] = 1;
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (auto x: graf[v]){
			if (!vis[x]){
				vis[x] = 1;
				dist[x] = dist[v] + 1;
				q.push(x);
			}
		}
	}
}

void solve(){
	int m; cin >> n >> m;
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	int a, b, x; cin >> a >> b >> x;
	bfs(a);
	int first = dist[b];
	bfs(x);
	
	int second = dist[a]+dist[b];
	if (first == second) cout << "TAK\n";
	else cout << "NIE\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
