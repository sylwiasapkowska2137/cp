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
	int n, x, mini = 1e9, maxi = 0, indexmin, indexmax;
	cin >> n;
	rep(i, 0, n) {
		cin >> x;
		if (x > maxi){
			maxi = x;
			indexmax = i;
		}
		if (x < mini){
			mini = x;
			indexmin = i;
		}
	}
	indexmin++;
	indexmax++;
	//4 przypadki
	if (indexmin > indexmax) swap(indexmin, indexmax);
	//indexmin na lewo
	int ans = INT_MAX;
	ans = min(indexmin+n-indexmax+1, ans);
	ans = min(n-indexmin+1, ans);
	ans = min(indexmax, ans);
	ans = min(indexmax+n-indexmin+1, ans);
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)solve();
	
	return 0;
}
