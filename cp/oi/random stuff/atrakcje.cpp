#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define dbg if(0)

const int MAX = 2e4+2, K = 22, INF = 1e9+7;
int n, m, k;
vector<pii>graf[MAX];
int dist[MAX], d[K][K];
vector<bool>vis;
int dp[K][(1<<K)+1];
vector<int>ogr;

/*
int brut(){
	int ans = INT_MAX;
	vector<int>p(k);
	for (int i = 0; i<(int)p.size(); i++) p[i] = i;
	do{
		//for (auto x: p) debug(x);
		//cerr << "\n";
		bool ok = 0;
		vector<int>pos(k);
		for (int i = 0; i<(int)p.size(); i++) pos[p[i]] = i;
		for (auto x: order){
			if (pos[x.st-2]>=pos[x.nd-2]) ok = 1;
		}
		if (ok) continue;
		int tmp = d[p[0]+2][1] + d[p[k-1]+2][k+2];
		for (int i = 1; i<(int)p.size(); i++) tmp+=d[p[i]+2][p[i-1]+2];
		//debug(tmp);
		ans = min(ans, tmp);
	} while (next_permutation(p.begin(), p.end()));
	return ans;
}*/

void dijkstra(int start, int nr){
	for (int i = 1; i<=n; i++) dist[i] = INF;
	vis.assign(n+1, 0);
	set<pii>s;
	dist[start] = 0;
	s.insert({0, start});
	while(!s.empty()){
		int v = s.begin()->nd;
		int d = s.begin()->st;
		s.erase(s.begin());
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto x: graf[v]){
			if (dist[v]+x.nd < dist[x.st]){
				dist[x.st] = dist[v]+x.nd;
				s.insert({dist[x.st], x.st});
			}
		}
	}
	for (int i = 1; i<=k+1; i++)d[nr][i] = dist[i];
	d[nr][k+2] = dist[n];
}

int solve(){
	for (int i = 1; i<=k+2; i++) for (int j = 0; j<(1<<k); j++) dp[i][j] = INF;
	for (int x = 2; x<=k+1; x++) if (!ogr[x]) dp[x][(1<<(x-2))] = d[1][x];
	for (int x = 1; x<(1<<k); x++){
		for (int y = 2; y<=k+1; y++){
			if (!(x&(1<<(y-2))) && (ogr[y]|x) == x) {
				for (int z = 2; z<=k+1; z++){
					if (x&(1<<(z-2)))  dp[y][x|(1<<(y-2))] = min(dp[y][x|(1<<(y-2))], d[z][y] + dp[z][x]);
				}
			}
		}
	}
	int res = INF;
	for (int i = 2; i<=k+1; i++) {
		res = min(res, dp[i][(1<<k)-1]+d[i][k+2]);
		//debug(dp[i][(1<<k)-1]);
		//debug(d[i][k+2]);
		//cerr << "\n";
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	int a, b, c, g;
	for (int i = 0; i<m; i++){
		cin >> a >> b >> c;
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	cin >> g;
	ogr.assign(k+1, 0);
	for (int i = 0; i<g; i++){
		cin >> a >> b;
		ogr[b] |= (1<<(a-2));
	}
	for (int i = 1; i<=k+1; i++) dijkstra(i, i);
	dijkstra(n, k+2);
	//cout << brut() << "\n";
	cout << solve() << "\n";
	return 0;
}
