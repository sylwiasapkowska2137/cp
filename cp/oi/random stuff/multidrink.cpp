#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 5e5+7;
vector<int>graf[MAX], deg;
vector<bool>leaf;

void dfs(int v, int pa = -1){
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b;
	cin >> n;
	deg.assign(n+1, 0);
	leaf.assign(n+1, 0);
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	for (int i = 1;i<=n; i++){
		for (auto x: graf[i]){
			if (graf[x].size() > 1) deg[i]++;
		}	
	}
	for (int i = 1; i<=n; i++)graf[i].pb(i);
	
	for (int i = 1; i<=n; i++){
		if (deg[i]>5){
			cout << "BRAK\n";
			return 0;
		}
	}
	for (int i = 1; i<=n; i++)	if (graf[i].size() == 2) leaf[i] = 1;
	leaf[1] = leaf[n] = 0;
	
	
	
	return 0;
}
