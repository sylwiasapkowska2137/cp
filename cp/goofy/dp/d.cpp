#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
#define dbg if(1)
 
const int N = 1007;
LL dp[N];
int w[N], val[N];
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, p;
	cin >> n >> p;
	for (int i = 0; i<n; i++) cin >> w[i] >> val[i];
	
	for (int i = 0; i<n; i++){
		for (int j = p; j>=0; j--){
			if (w[i]<=j) dp[j] = max(dp[j], dp[j-w[i]]+val[i]);
		}
	}
	cout << dp[p] << "\n";
	return 0;
}
 
