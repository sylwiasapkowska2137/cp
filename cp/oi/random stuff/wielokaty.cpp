#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, x, y, val = -1, ans = 0;
	cin >> n >> m;
	vector <bool> a(n, 0);
	a[0] = 1;
	for (int i = 0; i<m; i++){
		cin >> x >> y;
		x--;y--;
		a[max(x, y)-min(x, y)] = 1;
	}
	vector <int> res;
	for (int i = 0; i<n; i++){
		if (a[i]) res.push_back(i);
	}
	if (m == 0) {
		cout << n;
		return 0;
	}
	int k = res.size();
	for (int i = 1; i<k; i++){
		if (ans <= res[i]-res[i-1]){
			ans = res[i] - res[i-1];
			val = i-1;
		}
		//debug(val);
	}
	if (ans < n-res[k-1]){
		ans = n-res[k-1];
		val = 0;
	}
	//debug(val);
	if (val == 0) cout << ans+1 << "\n";
	else cout << ans+2 << "\n";
}
