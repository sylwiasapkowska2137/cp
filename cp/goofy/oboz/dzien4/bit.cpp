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

const int MAX = 1e6+7, INF = 1e9+7;
vi dist[3], graf[MAX];
vb vis;
int n;

void bfs(int src, int k){
	dist[k].assign(n+1, INF);
	vis.assign(n+1, 0);
	dist[k][src] = 0;
	vis[src] = 1;
	queue<int>q;
	q.push(src);
	while (!q.empty()){
		int v = q.front();q.pop();
		for (auto x: graf[v]){
			if (!vis[x]){
				vis[x] = 1;
				q.push(x);
				dist[k][x] = dist[k][v]+1;
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
	int a, b, c; cin >> a >> b >> c;
	bfs(a, 0);
	bfs(b, 1);
	bfs(c, 2);
	int ans = INT_MAX;
	rep(i, 1, n+1) ans = min(ans, dist[0][i]+dist[1][i]+dist[2][i]);
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
