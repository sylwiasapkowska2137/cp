#include <bits/stdc++.h>
using namespace std;

#define int long long
const int oo = 1e18;

void solve(){
	int n, m; cin >> n >> m;
	vector<int>a(m+1);
	for (int i = 1; i<=m; i++) cin >> a[i];

	auto check = [&](int mid){
		int ret = 0;
		for (int i = 1; i<=m; i++) ret += a[i]/mid;
		return ret;
	};
	auto check2 = [&](int mid){
		vector<int>ret(m+1);
		for (int i = 1; i<=m; i++) ret[i] = a[i]/mid;
		return ret;
	};
	int L = 1, R = n, ans = 1;
	while (R >= L){
		int mid = (L+R)/2;
		if (check(mid) >= n) {
			ans = mid;
			L = mid+1;
		} else R = mid-1;
	}
	if (ans == 1){
		vector<int>now = check2(ans);
		int s = accumulate(now.begin(), now.end(), 0);
		if (s < n){
			cout << "TAK\n" << n << " ";
			for (int i = 1; i<=n; i++) cout << "0 ";
			cout << "\n";
			return;
		}
	}
	// cout << ans << "\n";
	cout << "TAK" << "\n";
	vector<int>curr = check2(ans);
	for (int i = 1; i<=m; i++) {
		cout << min(n, curr[i]) << " ";
		n -= curr[i];
		n = max(n, 0LL);
	}
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
