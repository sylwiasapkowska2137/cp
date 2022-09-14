#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX = 3e3+7;
int L[MAX][MAX]; 

void lcs(string x, string y, int n, int m) { 
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= m; j++) { 
			if (x[i - 1] == y[j - 1]) L[i][j] = L[i - 1][j - 1] + 1; 
			else L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
		} 
	} 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string x, y;
	int n, m, t, a, b, c, d;
	cin >> n >> m >> t >> x >> y;
	lcs(x,y,n,m);
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cerr << L[i][j] << " ";
		}
		cerr << "\n";
	}
	while (t--){
		cin >> a >> b >> c >> d;
		int suma = L[d][b]-L[c-1][b]-L[d][a-1]+L[c][a];
		cout << suma << "\n";
	}
	return 0;
}
