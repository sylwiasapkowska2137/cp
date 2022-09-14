#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)

void solve(){
	int n, l, r;
	cin >> n >> l >> r;
	vector<int>a(n);
	rep(i, 0, n) cin >> a[i];
	sort(a.begin(), a.end());
	LL ans = 0LL;
	rep(i, 0, n){
		int x = lower_bound(a.begin(), a.end(), l-a[i])-a.begin();
		x = max(x, i+1);
		int y = upper_bound(a.begin(), a.end(), r-a[i])-a.begin()-1;
		ans += max(0, y-x+1);
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)solve();
	
	return 0;
}

