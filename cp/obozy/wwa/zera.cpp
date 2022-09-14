#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 2007;
int dist[MAX][MAX];
LL depth[MAX][MAX];
vector<pii>graf[MAX];
int rep[MAX];
int suma;

bool cmp(pii a, pii b){return dist[a.st][a.nd] < dist[b.st][b.nd];}

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

void dfs1(int v, int i, int pa = -1){
	suma++;
	for (auto x: graf[v]){
		if (x.st!=pa){
			depth[i][x.st] = depth[i][v]+(LL)x.nd;
			dfs1(x.st, i, v);
		}
	}
}

void dfs2(int v, int i, int pa = -1){
	for (auto x: graf[v]){
		if (x.st!=pa){
			depth[i][x.st] = depth[i][v]+(LL)x.nd;
			dfs2(x.st, i, v);
		}
	}
}

void Union(int a, int b){
	int c = Find(a);
	int d = Find(b);
	if (c!=d){
		rep[d] = c;
		graf[a].pb({b, dist[a][b]});
		graf[b].pb({a, dist[b][a]});
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pii>tab;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin >> dist[i][j];
		}
		rep[i] = i;
	}
	for (int i = 1; i<=n; i++){
		for (int j = i+1; j<=n; j++){
			if (dist[i][j]!=dist[j][i]){
				cout << "NO\n";
				return 0;
			}
			if (dist[i][j]) tab.pb({i, j});
		}
	}
	sort(tab.begin(), tab.end(), cmp);
	for (auto x: tab) Union(x.st, x.nd);
	dfs1(1, 1);
	if (suma < n){
		cout << "NO\n";
		return 0;
	}
	for (int i = 2; i<=n; i++)	dfs2(i, i);
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			if ((LL)dist[i][j]!=depth[i][j]){
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	return 0;
}


