#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define fastio ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0)

int main(){
	fastio;
	int n;
	LL minn = 1e9+7, maxn = -1e9+7, suma = 0;
	cin >> n;
	vector<LL>a(n+1, 0LL), mini(n+1), maxi(n+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		suma+=(LL)a[i];
		if (maxi[i-1]>=0LL) maxi[i] = maxi[i-1]+a[i];
		else maxi[i] = a[i];	
		if (mini[i-1]<=0LL) mini[i] = mini[i-1]+a[i];
		else mini[i] = a[i];
		minn = min(minn, mini[i]);
		maxn = max(maxn, maxi[i]);
	}
	cout << suma-minn;
	return 0;
}


