#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

const int MAX = 2e5+7;
vector<int>graf[MAX], ans;
vector<bool>vis;

void dfs(int v){
	vis[v] = 1;
	ans.pb(v);
	for (auto x: graf[v]){
		if (!vis[x]){
			dfs(x);
			ans.pb(v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b;
	cin >> n;
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	for (int i = 1; i<=n; i++){
		sort(graf[i].begin(), graf[i].end());
	}
	vis.assign(n+1, 0);
	dfs(1);
	for (auto x: ans) cout << x << " ";
	return 0;
}




