#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	if (n == 1){
		cout << "1\n";
		return;
	}
	vector <pair <int, int> > dp(n+1); //wierzcholek, sasiad
	vector <bool> vis(n+1, false);
	queue<int> q;
	dp[1] = {1, -1};
	vis[1] = true;
	q.push(1);
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (int i = 0; i<2; i++){
			int reszta = (10*v+i)%n;
			if (!vis[reszta]){
				vis[reszta] = true;
				dp[reszta] = {i, v};
				q.push(reszta);
			}
		}
	}
	if (!vis[0]) {
		cout << "BRAK\n";
		return;
	}
	string ans = "";
	int pa = 0;
	while (pa != -1){
		ans += to_string(dp[pa].first);
		pa = dp[pa].second;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int z;
	cin >> z;
	while (z--) solve();
	return 0;
}
