#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

void solve(){
	int n, ans = 0;
	cin >> n;
	vector<string>s(n);
	rep(i, 0, n) cin >> s[i];
	int f[n][5];
	memset(f, 0, sizeof(f));
	rep(i, 0, n){
		for (char c: s[i]){
			f[i][c-'a']++;
		}
	}
	for (char i = 'a'; i<='e'; i++){
		vector<int>b(n);
		rep(j, 0, n) b[j] = 2*f[j][i-'a']-s[j].size();
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		int q = 0, c = 0;
		rep(j, 0, n){
			if (q + b[j] > 0){
				c++;
				q+=b[j];
			} else break;
		}
		ans = max(ans, c);
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
