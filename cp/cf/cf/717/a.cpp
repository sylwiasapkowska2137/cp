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
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n-1){
		if (k >= a[i]){
			k-=a[i];
			a[n-1]+=a[i];
			a[i] = 0;
		} else {
			a[i]-=k;
			a[n-1]+=k;
			break;
		}
	}
	rep(i, 0, n) cout << a[i] << " ";
	cout << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}

