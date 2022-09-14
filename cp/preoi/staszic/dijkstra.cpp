#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define ULL unsigned LL
#define st first
#define nd second
#define pii pair <int, int>
#define pli pair<LL, int>
#define pb push_back
#define debug(x) cerr << x << " "

const int MAX = 5e5+7;
const LL INF = 1e18;
vector <pii> graf[MAX];
vector <LL> dist;
vector <bool> vis;

void dijkstra(){
	dist[1] = 0;
	set <pair <LL, int> > s;
	s.insert({0, 1});
	while (!s.empty()){
		int v = s.begin()->nd;
		LL d = s.begin()->st;
		s.erase(s.begin());
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto u: graf[v]){
			if (d + u.nd < dist[u.st]){
				dist[u.st] = d+u.nd;
				s.insert({dist[u.st], u.st});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0; i<m; i++){
		cin >> a >> b >> c;
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	dist.assign(n+1, INF);
	vis.assign(n+1, false);
	dijkstra();
	for (int i = 1; i<=n; i++) {
		if (dist[i] == INF) cout << "-1\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}


