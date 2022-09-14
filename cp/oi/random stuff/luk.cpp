#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define pii pair<int, int>

const int MAX = 3e5+7;
vector<int>graf[MAX], dp;
int n;

void dfs(int v, int k, int pa = -1){
	for (auto x: graf[v]){
		if (x!=pa){
			dfs(x, k, v);
			dp[v] += (dp[x]+1);
		}
	}
	dp[v] = max(0, dp[v]-k);
}

bool warunek(int k){
	dp.assign(n+1, 0);
	dfs(1, k);
	if (dp[1]==0) return 1;
	return 0;
}

void binsracz(int start, int koniec){
	int ans = 0;
	while (start <= koniec){
		int m = (start + koniec)/2;
		if (warunek(m)) {
			koniec = m-1;
			ans = m;
		}
		else start = m+1;
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a, b;
	cin >> n;
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	binsracz(1, n);
	return 0;
}
