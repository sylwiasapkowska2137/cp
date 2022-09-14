#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 1e6+7;
vector <int> graf[MAX];
int c, d;

void dfs(int v, int pa = -1, int depth = 0){
	if (depth > d){
		d = depth;
		c = v;
	}
	for (auto x: graf[v]) {
		if (x != pa && x != 0) dfs(x, v, depth+1);
	}
}

void solve(){
	int n, ile, a, root, mini = 1e9+7, maxi = 0, suma = 0;
	cin >> n;
	vector <pii> tab(n);
	for (int i = 0; i<n; i++){
		cin >> ile;
		for (int j = 1; j<=ile; j++){
			cin >> a;
			if (a == 0)	root = j;
			graf[a].pb(j);
			graf[j].pb(a);
		}
		if (ile == 1) {
			tab[i] = {0, 0};
			continue;
		}
		c = 0, d = 0;
		dfs(root);
		tab[i].nd = d;
		d = 0;
		dfs(c);
		tab[i].st = d;
		for (int i = 0; i<=ile; i++) graf[i].clear();
	}
	for (auto x: tab) suma += x.nd;
	for (auto x: tab){
		if (x.st == 0 && x.nd == 0) continue;
		auto curr = 2*(suma-x.nd)+x.st;
		mini = min(mini, curr);
		maxi = max(maxi, curr);
	}
	if (mini == 1e9+7) mini = 0;
	cout << maxi << " " << mini << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)	solve();
	return 0;
}
