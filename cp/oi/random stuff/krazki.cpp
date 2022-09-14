#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

vector <int> a;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, val, start = 0;
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i<n; i++)cin >> a[i];
	for (int i = 1; i<n; i++)a[i] = min(a[i], a[i-1]);
	reverse(a.begin(), a.end());
	while (m--){
		cin >> val;
		while (a[start]<val) start++;
		//cout << start << "\n";
		start++;
		if (start >= n) {
			cout << 0;
			return 0;
		}
	}
	if (start == -1) cout << 0;
	else cout << n-start+1 << "\n";
	return 0;
}
