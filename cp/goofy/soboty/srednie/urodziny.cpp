#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pb push_back
#define st first
#define nd second
#define pii pair <int, int>
#define debug(x) cerr << x << " "


bool dp[507][50007];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a, b, diff;
	cin >> n;
	vector <int> tab(n);
	LL suma = 0;
	for (int i = 0; i<n; i++){
		cin >> a >> b;
		diff = abs(a-b);
		tab[i] = diff;
		suma += (LL)diff;
	}
	//debug(suma);
	dp[0][0] = 1;
	for (int i = 0; i<=n; i++) dp[i][0] = 1;
	for (int i = 1; i<=suma; i++) dp[0][i] = 0;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=suma; j++){
			dp[i][j] = dp[i-1][j];
			if (tab[i-1] <= j) dp[i][j] = dp[i][j] | dp[i-1][j-tab[i-1]];
		}
	}
	for (int i = suma/2; i>=0; i--){
		if (dp[n][i] == 1){
			cout << suma-2*i << "\n";
			return 0;
		}
	}
}

