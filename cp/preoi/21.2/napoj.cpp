#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back
#define pii pair <int, int>
#define st first
#define nd second
const int MAX = 1e6+7;

vector <int> graf[MAX], wazny[MAX];
vector <bool> vis, kolor;
bool is;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]) if (!vis[x]) dfs(x);
}

void dfs2(int v){
	vis[v] = 1;
	kolor[v] = 1;
	for (auto x: wazny[v]){
		if (!vis[x]) dfs2(x);
		else if (kolor[x]) is = 1;
	}
	kolor[v] = 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,q,a,b;
	cin >> n >> m >> q;
	vector <pii> edges;
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
	}
	set<int>s;
	for (int i = 0; i<q; i++){
		cin >> a >> b;
		s.insert(b);
		s.insert(a);
		//wazny[a].pb(b);
		edges.pb({a, b});
	}
	for (auto i = s.begin(); i!=s.end(); i++){
		//debug(*i);
		vis.assign(n+1, 0);
		dfs(*i);
		for (int j = 1; j<=n; j++){
			if (vis[j] && j!=*i && s.find(j)!=s.end()){
				wazny[*i].pb(j);
			}
		}
	}
	/*for (auto i = s.begin(); i!=s.end(); i++){
		debug(*i);
		for (auto x: wazny[*i])debug(x);
		cerr << "\n";
	}*/
	int res = 0;
	for (int i = 0; i<(1<<q); i++){
		for (int j = 0; j<q; j++){
			if ((i&(1<<j))!=0){
				wazny[edges[j].st].pb(edges[j].nd);
			}
		}
		is = 0;
		vis.assign(n+1, 0);
		kolor.assign(n+1, 0);
		for (auto k = s.begin(); k!=s.end() && !is; k++){
			if (!vis[*k]) dfs2(*k);
		}
		if (!is) res = max(res, __builtin_popcount(i));
		for (int j = 0; j<q; j++){
			if ((i&(1<<j))!=0){
				wazny[edges[j].st].pop_back();
			}
		}
	}
	cout << res;
	return 0;
}
