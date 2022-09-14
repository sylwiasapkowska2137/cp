#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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

const int MAXN = 1e5+7, MAX = 1e5*102;
const LL INF = 1e18;
vpii G[MAXN], graf[MAX];
bool vis[MAX];
LL dist[MAX], D[MAX];

void dijkstra(int src){
	if (vis[src]) return;
	dist[src] = 0;
	set<pair<LL, int>>s;
	s.insert({0, src});
	while (!s.empty()){
		int v = s.begin()->nd;
		LL d = s.begin()->st;
		s.erase(s.begin());
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto x: graf[v]){
			if (d+x.nd < dist[x.st]){
				dist[x.st] = d+x.nd;
				s.insert({dist[x.st], x.st});
			}
		}
	}
}

void bfs(){
	queue<int>q;
	rep(i, 0, MAX) D[i] = INF;
	rep(i, 1, 51) {
		D[i+51] = 0;
		q.push(i+51);
	}
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (auto x: graf[v]){
			if (D[x.st] == INF){
				D[x.st] = D[v]+1;
				q.push(x.st);
			}
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	rep(i, 0, MAX) dist[i] = INF;
	rep(i, 0, m){
		int a, b, c;
		cin >> a >> b >> c;
		a--;b--;
		G[a].pb({b, c});
		G[b].pb({a, c});
	}
	rep(v, 0, n){
		vb vis(52, 0);
		for (auto x: G[v]){
			//krawedz od v do x.st o wadze x.nd
			int a = v*102+x.nd+51;
			int b = x.st*102+x.nd;
			graf[a].pb({b, x.nd*x.nd});
			vis[x.nd] = 1;
		}
		rep(j, 1, 51){
			if (vis[j]){
				rep(k, 1, 51){
					if (vis[k]){
						//dodac krawedz od v_j do v_k
						int a = 102*v+j;
						int b = 102*v+51+k;
						graf[a].pb({b, 2*j*k});
					}
				}
			}
		}
	}
	rep(i, 1, 51) dijkstra(i+51);
	
	bfs();
	
	vll ans(n, INF);
	
	rep(i, 0, n){
		rep(w, 1, 51){
			int x = 102*i+w;
			if (D[x]%3==0) ans[i] = min(ans[i], dist[x]);
		}
	}
	rep(i, 0, n){
		if (ans[i] == INF) cout << "-1 ";
		else cout << ans[i] << " ";
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
