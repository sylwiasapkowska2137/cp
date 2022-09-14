#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define ok cerr << "\n"
#define pb push_back
const 

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	vector<int>freq(n+1, 0);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		freq[a[i]]++;
	}
	int ans = 0;
	for (int i = 0; i<=n; i++) ans += min(freq[i], k);
	cout << min(ans/k, n/k) << "\n";
	for (int i = 0; i<n; i++){
		
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}
