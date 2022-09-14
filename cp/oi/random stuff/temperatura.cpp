#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, val = 1, ans = 0, now;
	cin >> n;
	vector <pii> a(n);
	pii prev, curr;
	cin >> prev.st >> prev.nd;
	now = prev.st;
	for (int i = 1; i<n; i++){
		cin >> curr.st >> curr.nd;
		now = max(now, curr.st);
		if (now > curr.nd){
			ans = max(ans, val);
			val = 1;
			now = curr.st;
		} else val++;
		prev = curr;
	}
	ans = max(ans, val);
	cout << ans;
	return 0;
}
