#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 1e5+7;
int graf[MAX];
vector <bool> vis;
vector<int> kolor;
int cycle = 0, numer = 0;
LL ans = 1e18+7;

void cnt(int v){
	int val = graf[v];
	LL curr = (LL)v;
	while (val != v){
		curr+=val;
		val = graf[val];
	}
	ans = min(ans, curr);
}

void dfs(int v){
	vis[v] = 1;
	kolor[v] = numer;
	if (!vis[graf[v]]) dfs(graf[v]);
	else {
		if (kolor[graf[v]] == numer) {
			cycle = graf[v];
			cnt(cycle);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n;
	for (int i = 1; i<=n; i++){
		cin >> x;
		graf[i] = x;
	}
	vis.assign(n+1, 0);
	kolor.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (!vis[i]) {
			numer++;
			cycle = 0;
			dfs(i);
		}
	}
	cout << ans << "\n";
	return 0;
}
