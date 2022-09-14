#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)
#define lg(x) (31-__builtin_clz(x))
void solve(){
	int n, ans = 0;
	cin >> n;
	vector<double>a(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 1, n){
		double x = ceil((double)max(a[i], a[i-1])/(double)min(a[i], a[i-1]));
		//debug(x);
		if (x<=2)continue;
		ans += 31-__builtin_clz(x-1);
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
