#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	LL a, b;
	cin >> a >> b;
	LL ans = __gcd(a, b);
	if (a != b) ans = 1;
	cout << ans << "\n";
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		if (a == b) {
			ans = __gcd(a, ans);
			cout << ans << "\n";
		}else cout << "1\n";
	}
	
	return 0;
}

