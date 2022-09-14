#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pb push_back
#define st first
#define nd second
#define pii pair <int, int>
#define debug(x) cerr << x << " "

const int MAX = 1e6+7;
vector <int> graf[MAX];
vector <bool> vis;
vector <int> cost;
LL res = 0, cnt = 0;

void dfs(int v){
	vis[v] = 1;
	cnt+=(LL)cost[v];
	res = max(cnt, res);
	for (auto x: graf[v]){
		if (!vis[x]) dfs(x);
	}
	cnt-=cost[v];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b;
	cin >> n;
	vis.assign(n+1, false);
	cost.resize(n+1);
	for (int i = 1; i<=n; i++) cin >> cost[i];
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfs(1);
	cout << res;
	return 0;
}
