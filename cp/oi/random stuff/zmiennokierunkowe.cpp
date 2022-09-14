#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair <int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 5e5+7;
vector <int> graf[MAX], postorder, numer, spojne[MAX], gt[MAX], trans[MAX], in, wejscia;
vector <bool>vis;
int nr = 0;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]) dfs(x);
	}
	postorder.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	numer[v] = nr;
	for (auto x: gt[v]){
		if (!vis[x]) dfs2(x);
	}
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
	//vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (!vis[i]) dfs(i);
	}
	vis.assign(n+1, 0);
	in.assign(n+1, 0);
	wejscia.assign(n+1, 0);
	numer.resize(n+1);
	for (int i = (int)postorder.size()-1; i>=0; i--){
		if (!vis[postorder[i]]){
			nr++;
			dfs2(postorder[i]);
		}
	}
	for (int i = 1; i<=n; i++)debug(numer[i]);
	cerr << "\n";
	for (int i = 1; i<=n; i++){
		for (auto x: graf[i]){
			if (numer[i]!=numer[x]){
				spojne[numer[i]].pb(numer[x]);
				in[numer[x]]++;
				trans[numer[x]].pb(numer[i]);
				wejscia[numer[i]]++;
			}
		}
	}
	for (int i = 1; i<=nr; i++){
		for (auto x: spojne[i])debug(x);
		cerr << "\n";
	}
	queue <int> k;
	for (int i = 1; i<=numer; i++) {
		if (!in[i]) k.push(i);
	}
	while (!k.empty()){
		
	}
	return 0;
}
/*
6 7
1 2
1 3
2 4
3 4
4 5
5 6
6 5
*/
//wypisac ile miast jest osiagalnych przez wszystkie
