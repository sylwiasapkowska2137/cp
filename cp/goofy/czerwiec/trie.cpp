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
	
	
	int n, k, a, b, ans = 0;
	cin >> n >> k;
	vector<int>deg(n+1, 0);
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
	}
	for (int i = 1; i<=n; i++){
		if (deg[i]>k+1){
			cout << "0\n";
			return 0;
		}
		if (deg[i]<=k) ans++;
	}
	cout << ans << "\n";
	return 0;
}
