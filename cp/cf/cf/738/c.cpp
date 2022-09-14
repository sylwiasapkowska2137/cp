#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

void solve(){
	int n;
	cin >> n;
	vector<int>a(n);
	rep(i, 0, n) cin >> a[i];
	if (a[0]) {
		cout << n+1 << " ";
		rep(i, 1, n+1) cout << i << " ";
		cout << "\n";
		return;
	}
	if (!a[n-1]){
		rep(i, 1, n+2) cout << i << " ";
		cout << "\n";
		return; 
	}
	rep(i, 1, n){
		if (!a[i-1] && a[i]){
			rep(j, 1, i+1) cout << j << " ";
			cout << n+1 << " ";
			rep(j, i+1, n+1) cout << j << " ";
			cout << "\n";
			return; 
		}
	}
	
	
	cout << "-1\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
