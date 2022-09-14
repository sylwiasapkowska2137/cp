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
	cin >> n;
	vector<int>a(n+2, -1);
	a[0] = INT_MAX;a[n+1] = INT_MAX;
	if (n == 1) {
		cout << "! " << 1 << "\n";cout.flush();
		return;
	}
	int start = 1, koniec = n;
	while (koniec > start){
		int m = (start+koniec)/2;
		rep(i, m-1, m+2){
			if (a[i]==-1) {
				cout << "? " << i << "\n";cout.flush();
				cin >> a[i];
			}	
		}
		if (a[m-1]>a[m] && a[m]<a[m+1]){
			cout << "! " << m << "\n";cout.flush();
			return;
		}
		if (a[m]>a[m+1]){
			start = m+1;
			continue;
		}
		koniec = m;
	}
	cout << "! " << start << "\n";cout.flush();
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
