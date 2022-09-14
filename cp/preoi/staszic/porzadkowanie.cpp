#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MAX = 1e5+7;
vector <int> graf[MAX], ans;
vector <bool> vis;
vector <pii> ile;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]) if (!vis[x]) dfs(x);
	ans.pb(v);
}
bool cmp(pii a, pii b){
	if (a.nd == b.nd) return (a.st > b.st);
	return (a.nd < b.nd);
}

int main(){
	fastio;
	int n, m, a, b;
	cin >> n >> m;
	ile.resize(n+1);
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		ile[a].st++;
		ile[b].nd++;
	}
	sort(ile.begin(), ile.end(), cmp);
	for (int i = 1; i<=n; i++){
		debug(ile[i].st);
		debug(ile[i].nd);
		cerr << "\n";
	}
	return 0;
}




