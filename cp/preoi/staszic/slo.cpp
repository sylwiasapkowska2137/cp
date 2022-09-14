#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define pil pair<int, LL>

const int MAX = 5e5+7, H = 20;
vector <pil> graf[MAX];
vector <int> depth;
vector <LL> suma;
int p[MAX][H];
LL sum = 0;

void dfs(int v, int pa = 0, int _depth = 0){
	depth[v] = _depth;
	p[v][0] = pa;
	for (int i = 1; i<=H; i++) p[v][i] = p[p[v][i-1]][i-1];
	for (auto x: graf[v]){
		if (x.st != pa){
			sum+=x.nd;
			suma[x.st] = sum;
			dfs(x.st, v, _depth+1); 
			sum-=x.nd;
		}	
	}
}

int lca(int a, int b){
	if (depth[a]>depth[b]) swap(a, b);
	for (int i = H; i>=0; i--) if(depth[p[b][i]]>=depth[a]) b = p[b][i];
	if (a == b) return a;
	for (int i = H; i>=0; i--){
		if (p[a][i]!=p[b][i]){
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b;
	LL c, res;
	cin >> n;
	suma.assign(n+1, 0LL);
	depth.assign(n+1, 0);
	for (int i = 1; i<n; i++){
		cin >> a >> b >> c;
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	dfs(1);
	while (cin >> a && a != -1){
		cin >> b;
		res = suma[a]+suma[b]-2*suma[lca(a, b)];
		cout << res << "\n";
	}
	return 0;
}
