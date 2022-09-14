#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

const int MAX = 5e4+7;
vector <int> graf[MAX], gt[MAX], preorder, spojne[MAX], nr, wejscia, toposort, ans, rozmiar;
vector <bool> vis;
int numer = 0;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]) if (!vis[x]) dfs(x);
	preorder.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	nr[v] = numer;
	rozmiar[numer]++;
	for (auto x: gt[v]) if (!vis[x]) dfs2(x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		gt[b].pb(a);
	}
	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (!vis[i]) dfs(i);
	}
	vis.assign(n+1, 0);
	nr.assign(n+1, 0);
	rozmiar.assign(n+1, 0);
	wejscia.assign(n+1, 0);
	for (int i = (int)preorder.size()-1; i>=0; i--){
		if (!vis[preorder[i]]) {
			numer++;
			dfs2(preorder[i]);
		}
	}
	//for (auto x: nr)debug(x);
	//cerr << "\n";
	for (int i = 1; i<=n; i++){
		for (auto x: graf[i]){
			if (nr[i]!=nr[x]){
				spojne[nr[i]].pb(nr[x]);
				wejscia[nr[x]]++;
			}
		}
	}
	queue <int> k;
	for (int i = 1; i<=numer; i++) {
		if (!wejscia[i]) k.push(i);
	}
	while (!k.empty()){
		int v = k.front();
		k.pop();
		toposort.pb(v);
		for (auto x: spojne[v]){
			wejscia[x]--;
			if (!wejscia[x]) k.push(x);
		}
	}
	//for (auto x: toposort) debug(x);
	ans.assign(n+1, 0);
	//cerr << "\n";
	//for (auto x: rozmiar) debug(x);
	//cerr << "\n";
	for (int i = (int)toposort.size()-1; i>=0; i--){
		ans[toposort[i]] = rozmiar[toposort[i]];
		
		for (auto x: spojne[toposort[i]]){
			ans[toposort[i]] += ans[x];
		}
	}
	for (int i = 1; i<=n; i++){
		cout << ans[nr[i]]-1 << "\n";
	}
	return 0;
}
