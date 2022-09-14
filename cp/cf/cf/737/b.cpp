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
	int n, k;
	cin >> n >> k;
	vector<pii>a(n);
	rep(i, 0, n){
		cin >> a[i].st;
		a[i].nd = i;
	}
	sort(a.begin(), a.end());
	//debug(a[0].st);
	//debug(a[0].nd);
	//cerr << "\n";
	rep(i, 1, n){
		//debug(a[i].st);
		//debug(a[i].nd);
		//cerr << "\n";
		if (a[i].nd - a[i-1].nd == 1) continue;
		k--;
	}
	//debug(k);
	if (k>0) cout << "YES\n";
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
