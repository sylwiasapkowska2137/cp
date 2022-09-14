#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

void solve(){
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	cout << "0 ";
	for (int i = 1; i<n; i++) {
		int ans = 0;
		for (int k = 0; k<31; k++){
			if ((a[i-1]&(1<<k)) && !(a[i]&(1<<k))) {
				ans+=(1<<k);
			}
		}
		a[i] = a[i]^ans;
		cout << ans << " ";
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}


