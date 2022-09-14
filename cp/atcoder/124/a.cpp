#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define ok cerr << "\n"
#define pb push_back

const LL MOD = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, b;
	char c;
	cin >> n >> k;
	vector<bool>vis(n+1, 0);
	vector<int>a(n+1, 0);
	
	for (int i = 0; i<k; i++){
		cin >> c >> b;
		vis[b] = 1;
		if (c == 'R'){
			for (int j = 1; j<=b; j++) a[j]++;
		} else {
			for (int j = b; j<=n; j++) a[j]++;
		}
	}
	LL ans = 1;
	for (int i = 1; i<=n; i++){
		if (!vis[i]){
			ans = (ans*a[i]);
			if (ans >= MOD) ans%=MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}





