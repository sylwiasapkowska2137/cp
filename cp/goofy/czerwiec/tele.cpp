#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 5e5+7;
vector<int>graf[MAX], a;
vector<bool>vis;
int cnt[2];

void dfs(int v){
	vis[v] = 1;
	//debug((v&1));
	//debug((a[v]&1));
	if ((v&1)!=(a[v]&1)) cnt[(v&1)]++;
	//cerr << "\n";
	for (auto x: graf[v]){
		if (!vis[x]) dfs(x);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int n, m, b, c;
	cin >> n >> m;
	a.resize(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i<m; i++) {
		cin >> c >> b;
		graf[c].pb(b);
		graf[b].pb(c);
	}
	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (!vis[i]) {
			dfs(i);
			if (cnt[0]!=cnt[1]){
				cout << "NIE\n";
				return 0;
			} 
			cnt[0] = cnt[1] = 0;
			//cerr << "\n";
		}
	}
	cout << "TAK\n";
	return 0;
}

