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
	int n, x, odd = 0, even = 0;
	cin >> n;
	n+=n;
	rep(i, 0, n) {
		cin >> x;
		if (x&1) odd++;
		else even++;
	}
	if (even == odd) cout << "YES\n";
	else cout << "NO\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}


