#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

vector<bool>vis;
vector<int> graf;
int x = -1;

void dfs(int v){
	vis[v] = 1;
	if (!vis[graf[v]]) dfs(graf[v]);
	else {
		if (x == -1) x = v;
		return;
	} 
}

void solve(){
	int n, z;
	cin >> n;
	x = -1;
	vector<int> ans;
	graf.resize(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> z;
		graf[i] = i-z;
	}
	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (!vis[i]) dfs(i);
	}
	int v = graf[x];
	while (v != x){
		ans.pb(v);
		v = graf[v];
	}
	ans.pb(v);
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
