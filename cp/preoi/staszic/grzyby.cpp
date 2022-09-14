#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const LL MOD = 1e9+9;
const int MAX = 1e6+7;
vector <int> ans, graf[MAX];
vector <bool> vis;
vector <LL> ile;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]) if (!vis[x]) dfs(x);
	ans.pb(v);
}

int main(){
	fastio;
	int n, m, a, b, start, meta;
	cin >> n >> m >> start >> meta;
	vis.assign(n+1, false);
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[b].pb(a);
	}
	for (int i = 1; i<=n; i++){
		if (!vis[i]) dfs(i);
	}
	ile.assign(n+1, 0LL);
	int v = 0;
	while (ans[v]!=start) v++;
	ile[start] = 1;
	for (int i = v+1; i<n; i++){
		for (auto x: graf[ans[i]]){
			ile[ans[i]]+=ile[x];
		}
		ile[ans[i]] = (ile[ans[i]]+MOD)%MOD;
		//debug(ile[ans[i]]);
	}
	cout << ile[meta];
	return 0;
}
