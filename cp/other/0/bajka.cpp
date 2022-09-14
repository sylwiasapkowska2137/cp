#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "

LL calc(LL n){
	LL ans = 0LL, mini = n;
	for (LL i = 1; i*i<=n; i++){
		LL left = n/(i+1), right = n/i;
		if (left>=right) continue;
		mini = left;
		ans += (i*((right*(right+1)/2-left*(left+1)/2)));

	}
	for (int i = 1; i<=mini; i++) ans+= ((n/i)*i);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int z;
        LL ans, n;
	cin >> z;
	while (z--){
		cin >> n;
		ans = n*n;
		ans -= calc(n);
		cout << ans << "\n";
	}
	return 0;
}
