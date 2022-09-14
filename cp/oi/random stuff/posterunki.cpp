#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
const LL MOD = 1e9+7;

const int MAX = 1e5+7;
vector <int> val, graf[MAX], gt[MAX], postorder, nr, spojne[MAX];
vector <bool> vis;
int numer = 0, mini, ile;
vector <pii> ans;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]) dfs(x);
	}
	postorder.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	nr[v] = numer;
	if (val[v] == mini) ile++;
	if (val[v] < mini){
		mini = val[v];
		ile = 1;
	}
	for (auto x: gt[v]){
		if (!vis[x]) dfs2(x);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, a, b;
	cin >> n;
	val.assign(n+1, 0);
	for (int i = 0; i<n; i++)cin >> val[i+1];
	cin >> m;
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		gt[b].pb(a);
	}
	vis.assign(n+1, 0);
	nr.resize(n+1);
	for (int i = 1; i<=n; i++){
		if (!vis[i]) dfs(i);
	}
	vis.assign(n+1, 0);
	for (int i = n-1; i>=0; i--){
		if (!vis[postorder[i]]) {
			numer++;
			mini = INT_MAX;
			ile = 0;
			dfs2(postorder[i]);
			ans.pb({mini, ile});
		}
	}
	LL res = 0LL, ways = 1LL;
	for (auto x: ans){
		res += (LL)x.st;
		ways = (ways*x.nd+MOD)%MOD;
	}
	cout << res << " " << ways << "\n";
	return 0;
}
