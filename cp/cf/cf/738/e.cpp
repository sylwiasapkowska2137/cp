#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

const int MAX = 1e5+7;
const LL MOD = 998244353;
int prime[MAX], mobius[MAX];

void sito(){
	rep(i, 2, MAX){
		if (!prime[i]){
			for (int j = i; j<MAX; j+=i) if (!prime[j]) prime[j] = i;
		}
	}
}

void Mobius(){
	mobius[1] = 1;
	rep(i, 2, MAX){
		if (prime[i/prime[i]] == prime[i]) mobius[i] = 0;
		else mobius[i] = -mobius[i/prime[i]];
	}
}

void solve(){
	sito();
	Mobius();
	
	LL ans = 0LL, m;
	int n;
	cin >> n >> m;
	vector<LL>L(n), R(n);
	rep(i, 0, n) cin >> L[i] >> R[i];
	
	for (LL x = 1; x<=m; x++){
		
		bool ok = 0;
		vector<LL>left(n), right(n);
		rep(i, 0, n){
			left[i] = ceil((long double)L[i]/(long double)x);
			right[i] = R[i]/x;
			if (right[i]<left[i]){
				ok = 1;
				break;
			}
		}
		if (ok) continue;
		LL sum = m/x;
		
		//dp[i][j] = na ile sposobów mozna otrzymac sumę j za pomocą pierwszych i elementów z przedzialu
		LL dp[sum+1], pref[sum+1];
		memset(dp, 0, sizeof(dp));
		memset(pref, 0, sizeof(pref));
		//debug("x");
		//debug(x);
		//debug(sum);
		//cerr << "\n";
		rep(i, 0, sum+1)pref[i] = 1;
		rep(i, 1, n+1){
			rep(j, 1, sum+1){
				LL LEFT = j-right[i-1];
				LL RIGHT = j-left[i-1];
				//pref[RIGHT]-pref[LEFT-1]
				if (RIGHT>=0) dp[j] = pref[RIGHT];
				else continue;
				if (LEFT > 0) dp[j]-=pref[LEFT-1];
			}
			//rep(j, 0, sum+1) debug(dp[j]);
			//cerr << "\n";
			pref[0] = 0LL;
			rep(j, 1, sum+1) {
				pref[j] = pref[j-1]+dp[j];
				if (pref[j]>=MOD) pref[j]%=MOD;
			}
			rep(j, 0, sum+1) dp[j] = 0LL;
		}
		//cerr << "\n";
		ans += (mobius[x]*pref[sum]);
		while (ans<0) ans+=MOD;
		if (ans>=MOD)ans%=MOD;
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	while (t--) solve();
	
	return 0;
}
