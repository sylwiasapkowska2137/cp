#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int L = 0, R = 0;
	int cnt[2] = {0, 0};
	int ans = 0;
	cnt[s[0]-'a']++;
	while (L<n){
		while (R+1 < n){
			int x = min(cnt[0]+(s[R+1]=='a'?1:0), cnt[1]+(s[R+1]=='b'?1:0));
			if (x <= k) {
				R++;
				cnt[s[R]-'a']++;
			}
			else break;
		}
		ans = max(ans, R-L+1);
		cnt[s[L]-'a']--;
		L++;
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}