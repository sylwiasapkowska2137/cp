#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)

const LL MOD = 1e9+7;

LL LCM(LL a, LL b){
	return a*b/(LL)__gcd(a, b);
}

void solve(){
	LL n, ans = 0, lcm = 1;
	cin >> n;
	ans+=n;
	rep(i, 1, n+1){
		lcm = LCM(lcm, i);
		if (lcm > n) break;
		ans += (n/lcm);
		if (ans>=MOD)ans%=MOD;
	}
	cout << ans << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}



