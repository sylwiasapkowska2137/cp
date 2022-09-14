#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

const int MAX = 2e5+7;
vector<bool>vis;
vector<int>graf[MAX], wsteczne, depth;
vector<tuple<int, int, int>>ans;
set<pii>s;
int cnt;


void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (vis[x]){
			wsteczne.pb(x);
			s.insert({min(x, v), max(x, v)});
		} 
	}
	while (wsteczne.size() > (wsteczne.size()&1)){
		ans.pb({wsteczne[wsteczne.size()-1], v, wsteczne[wsteczne.size()-2]});
		wsteczne.pop_back();
		wsteczne.pop_back();
	}
	if (wsteczne.size() == 1){
		cnt++;
		graf[v].pb(cnt);
		graf[cnt].pb(v);
	}
	for (auto x: graf[v]){
		if (!vis[x]){
			depth[x] = depth[v]+1;
			dfs(x);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, a, b;
	cin >> n >> m;
	depth.assign(2*n+1, 0);
	vis.assign(2*n+1, 0);
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	cnt = n;
	for (int i = 1; i<=n; i++) if(!vis[i])dfs(i);
	
	
	return 0;
}
