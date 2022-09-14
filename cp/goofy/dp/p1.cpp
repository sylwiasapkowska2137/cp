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

const int MAX = 1e5+7;
const LL MOD = 1e9+7;
vector<int>graf[MAX];
LL dp[MAX][2];

void dfs(int v, int pa = -1){
	dp[v][0] = dp[v][1] = 1;
	for (auto x: graf[v]){
		if (x!=pa){
			dfs(x, v);
			dp[v][0] = (dp[v][0]*(dp[x][1]+dp[x][0]))%MOD;
			dp[v][1] = (dp[v][1]*dp[x][0])%MOD;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b;
	cin >> n;
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfs(1);
	/*
	for (int i = 1; i<=n; i++){
		debug(dp[i][0]);
		debug(dp[i][1]);
		cerr << "\n";
	}*/
	cout << (dp[1][0]+dp[1][1])%MOD << "\n";
	return 0;
}
