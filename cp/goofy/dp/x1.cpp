#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
#define dbg if(1)

const int MAX = 20;
vector<int>graf[MAX], gt[MAX], g[MAX], in, topo, post, numer;
vector<bool>vis; 
int n, nr;
LL ans;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]) dfs(x);
	}
	post.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	numer[v] = nr;
	for (auto x: gt[v]){
		if (!vis[x]) dfs2(x);
	}
}

bool scc(){
	vis.assign(n+1, 0);
	numer.resize(n+1);
	for (int i = 1; i<=n; i++){
		if (!vis[i]) dfs(i);
	}
	reverse(post.begin(), post.end());
	vis.assign(n+1, 0);
	for (auto x: post){
		if (!vis[x]) {
			nr++;
			dfs2(x);
		}
	}
	for (int i = 1; i<=n; i++){
		for (auto x: graf[i]){
			if (numer[i] == numer[x]) return 0;
		}
	}
	return 1;
}

void Find(auto discovered, auto path){
	for (int v = 1; v<=n; v++){
		if (!in[v] && !discovered[v]){
			for (auto x: graf[v]) in[x]--;
			path.pb(v);
			discovered[v] = 1;
			Find(discovered, path);
			for (auto x: graf[v]) in[x]++;
			path.pop_back();
			discovered[v] = 0;
		}
	}
	if (path.size() == n) ans++;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int m, a, b;
	cin >> n >> m;
	in.resize(n+1);
	for (int i = 0; i<m;i++){
		cin >> a >> b;
		graf[a].pb(b);
		in[b]++;
		gt[b].pb(a);
	}
	if (scc()){
		vector<bool>discovered(n+1, 0);
		list<int>path;
		Find(discovered, path);
		cout << ans << "\n";
	} else {
		cout << "0\n";
		return 0;
	}
	
	return 0;
}



