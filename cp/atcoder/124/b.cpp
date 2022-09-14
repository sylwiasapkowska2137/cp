#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int>a(n), b(n), ans;
	for (int i = 0; i<n; i++) cin >> a[i];
	for (int i = 0; i<n; i++) cin >> b[i];
	sort(b.begin(), b.end());
	for (int i = 0; i<n; i++){
		int x = a[0]^b[i];
		vector<int>c(n);
		for (int j = 0; j<n; j++) c[j] = a[j]^x;
		sort(c.begin(), c.end());
		bool ok = 0;
		for (int j = 0; j<n; j++){
			if (c[j]!=b[j]){
				ok = 1;
				break;
			}
		}
		if (ok) continue;
		ans.pb(x);
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x << "\n";
	return 0;
}
