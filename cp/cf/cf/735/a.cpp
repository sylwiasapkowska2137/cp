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
	int n;
	LL a, b, c;
	cin >> n >> a >> b;
	LL maxi = max(a, b);
	LL ans = 0LL;
	if (maxi == a){
		ans = max(ans, a*b);
	}
	rep(i, 2, n){
		cin >> c;
		if (b>=maxi){
			ans = max(ans, (LL)b*(LL)max(a, c));
			maxi = b;
		}
		a = b;
		b = c;
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)solve();
	
	return 0;
}






