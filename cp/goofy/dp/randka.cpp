#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define pb push_back
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 5e5+7;
vector<pii>graf[MAX];
vector<int>dag[MAX];
vector<double>val;

void dfs(int v, int pa = -1){
	for (auto x: graf[v]){
		if (x.st != pa){
			val[x.st] = x.nd;
			dfs(x.st, v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, a, b, c;
	cin >> n >> m;
	if (m == n-1){
		val.resize(n+1, 0);
		for (int i = 0; i<m; i++){
			cin >> a >> b >> c;
			graf[a].pb({b, c});
			graf[b].pb({a, c});
		}
		dfs(1);
		for (auto x: graf[1])val[1] += (double)x.nd;
		val[1] /= (double)graf[1].size();
		for (int i = 1; i<=n; i++){
			for (auto x: graf[i]){
				if (val[i]<val[x.st]) dag[i].pb(x.st);
			}
		}
		for (int i = 1; i<=n; i++){
			for (auto x: dag[i]) debug(x);
			cerr << "\n";
		}
	}
	return 0;
}
