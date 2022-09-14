#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair <int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 1e6+6;
vector <pii> graf[MAX], gt[MAX];;
vector <int> postorder, nr, spojne[MAX], toposort, in;
vector <bool> vis;
int sumy[843], pre[843];
vector <LL> ans;
int numer;

int binsracz(int val){
	int start = 0, koniec = 842, m;
	while (koniec - start > 0){
		m = (start+koniec)/2;
		if (sumy[m]>=val) koniec = m;
		else start = m+1;
	}
	return start;
}

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x.st]) dfs(x.st);
	}
	postorder.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	nr[v] = numer;
	for (auto x: gt[v]){
		if (!vis[x.st])	dfs2(x.st);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, a, b, c, s, ka = 0, end = 1e8+1;
	pre[0] = 0;
	sumy[0] = 0;
	while (pre[ka]<end){
		ka++;
		sumy[ka] = ka*(ka+1)/2;
		pre[ka] = pre[ka-1]+sumy[ka];
	}
	cin >> n >> m;
	for (int i = 0; i<m; i++){
		cin >> a >> b >> c;
		graf[a].pb({b, c});
		gt[b].pb({a, c});
	}
	cin >> s;
	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (!vis[i]) dfs(i);
	}
	vis.assign(n+1, 0);
	nr.resize(n+1);
	for (int i = (int)postorder.size()-1; i>=0; i--){
		if (!vis[postorder[i]]) {
			numer++;
			dfs2(postorder[i]);
		}
	}
	ans.assign(numer+1, 0LL);
	for (int i = 1; i<=n; i++){
		for (auto x: graf[i]){
			if (nr[x.st] == nr[i]){
				int indeks = binsracz(x.nd);
				ans[nr[x.st]]+=(indeks)*(x.nd)-pre[indeks-1];
			} else {
				spojne[nr[i]].pb(nr[x.st]);
				in[nr[x.st]]++;
			}
		}
	}
	in.resize(numer+1);
	queue <int> k;
	for (int i = 1; i<=numer; i++){
		if (!in[i]) k.push(i);
	}
	while (!k.empty()){
		int v = k.front();
		k.pop();
		toposort.pb(v);
		for (auto x: spojne[v]){
			in[x]--;
			if (!in[x])k.push(x);
		}
	}
	for (auto x: toposort)debug(x);
	return 0;
}
