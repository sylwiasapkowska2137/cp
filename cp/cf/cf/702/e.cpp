#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

const LL INF = 1e18+7;

void solve(){
	int n;
	cin >> n;
	vector<pair<LL, LL>>a(n+2);
	a[n+1] = {INF, INF};
	vector<LL>pref(n+1);
	rep(i, 1, n+1) {
		cin >> a[i].st;
		a[i].nd = i;
	}
	rep(i, 1, n+1) pref[i] = pref[i-1]+(LL)a[i].st;
	sort(a.begin()+1, a.end());
	vector<int>dp(n+1);
	int koniec = 1;
	rep(start, 1, n+1){
		if (koniec < start) koniec = start;
		while (koniec < n && pref[koniec] >= (LL)a[koniec+1].st){
			koniec++;
		}
		dp[start] = koniec;
	}
	//rep(i, 1, n+1) debug(dp[i]);
	//cerr << "\n";
	vector<int>ans;
	rep(i, 1, n+1){
		if (dp[i] == n) ans.pb(a[i].nd);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x << " ";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
