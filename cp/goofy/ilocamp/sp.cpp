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

const int MAX = 2007, INF = 1e9+7;
vi graf[MAX], dist;
int ans = INF;

void bfs1(int s){
	queue<int>q;
	dist[s] = 0;
	q.push(s);
	int tmp = 0;
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (auto x: graf[v]){
			if (dist[x] == INF){
				dist[x] = dist[v]+1;
				tmp = max(tmp, dist[x]);
				q.push(x);
			}
		}
	}
	ans = min(ans, 2*tmp);
}

void bfs2(int a, int b){
	dist[a] = dist[b] = 0;
	queue<int>q;
	q.push(a);
	q.push(b);
	int tmp = 0;
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (auto x: graf[v]){
			if (dist[x] == INF){
				dist[x] = dist[v]+1;
				tmp = max(tmp, dist[x]);
				q.push(x);
			}
		}
	}
	ans = min(ans, 2*tmp+1);
}

void solve(){
	int n, m; cin >> n >> m;
	vpii edges;
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
		edges.pb({a, b});
	}
	rep(i, 1, n+1){
		dist.assign(n+1, INF);
		bfs1(i);
	}
	for (auto x: edges){
		dist.assign(n+1, INF);
		bfs2(x.st, x.nd);
	}
	LD w = ans/2.0;
	cout << setprecision(1) << fixed << w << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
