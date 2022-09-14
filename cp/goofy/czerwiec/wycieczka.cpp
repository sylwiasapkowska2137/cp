#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<pii>a(n+1);
	for (int i = 0; i<n; i++) {
		cin >> a[i].st;
		a[i].nd = i;
	}
	a[n] = {INT_MIN, INT_MIN};
	sort(a.begin(), a.end(), greater<pii>());
	int ans = -1;
	if (a[0].st == a[k].st){
		cout << "-1\n";
		return 0;
	}
	int mini = INT_MAX, maxi = INT_MIN;
	for (int i = 0; i<k; i++){
		mini = min(mini, a[i].nd);
		maxi = max(maxi, a[i].nd);
		if (maxi - mini == i && a[i+1].st < a[i].st) ans = max(ans, i+1);
	}
	cout << ans << "\n";
	return 0;
}

