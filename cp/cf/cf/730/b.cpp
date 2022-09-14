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
	int n;
	LL sum = 0;
	cin >> n;
	vector<int>a(n);
	rep(i, 0, n) {
		cin >> a[i];
		sum+=a[i];
	}
	//debug(sum);
	LL m = sum%n;
	cout << m*(n-m) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
