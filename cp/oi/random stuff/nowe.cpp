#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 1e5+7;
vector<int>gt[MAX], dist, maxi;
LL ans = 0LL;
int k;

void dfs(int v){
	maxi[v] = dist[v];
	for (auto x: gt[v]) {
		dist[x] = dist[v]+1;
		dfs(x);
		maxi[v] = max(maxi[v], maxi[x]);
	}
}

void dfs2(int v){
	if (dist[v]>k){
		ans += ceil((double)maxi[v]-k/(double)k);
	} else {
		for (auto x: gt[v]) dfs2(x);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b;
	cin >> n >> k;
	dist.assign(n+1, 0);
	maxi.assign(n+1, 0);
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		gt[b].pb(a);
	}
	dfs(1);
	for (int i = 1; i<=n; i++) debug(dist[i]);
	cerr << "\n";
	for (int i = 1; i<=n; i++) debug(maxi[i]);
	dfs2(1);
	cout << ans;
	return 0;
}

