#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

bool cmp(pii a, pii b){
	return a.st+a.nd < b.st+b.nd;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k = 0;
	LL ans = 0LL;
	cin >> n;
	vector<pii>a(n);
	for (int i = 0; i<n; i++) cin >> a[i].st >> a[i].nd;
	sort(a.begin(), a.end(), cmp);
	for (int i = n-1; i>=0; i--){
		k++;
		if (k&1) ans += (LL)a[i].st;
		else ans -= (LL)a[i].nd;
	}
	cout << ans << "\n";
	return 0;
}
