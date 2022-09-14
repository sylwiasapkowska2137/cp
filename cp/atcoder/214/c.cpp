#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, index, mini = INT_MAX, prev;
	cin >> n;
	vector<int>s(n), t(n);
	vector<LL>ans(n+1);
	rep(i, 0, n) cin >> s[i];
	rep(i, 0, n) {
		cin >> t[i];
		if (t[i]<mini){
			mini = t[i];
			index = i;
		}
	}
	
	ans[index] = t[index];
	rep(i, 1, n){
		prev = index;
		index = (index == n-1)?0: index+1;
		ans[index] = min((LL)s[prev]+ans[prev], (LL)t[index]);
	}
	rep(i, 0, n) cout << ans[i] << "\n";
	
	return 0;
}




