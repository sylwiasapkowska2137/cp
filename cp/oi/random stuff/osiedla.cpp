#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back

stack <int>s, pom;
const int MAX = 1e6+7;
vector <pii> graf[MAX], edges;
vector <int> ans, rep;
vector <bool> vis;
int bridges;

void cnt(int v){
	while (rep[s.top()]!=rep[v]){
		pom.push(s.top());
		s.pop();
		if (rep[pom.top()]==pom.top()) bridges--;
		rep[pom.top()] = rep[v];
	}
	while (!pom.empty()){
		s.push(pom.top());
		pom.pop();
	}
}

void dfs(int v){
	s.push(v);
	for (auto x: graf[v]){
		if (ans[x.nd] == -1){
			if (edges[x.nd].st == v) ans[x.nd] = 1;
			else ans[x.nd] = 0;
			if (!vis[x.st]) {
				vis[x.st] = 1;
				dfs(x.st);
			} else cnt(x.st);
		}
	}
	s.pop();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	bridges = n;
	rep.resize(n+1);
	edges.resize(m+1);
	for (int i = 1; i<=n; i++)rep[i] = i;
	for (int i = 0; i<m; i++){
		cin >> edges[i].st >> edges[i].nd;
		graf[edges[i].st].pb({edges[i].nd, i});
		graf[edges[i].nd].pb({edges[i].st, i});
	}
	vis.assign(n+1, 0);
	ans.assign(m+1, -1);
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			vis[i] = 1;
			dfs(i);
		}
	}
	cout << bridges << "\n";
	for (int i = 0; i<m; i++){
		if (ans[i]) cout << ">";
		else cout << "<";
	}
	cout << "\n";
	return 0;
}
