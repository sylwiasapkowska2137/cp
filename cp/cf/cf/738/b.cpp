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
	string s, ans;
	cin >> s;
	int cnt = 0, x;
	while (s[cnt] == '?' && cnt<n) cnt++;
	x = cnt;
	if (cnt == n) {
		rep(i, 0, n){
			if (i&1) cout << "B";
			else cout << "R";
		}
		cout << "\n";
		return;
	}
	
	
	//cnt--;
	if (s[cnt] == 'R'){
		int k = 1;
		while (cnt>0){
			if (k&1) ans+="B";
			else ans+="R";
			k++;
			cnt--;
		}
	} else {
		bool k = 0;
		while (cnt>0){
			if (k) ans+="B";
			else ans+="R";
			k^=1;
			cnt--;
		}
	}
	reverse(ans.begin(), ans.end());
	//cout << ans;
	for (int i = x; i<n; i++){
		if (s[i] == '?' && ans[i-1] == 'R') ans+="B";
		else if (s[i] == '?' && ans[i-1] == 'B') ans+="R";
		else ans+=s[i];
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
