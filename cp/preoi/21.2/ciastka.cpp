#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "
#define LL long long
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL n, x, a, b;
	cin >> n >> x >> a >> b;
	vector <LL> arr(n+1), pre(n+1), mini(n+1);
	pre[0] = arr[0] = x;
	for (int i = 1; i<=n; i++){
		cin >> arr[i];
		pre[i] = pre[i-1]+arr[i];
		if (pre[i]>b){
			cout << "-1\n";
			return 0;
		}
	}
	mini[n] = b-pre[n];
	for (int i = n-1; i>=0; i--){
		mini[i] = min(mini[i+1], b-pre[i]);
	}
	LL val = 0LL, ans = 0LL, all = 0LL;
	for (int i = 1; i<=n; i++){
		pre[i] = pre[i-1]+arr[i];
		if (pre[i]<a){
			ans++;
			pre[i]+=(mini[i-1]-val);
			if (pre[i]<a){
				cout << "-1\n";
				return 0;
			}
			val=mini[i-1];
		}
	}
	//cerr << "\n";
	//for (auto x: mini)debug(x);
	cout << ans;
	return 0;
}
