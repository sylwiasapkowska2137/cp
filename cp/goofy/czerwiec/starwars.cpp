#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

vector<int>a;

int binsearch(int start, int koniec, int val){
	int x = -1;
	while (koniec >= start){
		int m = (start+koniec)/2;
		//debug(m);
		if (a[m] == val) return m; //val < a[m]
		else if (a[m]<val) start = m+1;
		else koniec = m-1;
	}
	return x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	a.resize(n);
	
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	//for (auto x: a) debug(x);
	vector<int>dp(a.size()+1, 1);
	int ans = 1;
	for (int i = 0; i<(int)a.size(); i++){
		int x = binsearch(0, a.size()-1, a[i]-k);
		if (x != -1)dp[i] = max(dp[x]+1, dp[i]);
	}
	for (int i = 0; i<(int)dp.size(); i++) ans = max(ans, dp[i]);
	cout << ans << "\n";
	return 0;
}
