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

vector<string> powers;

string to(LL n){
	string ans;
	while (n){
		ans += ((n%10)+'0');
		n/=10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

void solve(){
	LL n;
	int ans = INT_MAX;
	cin >> n;
	string s = to(n);
	int x = s.size();
	rep(power, 0, 60){
		int j = 0, k = 0;
		int len = (int)powers[power].size();
		rep(start, 0, x){
			if (powers[power][j] == s[start] && j<len) j++;
		}
		ans = min(ans, x+len-2*j);
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	LL x = 1;
	rep(i, 0, 60){	
		powers.pb(to(x));
		x*=2;
	}
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
