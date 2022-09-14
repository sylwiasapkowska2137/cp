#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MOD = 1000007;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	LL n;
	cin >> t;
	while (t--){
		cin >> n;
		LL x = 3*n*(n-1)/2 + 2*n;
		x = ((x%MOD)+MOD)%MOD;
		cout << x << "\n";
	}
	
	return 0;
}

