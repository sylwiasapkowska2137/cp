#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

void solve(){
	LD n, suma = 0LL, maxi = INT_MIN, x;
	cin >> n;
	rep(i, 0, n){
		cin >> x;
		suma+=x;
		maxi = max(maxi, x);
	}
	cout << setprecision(10) << fixed;
	cout << maxi + (suma-maxi)/(n-1) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
