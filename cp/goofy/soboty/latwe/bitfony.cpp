
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

vector <int> tab;
vector <bool> vis;
vector <int> depth;

void dfs(int v, int _depth = 0){
	vis[v] = 1;
	depth[v] = _depth;
	if (!vis[tab[v]]) dfs(tab[v], _depth+1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b, c;
	cin >> n;
	tab.assign(n+1, 0);
	vis.assign(n+1, false);
	depth.assign(n+1, 0);
	for (int i = 1; i<=n; i++)cin >> tab[i];
	cin >> a >> b;
	dfs(a);
	if (vis[b])	cout << depth[b];
	else cout << "-1";
	return 0;
}






