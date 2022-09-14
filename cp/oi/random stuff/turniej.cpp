#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

int n, nr = 0, q;
const int MAX = 5e5+7;
int jeden[MAX], dwa[MAX], trzy[MAX], numer[MAX];
vector<int> postorder;
vector<bool>vis;

void dfs1(int v, int pa = -1){
	vis[v] = 1;
	for (int i = 1; i<=n; i++){
		if (i == v || i == pa || vis[i]) continue;
		int val = 0;
		if (jeden[i]>jeden[v]) val++;
		if (dwa[i]>dwa[v]) val++;
		if (trzy[i]>trzy[v]) val++;
		if (val>=2)	dfs1(i, v);
	}
	postorder.pb(v);
}

void dfs2(int v, int pa = -1){
	vis[v] = 1;
	numer[v] = nr;
	for (int i = 1; i<=n; i++){
		if (i == v || i == pa || vis[i]) continue;
		int val = 0;
		if (jeden[i]>jeden[v]) val++;
		if (dwa[i]>dwa[v]) val++;
		if (trzy[i]>trzy[v]) val++;
		if (val<2)dfs2(i, v);
	}
}


void scc(){
	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (!vis[i]) dfs1(i);
	}
	vis.assign(n+1, 0);
	reverse(postorder.begin(), postorder.end());
	for (auto x: postorder){
		if (!vis[x]){
			nr++;
			dfs2(x);
		}
	}
	for (int i = 1; i<=n; i++) debug(numer[i]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i<=n; i++) cin >> jeden[i];
	for (int i = 1; i<=n; i++) cin >> dwa[i];
	for (int i = 1; i<=n; i++) cin >> trzy[i];
	scc();
	cin >> q;
	while (q--){
		int a, b;
		cin >> a >> b;
		int val = 0;
		if (jeden[b]>jeden[a]) val++;
		if (dwa[b]>dwa[a]) val++;
		if (trzy[b]>trzy[a]) val++;
		if (val>=2 || numer[a]==numer[b]) cout << "TAK\n";
		else cout << "NIE\n";
	}
	return 0;
}
