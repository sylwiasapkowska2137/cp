#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pb push_back
#define debug(x) cerr << x << " "

const int MAX = 1e4+7;
vector <int> graf[MAX], gt[MAX], postorder, nr, spojne[MAX];
vector <bool> vis, in, out;
int numer = 0;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]) if (!vis[x]) dfs(x);
	postorder.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	nr[v] = numer;
	for (auto x: gt[v]) if (!vis[x]) dfs2(x);
}

void dfs3(int v){
	in[v] = 1;
	vis[v] = 1;
	for (auto x: spojne[v]){
		if (!vis[x]){
			out[v] = 1;
			dfs3(x);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		gt[b].pb(a);
	}
	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		if (!vis[i]) dfs(i);
	}
	vis.assign(n+1, 0);
	nr.assign(n+1, 0);
	for (int i = (int)postorder.size()-1; i>=0;i--){
		if (!vis[postorder[i]]) {
			numer++;
			dfs2(postorder[i]);
		}
	}
	
	if (numer == 1) {
		cout << 0;
		return 0;
	}
	in.assign(n+1, 0);
	out.assign(n+1, 0);
	for (int i = 1; i<=n; i++){
		for (auto x: graf[i]){
			if (nr[i]!=nr[x] && i!=x){
				spojne[nr[i]].pb(nr[x]);
				in[nr[x]] = 1;
				out[nr[i]] = 1;
			}
		}
	}
	vis.assign(n+1, 0);
	int inn = 0, outt = 0;
	for (int i = 1; i<=numer; i++){
		if (!in[i]) inn++;
		if (!out[i]) outt++;
	}
	cout << max(inn, outt);
	return 0;
}
