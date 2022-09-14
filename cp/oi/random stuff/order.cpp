#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define debug(x) cerr << x << " "
const int MAX = 5e5+7;
vector <int> graf[MAX], preorder, postorder;
int czas;

void dfs(int v, int pa = -1){
	preorder[v] = ++czas;
	for (auto x: graf[v]){
		if (x!=pa) dfs(x, v);
	}
	postorder[v] = ++czas;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, q, pa, root, a, b;
	cin >> n >> q;
	preorder.resize(n+1);
	postorder.resize(n+1);
	for (int i = 1; i<=n; i++){
		cin >> pa;
		if (pa == 0){
			root = i;
			continue;
		}
		graf[i].pb(pa);
		graf[pa].pb(i);
	}
	dfs(root);
	while (q--){
		cin >> a >> b;
		if (preorder[a]<preorder[b] && postorder[a]>postorder[b]) cout << "NIE\n";
		else cout << "TAK\n";
	}
	return 0;
}
