#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 5e5+7;
vector<int>graf[MAX];
int dist[2][MAX];

void bfs(int n, int start, int k){
	for (int i = 1; i<=n; i++) dist[k][i] = INT_MAX;
	queue<int>q;
	dist[k][start] = 0;
	q.push(start);
	
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (auto x: graf[v]){
			if (dist[k][x] == INT_MAX){
				dist[k][x] = dist[k][v]+1;
				q.push(x);
			}
		}	
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k, a, b, s, d;
	cin >> n >> m >> k >> s >> d;
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	bfs(n, s, 0);
	bfs(n, d, 1);
	/*
	cerr << "\n";
	for (int i = 1; i<=n; i++){
		debug(dist[0][i]);
		debug(dist[1][i]);
		cerr << "\n";
	}*/
	int ans = dist[0][d];
	for (int i = 0; i<k; i++){
		cin >> a >> b;
		ans = min(ans, min(dist[0][a]+dist[1][b], dist[1][a]+dist[0][b]));
	}
	cout << ans;
	return 0;
}

