#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 2137;
vector<pii> graf[MAX];
bool osiagalny[MAX][MAX], dasie[MAX][MAX];
vector <bool> vis;
void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]) if (!vis[x.st]) dfs(x.st);
}

bool warunek(int m){
	return 1;
}

int binsracz(int start, int koniec){
	while (start <= koniec){
		int m = (start+koniec)/2;
		if (warunek(m)) start = m;
		else koniec = m-1;
	}
	return start;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b;
	cin >> n;
	int m = 2*n;
	vector <pii> czy(m);
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		czy[i].st = a;
		czy[i].nd = b;
		graf[a].pb({b, i});
	}
	for (int i = 1; i<=n; i++){
		vis.assign(n+1, 0);
		dfs(i);
		for (int j = 1; j<=n; j++){
			if (vis[j]) osiagalny[i][j] = 1; //z i do j
		}
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			debug(osiagalny[i][j]);
		}
		cerr << "\n";
	}
	for (int i = 0; i<m; i++){
		for (int j = i+1; j<m; j++){
			
		}
	}
	//binsracz(0, n);
	return 0;
}
