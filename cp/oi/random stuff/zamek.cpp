#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define pb push_back
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 102;
vector<short int>graf[MAX], val, parent, ans;
bool ok = 0;
int start, meta, cena;

void bfs(){
	queue<pii>q;
	q.push({start, val[start]});
	while (!q.empty()){
		int v = q.front().st;
		int war = q.front().nd;
		q.pop();
		for (auto x: graf[v]){
			if (war+val[x] <= cena) {
				q.push({x, war+val[x]});
				parent[x] = v;
				if (x == meta && war+val[v] == cena){
					return;
				}
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, a, b;
	cin >> n >> m >> start >> meta >> cena;
	val.resize(n+1);
	parent.resize(n+1);
	for (int i = 1; i<=n; i++) cin >> val[i];
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	//cerr << "\n";
	bfs();
	parent[start] = -1;
	for (int i = 1; i<=n; i++) debug(parent[i]);
	int v = meta;
	/*
	while (1){
		ans.pb(v);
		v = parent[v];
		debug(v);
		if (v == -1) break;
	}*/
	reverse(ans.begin(), ans.end());
	for (auto x: ans) cout << x << " ";
	return 0;
}
