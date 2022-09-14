#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	LL k, x;
	cin >> n >> k >> x;
	vector<LL>a(n);
	rep(i, 0, n) cin >> a[i];
	sort(a.begin(), a.end());
	//for (auto x: a) debug(x);
	//cerr << "\n";
	int ans = 1;
	vector<LL>diff;
	rep(i, 1, n){
		//debug(a[i]-a[i-1]);
		if (a[i]-a[i-1]>x) {
			ans++;
			diff.pb(a[i]-a[i-1]);
		}
	}
	//cerr << "\n";
	//debug(ans);
	sort(diff.begin(), diff.end());
	for (auto d: diff){
		LL add = ceil((long double)d/(long double)x)-1;
		if (k >= add){
			k-=add;
			ans--;
		}
	}
	cout << ans << "\n";
	return 0;
}





