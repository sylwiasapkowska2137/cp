#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<LL, LL>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 1e5+7;
pll dp[MAX][2];

bool comp(pll a, pll b){
	return a.st*b.nd > a.nd * b.st;
}


pll maxx(pll a, pll b){
	if (comp(a, b)) return a;
	return b;
}

pll minn(pll a, pll b){
	if (comp(a, b)) return b;
	return a;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i<n; i++){
		if (i == 0){
			dp[0][0] = {1, 1};
			dp[0][1] = {a[0], 1};
		} else {
			dp[i][0] = maxx(dp[i-1][0], dp[i-1][1]);
			LL tmp = (a[i]*dp[i][0].nd)/dp[i][0].st;
			if (tmp)dp[i][1] = minn(dp[i][0], {a[i], tmp});
			else dp[i][1] = dp[i][0];
		}
	}
	pll ans = {0, 0};
	for (int i = 0; i<n; i++){
		//debug(dp[i][0].st);
		//debug(dp[i][0].nd);
		ans = max(ans, dp[i][0]);
		ans = max(ans, dp[i][1]);
	}
	/*
	cerr << "\n";
	for (int i = 0; i<n; i++){
		debug(dp[i][1].st);
		debug(dp[i][1].nd);
	}
	cerr << "\n";*/
	LL d = __gcd(ans.st, ans.nd);
	cout << ans.st/d << " " << ans.nd/d << "\n";
	return 0;
}


