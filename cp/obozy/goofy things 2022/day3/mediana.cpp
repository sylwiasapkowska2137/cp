#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int>pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<bool> vb;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)
#define pb push_back

const int MAX = 1007;
int tab[MAX][MAX];
int n;

bool check(int mid){
	int dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if (tab[i][j]>=mid) dp[i][j]++;
		}
	}
	if (dp[n][n] >= n) return 1;
	return 0;
}

void solve(){
	cin >> n;
	rep(i, 1, n+1){
		rep(j, 1, n+1){
			cin >> tab[i][j];
		}
	}
	int L = 1, R = 1e9, ans = 1e9+7;
	while (R>=L){
		int mid = (L+R)/2;
		if (check(mid)) {
			ans = mid;
			L = mid+1;
		} else R = mid-1;
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
