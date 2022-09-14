#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define pii pair<int,int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
const int MAX = 1e6+7;
vector<int>graf[MAX];
int dp[MAX][2];

void dfs(int v, int pa = -1){
	int suma = 0;
	for (auto x: graf[v]) if (x!=pa) dfs(x, v);
	for (auto x: graf[v]) if (x!=pa) suma+=dp[x][1];
	for (auto x: graf[v]){
		if (x!=pa){
			dp[v][0] += max(dp[x][0], dp[x][1]);
			dp[v][1] = max(dp[v][1], suma-dp[x][1]+dp[x][0]+1);
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
	cout << max(dp[1][0], dp[1][1]) << "\n";
	return 0;
}
