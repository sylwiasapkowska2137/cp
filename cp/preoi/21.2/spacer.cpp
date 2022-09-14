#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct edge{
	int a, b, c;
	edge(int a, int b, int c): a(a), b(b), c(c) {}
};

bool cmp (edge a, edge b){
	return (a.c < b.c);
}

const int MAX = 5e5+7;
vector <pii> graf[MAX];
vector <int> rep, ile;
vector<edge> tab;
vector <LL> suma;
vector <bool>used;

int Find(int a){
	if (rep[a] == a) return a;
	rep[a] = Find(rep[a]);
	return rep[a];
}

void Union(int a, int b, int dist, int indeks){
	int c = Find(a);
	int d = Find(b);
	if (c!=d){
		used[indeks] = 1;
		if (ile[c]<ile[d]) swap(c, d);
		rep[d] = c;
		graf[a].pb({b, dist});
		graf[b].pb({a, dist});
		if (ile[c]==ile[d]) ile[c]++;
	}
}

void dfs(int v, int pa = -1){
	for (auto x: graf[v]){
		if (x.st != pa){
			suma[x.st] = suma[v]+(LL)x.nd;
			dfs(x.st, v);
		}
	}
}

int main(){
	fastio;
	
	int n, m, a, b, c;
	cin >> n >> m;
	rep.resize(n+1);
	ile.resize(n+1, 0);
	used.assign(m+1, 0);
	for (int i = 0; i<m; i++){
		cin >> a >> b >> c;
		tab.pb({a, b, c});
	}
	for (int i = 0; i<=n; i++) rep[i] = i;
	sort(tab.begin(), tab.end(), cmp);
	for (int i = 0; i<m; i++) Union(tab[i].a, tab[i].b, tab[i].c, i);
	suma.assign(n+1, 0LL);
	dfs(1);
	set<int> ans;
	LL maxi = -1, val;
	for (int i = 0; i<m; i++){
		if (!used[i]){
			val = suma[tab[i].a]+suma[tab[i].b]+tab[i].c;
			if (val&1){
				if (maxi == val) {
					ans.insert(tab[i].b);
					ans.insert(tab[i].a);
				} else if (val > maxi){
					ans.clear();
					maxi = val;
					ans.insert(tab[i].a);
					ans.insert(tab[i].b);
				}
			}
		}
	}
	if (ans.empty() || maxi == -1) {
		cout << "BRAK\n";
		return 0;
	}
	for (auto it = ans.begin(); it!=ans.end(); it++){
		cout << *it << " ";
	}
	cout << "\n" << maxi << "\n";	
	return 0;
}
