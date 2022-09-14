#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	LL n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++){
		cin >> a[i];
		if (a[i]>0) a[i] = 1;
		else a[i] = -1;
	}
	
	int x = 1, pos = 1, neg = 0;
	for (int i = 0; i<n; i++){
		x *= a[i];
		if (x == 1) pos++;
		else neg++;
	}
	LL ans = (LL)pos*(LL)neg;
	LL dod = n*(n+1)/2 - ans;
	cout << ans << " " << dod << "\n";
	
	return 0;
}
