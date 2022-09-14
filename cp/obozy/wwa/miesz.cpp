#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 1e6+7;
vector<int>graf[MAX], gt[MAX], post, nr, wejscia;
vector<bool>vis;
int numer, suma;

void dfs(int v){
	vis[v] = 1;
	suma++;
	for (auto x: graf[v]){
		if (!vis[x]) dfs(x);
	}
	post.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	nr[v] = numer;
	for (auto x: gt[v]){
		if (!vis[x]) dfs2(x);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
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
	wejscia.assign(n+1, 0);
	reverse(post.begin(), post.end());
	for (auto x: post){
		if (!vis[x]){
			numer++;
			dfs2(x);
		}
	}
	//for (auto x: nr)debug(x);
	//cerr << "\n";
	for (int i = 1; i<=n; i++){
		for (auto x: graf[i]){
			if (nr[i]!=nr[x]){
				//debug(i);
				//debug(x);
				//debug(nr[i]);
				//debug(nr[x]);
				//cerr << "\n";
				wejscia[nr[x]]++;
			}
		}
	}
	
	int cnt = 0, src;
	for (int i = 1; i<=numer; i++) {
		//debug(wejscia[i]);
		if (!wejscia[i]) {
			src = i;
			cnt++;
		}
	}
	if (cnt == 0) cout << "TAK\n";
	else if (cnt == 1){
		vis.assign(n+1, 0);
		suma = 0;
		int start = 1;
		while (nr[start]!=src) start++;
		dfs(start);
		//debug(suma);
		if (suma == n) cout << "TAK\n";
		else cout << "NIE\n";
	}
	else cout << "NIE\n";
	return 0;
}
