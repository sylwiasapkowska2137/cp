#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 1007;
LL tab[MAX][MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> tab[i][j];
		}
	}
	
	for (int j = 1; j<=m; j++){
		for (int i = n; i>=1; i--){
			tab[i][j] += tab[i+1][j];
			tab[0][j] = max(tab[0][j], tab[i][j]);
		}
		
	}
	/*
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			debug(tab[i][j]);
		}
		cerr << "\n";
	}
	cerr << "\n";*/
	LL ans = 0LL;
	for (int i = 1; i<=m; i++) ans += tab[0][i];
	cout << ans << "\n";
	return 0;
}

