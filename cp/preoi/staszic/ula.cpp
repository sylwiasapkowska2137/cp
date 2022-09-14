#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsugned LL
#define LD long double
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define fastio ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0)

const int MAX = 2e5+7;
vector <int> graf[MAX], gt[MAX], spojne[MAX], num, preorder, nr, suma, wynik, wejscia, dp;
vector <bool> vis;
int numer = 0;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]) if (!vis[x]) dfs(x);
	preorder.pb(v);
}

void dfs2(int v){
	vis[v] = 1;
	nr[v] = numer;
	suma[numer]+=num[v];
	for (auto x: gt[v]) if (!vis[x]) dfs2(x);
}

int main(){
	fastio;
	int n, m, a, b, ans = 0, curr;
	cin >> n >> m;
	num.assign(n+1, 0);
	for (int i = 0; i<n; i++) cin >> num[i+1];
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		graf[a].pb(b);
		gt[b].pb(a);
	}
	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++)if (!vis[i]) dfs(i);
	vis.assign(n+1, 0);
	nr.assign(n+1, -1);
	suma.assign(n+1, 0);
	wejscia.assign(n+1, 0);
	for (int i = (int)preorder.size()-1; i>=0; i--){
		if (!vis[preorder[i]]) {
			numer++;
			dfs2(preorder[i]);
		}
	}
	for (int i = 1; i<=n; i++){
		for (auto v: graf[i]){
			if (nr[i] != nr[v]){
				spojne[nr[i]].pb(nr[v]);
				wejscia[nr[v]]++;
			}
		}
	}
	queue <int> k;
	for (int i = 1; i<=numer; i++){
		if (!wejscia[i]) k.push(i);
	}
	while (!k.empty()){
		int v = k.front();
		k.pop();
		wynik.pb(v);
		for (auto x: spojne[v]){
			wejscia[x]--;
			if (wejscia[x] == 0) k.push(x);
		}
	}
	dp.assign(n+1, 0);
	for (int i = (int)wynik.size()-1; i>=0; i--){
		for (auto x: spojne[wynik[i]]) {
			dp[wynik[i]]=max(dp[wynik[i]],dp[x]);
		}
		dp[wynik[i]]+=suma[wynik[i]];
		ans = max(ans, dp[wynik[i]]);
	}
	cout << ans;
	return 0;
}
