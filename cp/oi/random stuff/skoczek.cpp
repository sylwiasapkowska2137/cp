#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

void solve(){
	int n, a, b, x = 0, y = 0;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> a >> b;
		x = __gcd(x, a);
		y = __gcd(y, b);
	}
	//debug(x);
	//debug(y);
	if (abs(x) == 1 && abs(y) == 1) cout << "TAK\n";
	else cout << "NIE\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
