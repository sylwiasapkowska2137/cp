#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 1e6+7;
vector<int> graf[MAX], gt[MAX], typ, numer, spojne[MAX], toposort, postorder, in;
vector <bool> special;
//typ: 0 - nieosiagalny z uniwerka, 1 - nalezacy do cyklu, 2 - kazdy inny
vector<bool> vis;
int nr, ile;

void dfs1(int v){
	vis[v] = 1;
	for (auto x: gt[v]) if(!vis[x]) dfs1(x);
}

void dfs2(int v){
	vis[v] = 1;
	for (auto x: graf[v]) if(!vis[x]) dfs2(x);
	postorder.pb(v);
}

void dfs3(int v){
	vis[v] = 1;
	numer[v] = nr;
	ile++;
	for (auto x: gt[v]) if (!vis[x]) dfs3(x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, a, b;
	cin >> n >> m;
	n++;
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		gt[b].pb(a);
	}
	
	vis.assign(n+1, 0);
	typ.assign(n+1, 7);
	numer.resize(n+1);
	in.resize(n+1);
	special.assign(n+1, 0);
	
	dfs1(n);
	for (int i = 1; i<=n; i++){
		if (!vis[i]) typ[i] = 0;
	}
	
	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (!vis[i]) dfs2(i);
	}
	
	vis.assign(n+1, 0);
	for (int i = n-1; i>=0; i--){
		if (!vis[postorder[i]]) {
			nr++;
			ile = 0;
			dfs3(postorder[i]);
			if (ile > 1) special[nr] = 1;
		}
	}
	for (int i = 1; i<=n; i++) debug(typ[i]);
	cerr << "\n";
	for (int i = 1; i<=n; i++) debug(numer[i]);
	cerr << "\n";
	queue<int> k;
	for (int i = 1; i<=n; i++){
		for (auto x: graf[i]){
			if (numer[i]!=numer[x]){
				spojne[numer[i]].pb(numer[x]);
				in[numer[x]]++;
			}
		}
	}
	for (int i = 1; i<=nr; i++){
		if (in[i]==0)k.push(i);
	}
	while (!k.empty()){
		int v = k.front();
		k.pop();
		toposort.pb(v);
		for (auto x: spojne[v]){
			in[x]--;
			if (in[x] == 0) k.push(x);
		}
	}
	for (auto x: toposort)debug(x);
	cerr << "\n";
	reverse(toposort.begin(), toposort.end());
	
	return 0;
}
