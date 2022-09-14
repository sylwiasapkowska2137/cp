
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
vector <bool> vis, is;
int maxdepth, w;

void dfs(int v, int _depth = 0){
	vis[v] = 1;
	if (_depth > maxdepth && is[v]){
		maxdepth = _depth;
		w = v;
	}
	for (auto x: graf[v]) 
		if (!vis[x]) dfs(x, _depth+1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k, a, b;
	cin >> n >> k;
	vis.assign(n+1, false);
	is.assign(n+1, false);
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	for (int i = 0; i<k; i++){
		cin >> a;
		is[a] = 1;
	}
	dfs(1);
	maxdepth = 0;
	vis.assign(n+1, false);
	dfs(w);
	cout << maxdepth;
	return 0;
}







