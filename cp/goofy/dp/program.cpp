#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define pb push_back
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 1e6;

struct interval{
	int l, r, val;
	interval(){}
	interval(int l, int r, int val): l(l), r(r), val(val) {}
};

bool warunek(int m, int k, vector<interval>&a){
	int n = a.size();
	vector<int>dp(n, 0);
	//debug(m);
	//cerr << "\n";
	for (int i = 0; i<n; i++){
		for (int j = 0; j<i; j++){
			if (a[j].val < m) continue;
			if (a[i].l > a[j].r || a[i].r < a[j].l) dp[i] = max(dp[i], dp[j]);
		}
		dp[i]++;
	}
	//for (auto x: dp) debug(x);
	//cerr << "\n";
	if (dp[n-1]>=k) return 1;
	return 0;
}

int binsearch(int start, int koniec, int k, vector<interval>&a){
	int ans = -2;
	while (koniec > start){
		int m = (start+koniec)/2;
		if (warunek(m, k, a)){
			start = m+1;
			ans = m;
		} else koniec = m-1;
	}
	if (warunek(start, k, a)) ans++;
	if (ans <= 0) return -1;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<interval>a(n);
	for (int i = 0; i<n; i++) cin >> a[i].l >> a[i].r >> a[i].val;
	cout << binsearch(1, MAX, k, a) << "\n";
	return 0;
}
