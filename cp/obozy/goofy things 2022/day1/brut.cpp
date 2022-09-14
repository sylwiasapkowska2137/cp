#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for(int i = a; i>=b; i--)
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define sz(x) (int)((x).size())
#define pb push_back
#define all(x) x.begin(), x.end()

const int MAX = 1e5+7, INF = 1e9+7;
vi graf[MAX], color, around;

struct Query{
	int v, d, c;
};

void bfs(int s, int d, int c, int n){
	queue<int>q;
	q.push(s);
	map<int, int>dist;
	dist[s] = 0;
	around[s] = d;
	if (!color[s]) color[s] = c;
	around[s] = max(around[s], d);
	while (!q.empty()){
		int v = q.front();q.pop();
		for (auto x:graf[v]){
			if (dist.find(x) == dist.end()){
				dist[x] = dist[v]+1;
				if (d-dist[x] <= around[x]) continue;
				if (dist[x] <= d){
					q.push(x);
					around[x] = max(around[x], d-dist[x]);
					if (!color[x]) color[x] = c;
				}
			}
		}
	}
}
 

void solve(){
	int n, m; cin >> n >> m;
	color.assign(n+1, 0);
	around.assign(n+1, -1);
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	int q; cin >> q;
	vector<Query>Q;
	rep(i, 0, q){
		int v, d, c; cin >> v >> d >> c;
		Q.pb({v, d, c});
	}
	reverse(all(Q));
	rep(i, 0, q){
		bfs(Q[i].v, Q[i].d, Q[i].c, n);
	}
	rep(i, 1, n+1) cout << color[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
