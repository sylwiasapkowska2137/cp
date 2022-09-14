#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)

const int MAX = 2e5+7;
const LL MOD = 1e9+7;
LL dp[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, gcd = 0, sum = 0;
	bool even = 0;
	cin >> n;
	vector<int>a(n);
	rep(i, 0, n){
		cin >> a[i];
		even |= (a[i]&1);
		sum += a[i];
	}
	dp[0] = 1;
	rep(i, 0, n){
		for (int j = 1e5; j>=a[i]; j--){
			dp[j]+=dp[j-a[i]];
			if (dp[j]>=MOD) dp[j]%=MOD;
		}
	}
	debug(sum);
	
	if (sum&1){
		cout << "0\n";
		return 0;
	}
	
	debug(dp[sum/2]);
	
	if (dp[sum/2]<2){
		cout << "0\n";
		return 0;
	}
	
	cout << "1\n";
	while (!even){
		rep(i, 0, n) {
			a[i]/=2;
			even |= (a[i]&1);
		}
	}
	rep(i, 0, n){
		if (a[i]&1){
			cout << i+1 << "\n";
			return 0;
		}
	}
	
	
	return 0;
}



