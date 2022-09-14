#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef vector<int> vi;
 
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for(int i = a; i>=b; i--)
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define sz(x) (int)((x).size())
#define pb push_back
#define all(x) x.begin(), x.end() 

const int MAX = 1e5+7, INF = 1e9+7;
vi graf[MAX], ans;
bool around[MAX][11];

void bfs(int s, int d, int c) {
	queue<int>q;
	q.push(s);
	map<int, int> dist;
	dist[s] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (!ans[v]) ans[v] = c;
		if (dist[v] == d) continue;
		for (auto x: graf[v]) {
			if (!around[x][d-dist[v]-1] && dist.find(x) == dist.end()) {
				around[x][d-dist[v]-1] = 1;
				q.push(x);
				dist[x] = dist[v]+1;
			}
			if (!ans[x]) ans[x] = c;
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	ans.assign(n+1, 0);
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	int q; cin >> q;
	vector<tuple<int, int, int>>Q;
	while (q--){
		int v, d, c; cin >> v >> d >> c;
		Q.pb({v, d, c});
	}
	reverse(all(Q));
	for (auto [v, d, c]:Q){
		bfs(v, d, c);
	}
	rep(i, 1, n+1) cout << ans[i] << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
   
	solve();
   
	return 0;
}
 
