#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 5007*2;
const short int INF = SHRT_MAX;
vector <int> graf[MAX];
unsigned short int dist[MAX/2][MAX];
vector <bool> vis;
queue <int> q;

void bfs(int s){
	dist[s][s] = 0;
	q.push(s);
	vis[s] = 1;
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (auto x: graf[v]){
			if (!vis[x]){
				vis[x] = 1;
				dist[s][x] = dist[s][v]+1;
				q.push(x);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, k, a, b, c;
	cin >> n >> m >> k;
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b+n);
		graf[b+n].pb(a);
		graf[a+n].pb(b);
		graf[b].pb(a+n);
	}
	for (int i = 1; i<=n; i++)	for (int j = 1; j<=2*n; j++) dist[i][j] = INF;
	for (int i = 1; i<=n; i++){
		vis.assign(2*n+1, 0);
		bfs(i);
	}
	while (k--){
		cin >> a >> b >> c;
		if (c&1) {
			if (dist[a][b+n]<=c && dist[a][b+n]!=INF && graf[a].size()!=0) cout << "TAK\n";
			else cout << "NIE\n";
		} else {
			if (dist[a][b]<=c && dist[a][b]!=INF && graf[a].size()!=0) cout << "TAK\n";
			else cout << "NIE\n";
		}
	}
	return 0;
}
