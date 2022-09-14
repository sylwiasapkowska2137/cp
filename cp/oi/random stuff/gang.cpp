#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "
#define LL long long
#define st first
#define nd second
#define pii pair <int, int>
#define pb push_back
const int S = 333;

const int MAX = 1e5+7, MAXM = 1e6+7;
vector <pii> graf[MAX];
int freq[S+1][MAXM];
struct A{
	int a, b, c;
	A (int a, int b, int c): a(a), b(b), c(c){}
};
vector <A> input;
int parent[MAX], depth[MAX], preorder[MAX], postorder[MAX], maxx[MAX], wazny[MAX], numer[MAX], cnt[MAXM];
int czas = 0;

void dfs(int v, int pa = -1, int _depth = 0){
	depth[v] = _depth;
	//parent[v] = pa;
	preorder[v] = czas++;
	maxx[v] = _depth;
	for (auto x: graf[v]){
		if (x.st != pa) {
			dfs(x.st, v, _depth+1);
			maxx[v] = max(maxx[v], maxx[x.st]);
		}
	}
	postorder[v] = czas++;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, z, a, b, c;
	cin >> n >> m >> z;
	for (int i = 1; i<n; i++){
		cin >> a >> b >> c;
		input.pb({a, b, c});
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	dfs(1); 
	/*
	for (int i = 1; i<=n; i++){
		maxx[i]-=depth[i];
		//debug(maxx[i]);
		if (depth[i]%S == 0 && maxx[i]>=S) wazny.pb(i);
	}
	cnt.resize(wazny.size()+1);
	for (int i = 0; i<(int)input.size(); i++){
		if (depth[input[i].a]>depth[input[i].b]) numer[input[i].a] = input[i].c;
		else numer[input[i].b] = input[i].c;
	}
	for (auto x: wazny)debug(x);
	for (int i = 0; i<(int)wazny.size(); i++){
		int v = wazny[i];
		while (parent[v] != 0){
			freq[i][numer[v]]++;
			if (freq[i][numer[v]]==1) cnt[i]++;
			v = parent[v];
		}
		for (int j = 1; j<=m; j++)debug(freq[i][j]);
		cerr << "\n";
	}*/
	
	return 0;
}
