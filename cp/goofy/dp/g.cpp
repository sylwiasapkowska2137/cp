#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
#define dbg if(1)

const int MAX = 1e5+7;
vector<int>graf[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, a, b;
	cin >> n >> m;
	vector<int>in(n+1, 0), toposort, dp(n+1, 0);
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		in[b]++;
		graf[a].pb(b);
	}
	queue<int>q;
	for (int i = 1; i<=n; i++) if (!in[i]) q.push(i);
	while (!q.empty()){
		int v = q.front();q.pop();
		toposort.pb(v);
		for (auto x: graf[v]){
			in[x]--;
			if (!in[x]) q.push(x);
		}
	}
	//for (auto x: toposort) debug(x);
	reverse(toposort.begin(), toposort.end());
	//cerr << "\n";
	for (auto v: toposort){
		for (auto x: graf[v]){
			dp[v] = max(dp[v], dp[x]+1);
		}
	}
	int ans = 0;
	for (int i = 1; i<=n; i++) ans = max(ans, dp[i]);
	cout << ans << "\n";
	return 0;
}



