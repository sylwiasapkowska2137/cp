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
	int n, x;
	bool ok = 0;
	cin >> n;
	vector<int>pref(n+1);
	pref[0] = 0;
	rep(i, 0, n) {
		cin >> x;
		pref[i+1] = pref[i]^x;
	}
	if (!pref[n]) ok = 1;
	rep(i, 1, n+1){
		rep(j, i+1, n){
			ok |= (pref[i] == (pref[j]^pref[i]) && pref[i] == (pref[n]^pref[j]));
		}
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}


