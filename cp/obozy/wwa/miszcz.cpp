#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 5e5+7, K = 20;
vector<int>graf[MAX];
int preorder[MAX], postorder[MAX], up[MAX][K], depth[MAX];
int czas;

bool cmp(int a, int b){
	return preorder[a] < preorder[b];
}

void dfs(int v, int pa = 0){
	preorder[v] = czas++;
	up[v][0] = pa;
	for (int i = 1; i<K; i++) up[v][i] = up[up[v][i-1]][i-1];
	for (auto x: graf[v]){
		if (x!=pa){
			depth[x] = depth[v]+1;
			dfs(x, v);
		}
	}
	postorder[v] = czas++;
}

int LCA(int a, int b){
	if (depth[a]<depth[b]) swap(a, b); //a jest głębiej
	for (int i = K-1; i>=0; i--){
		if (depth[a]-(1<<i)>=depth[b]) a = up[a][i];
	}
	if (a == b) return a;
	for (int i = K-1; i>=0; i--){
		if (up[a][i]!=up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}



int dist(int a, int b){
	int lca = LCA(a, b);
	return depth[a]+depth[b]-2*depth[lca];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q, a, b, t, ans;
	cin >> n >> q;
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfs(1);
	while (q--){
		cin >> t;
		ans = 0;
		vector<int>tab(t);
		for (int i = 0; i<t; i++) cin >> tab[i];
		sort(tab.begin(), tab.end(), cmp);
		for (int i = 1; i<t; i++){
			ans += dist(tab[i], tab[i-1]);
		}
		ans+=dist(tab[0], tab[t-1]);
		cout << ans/2 << "\n";
	}
	return 0;
}
