#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 5007;
LL res[MAX][MAX];
int a[MAX], b[MAX];

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int i = 1; i<=n; i++) cin >> b[i];
	
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			if (a[i]==b[j])	{
				res[i][j] = res[i-1][j-1]+(LL)b[j];
			} else {
				res[i][j] = max(res[i-1][j], res[i][j-1]);
			}
			//debug(suma[i][j]);
		}
		//cerr << "\n";
	}
	cout << res[n][n];
	return 0;
}
