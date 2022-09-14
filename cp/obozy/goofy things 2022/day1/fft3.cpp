#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> vi;

#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for(int i = a; i>=b; i--)
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define sz(x) (int)((x).size())
#define pb push_back

const LL MOD = 998244353;
const int MAX = 2e5+50;
LL fact[MAX], inv_num[MAX], inv_fact[MAX];
int prime[MAX];

void sito(){
	for (LL i = 2; i<MAX; i++){
		if (!prime[i] && i*i<(LL)MAX){
			for (LL j = i*i; j<MAX; j+=i){
				prime[j] = i;
			}
		}
	}
}

LL C(int n, int k){
	if (n < 0 || k < 0 || n-k < 0) return 0;
	LL x = ((fact[n]*inv_fact[n-k])%MOD * inv_fact[k])%MOD;
	return x;
}

void solve(){
	fact[0] = 1LL;
	rep(i, 1, MAX) fact[i] = (fact[i-1]*(LL)i)%MOD;
	inv_num[0] = inv_num[1] = 1LL;
	rep(i, 2, MAX) inv_num[i] = inv_num[MOD%i] * (MOD-MOD/i) % MOD;
	inv_fact[0] = inv_fact[1] = 1LL;
	rep(i, 2, MAX) inv_fact[i] = (inv_fact[i-1]*inv_num[i])%MOD;
	LL n, m; cin >> n >> m;
	LL ans = 0LL;
	sito();
	rep(i, 1, m+1){
		int x = i;
		map<int, int>cnt;
		while (prime[x]){
			cnt[prime[x]]++;
			x/=prime[x];
		}
		if (x > 1) cnt[x]++;
		//debug(i);
		//for (auto x: d) debug(x);
		//cerr << "\n";
		LL curr = 1LL;
		for (auto x: cnt){
			curr *= C(n+x.nd-1, n-1);
			curr %= MOD;
		}
		ans += curr;
		if (ans > MOD) ans %= MOD;
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
