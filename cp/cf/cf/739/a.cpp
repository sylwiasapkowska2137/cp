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

vector<int>ans;

void solve(){
	int n;
	cin >> n;
	cout << ans[n-1] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	rep(i, 1, 2000){
		if (i%3 == 0 || i%10==3) continue;
		ans.pb(i);
	}
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
