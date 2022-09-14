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

void solve(){
	LL a, b, c;
	cin >> a >> b >> c;
	LL n = abs(b-a);
	if (c > 2*n || a > 2*n || b>2*n) cout << "-1\n";
	else {
		c += n;
		if (c > 2*n) c = c-=2*n;
		cout << c << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
