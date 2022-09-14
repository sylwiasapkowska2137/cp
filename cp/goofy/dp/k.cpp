#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
#define dbg if(1)

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	vector<bool>dp(k+1);
	for (int i = 0; i<n; i++) cin >> a[i];
	for (int i = 1; i<=k; i++){
		for (int j: a){
			if (i>=j && !dp[i-j]) dp[i] = 1;
		}
	}
	if (dp[k]) cout << "Bitek\n";
	else cout << "Bajtek\n";
	return 0;
}
