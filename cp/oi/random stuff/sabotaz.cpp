#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 1e5+7;
vector<int>graf[MAX];
vector<bool>vis;
int match[MAX];

bool dfs(int v){
	if(vis[v])return 0;
	vis[v] = 1;
	for(auto x:graf[v]){
		if(!match[x] || dfs(match[x])){
			match[v] = x;
			match[x] = v;
			return 1;
		}
	}
	return 0;
}


struct x{
	bool jaki;
	int nr, i;
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, b;;
	char c;
	x elem;
	cin >> n;
	vector<x>all;
	for (int i = 1; i<=n; i++){
		cin >> c >> elem.nr;
		elem.i = i;
		if (c == 'L') elem.jaki = 1;
		else elem.jaki = 0;
		all.pb(elem);
	}
	for (int i = 0; i<n; i++){
		for (int j = i+1; j<n; j++){
			if (all[i].nr == all[j].nr){
				if (all[i].jaki == all[j].jaki) {
					graf[all[i].i].pb(all[j].i);
					graf[all[j].i].pb(all[i].i);
				}
			}
			if (all[i].jaki != all[j].jaki){
				if (abs(all[i].nr-all[j].nr)==1){
					graf[all[i].i].pb(all[j].i);
					graf[all[j].i].pb(all[i].i);
				}
			}
		}
	}
	
	while(1){
		vis.assign(n+1, 0);
		bool ok = 0;
		for(int i = 1;i <= n; i++){
			if(!match[i]) ok|=dfs(i);
		}
		if (!ok)break;
	}
	for (int i = 1; i<=n; i++){
		debug(match[i]);
	}
	return 0;
}


