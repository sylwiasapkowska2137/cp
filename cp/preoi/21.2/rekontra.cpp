#include <bits/stdc++.h>	
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m,p;
	cin >> n >> m >> p;
	vector <int> x(n), y(m), dp1(n), dp2(n);
	for (int i = 0; i<n; i++) cin >> x[i];
	for (int i = 0; i<m; i++) cin >> y[i];
	int mid = m/2;
	for (int k = 0; k<mid; k++){
		for (int i = 0; i<n; i++){
			if (k == 0 && i == 0) dp1[0] = (x[0]+y[0])%p;
			else if (k == 0) dp1[i] = dp1[i-1]+(x[i]+y[0])%p;
			else if (i == 0) dp1[i] += (x[0]+y[k])%p;
			else dp1[i] = max(dp1[i], dp1[i-1])+ (x[i]+y[k])%p;
		}
	}
	for (auto x: dp1) debug(x);
	for (int k = m-1; k>=mid; k--){
		for (int i = n-1; i>=0; i--){
			if (k == m-1 && i == n-1) dp2[i] = (x[i]+y[k])%p;
			else if (k == m-1) dp2[i] = dp2[i+1]+(x[i]+y[k])%p;
			else if (i == n-1) dp2[i] += (x[i]+y[k])%p;
			else dp1[i] = max(dp2[i], dp2[i+1])+ (x[i]+y[k])%p;
		}
	}
	cerr << "\n";
	for (auto x: dp2) debug(x);
	return 0;
}
