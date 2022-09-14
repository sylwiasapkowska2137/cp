#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
int n;
const int MAX = 1e5+7, Q = 2e5+8;
vector<int>graf[MAX], dist;
vector<bool>vis;
pii query[Q];

void bfs(int v){
	vis.assign(n+1, 0);
	
	vis[v] = 1;
	dist[v] = 0;
	queue<int>k;
	k.push(v);
	while (!k.empty()){
		v = k.front();
		k.pop();
		for (auto x: graf[v]){
			if (!vis[x]){
				vis[x] = 1;
				k.push(x);
				dist[x] = dist[v]+1;
			}
		}
	}
}

int losuj(int a, int b){
	return a+rand()%(b-a+1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	srand(2137);
	int m,p,a,b,c;
	cin >> n >> m >> p;
	dist.resize(n+1);
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	for (int i = 0; i<p; i++) cin >> query[i].st >> query[i].nd;
	vector<int>ans(p+1, INT_MAX);
	for (int i = 0; i<200; i++){
		c = losuj(1, n);
		bfs(c);
		for (int j = 0; j<p; j++) ans[j] = min(ans[j], dist[query[j].st]+dist[query[j].nd]);
	}
	for (int i = 0; i<p; i++) cout << ans[i] << "\n";
	return 0;
}
