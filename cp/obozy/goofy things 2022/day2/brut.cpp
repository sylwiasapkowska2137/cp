#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int>pii;
typedef vector<int> vi;
typedef vector<LL> vll;

#define debug(x) cerr << x << " "
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)
#define pb push_back

void solve(){
	int n, q, k; cin >> n >> q >> k;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	while (q--){
		int x, y; cin >> x >> y;
		vi tab;
		--x;--y;
		rep(i, x, y+1) tab.pb(a[i]);
		sort(all(tab));
		//for (auto x: tab) debug(x);
		//cerr << "\n";
		int ans = 0;
		if (tab[0] > k){
			cout << y-x+1 << "\n";
			continue;
		}
		
		while (sz(tab)>1 && tab.back()+tab[sz(tab)-2] > k){
			tab.pop_back();
			ans++;
		}
		
		if (sz(tab) == 1){
			if (tab[0] > k) ans++;
		} 
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}
