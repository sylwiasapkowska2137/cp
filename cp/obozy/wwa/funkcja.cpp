//
#include <bits/stdc++.h>
using namespace std;

#define LL unsigned long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
const LL MOD = 11;

LL power(LL a, LL b) {
	LL res = 1LL;
	while (b>0){
		if (b&1)res = (res*a)%MOD;
		a = (a*a)%MOD;
		b /=2;
	}
	return (res%MOD);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	LL A0, n;
	cin >> A0 >> n;
	A0 = (A0 % MOD);
	LL res = A0 * power(2, n);
	res = ((res%MOD)+MOD)%MOD;
	cout << res;
	return 0;
}

