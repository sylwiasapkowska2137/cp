#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, ans = 0, mini = INT_MAX, maxi = INT_MIN;
	cin >> n;
	vector<int>a(n), pos(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		pos[a[i]-1] = i;
	}
	for (int i = 0; i<n; i++){
		mini = min(mini, pos[i]);
		maxi = max(maxi, pos[i]);
		if (maxi-mini+1 == i+1) ans++;
	}
	cout << ans << "\n";\
	return 0;
}
