#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "
const int MAX = 1e6+7, K = 20;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, q, a, b, x1, x2, y1, y2;
	cin >> n >> m >> q;
	if (n <= m){
		vector<vector<vector<int>>> tab(n+1, vector<vector<int>>(m+1, vector<int>(K)));
		for (int a = 0; a < n; a++){
			for (int i = 0; i<m; i++){
				cin >> tab[a][i][0];
			}
			for (int j = 1; j<=log2(m); j++){
				for (int i = 0; i+(1<<(j-1))<m; i++){
					tab[a][i][j] = min(tab[a][i][j-1], tab[a][i+(1<<(j-1))][j-1]);
				}
			}
		}
		while (q--){
			cin >> x1 >> y1 >> x2 >> y2;
			x1--;x2--;y1--;y2--;
			int len = y2-y1+1;
			int k = log2(len);
			int mini = 1e9+7;
			for (int i = x1; i<=x2; i++){
				mini = min(mini, min(tab[i][y1][k],tab[i][y2+1-(1<<k)][k]));
			}
			cout << mini << "\n";
		}
	} else {
		vector<vector<vector<int>>> tab(m+1, vector<vector<int>>(n+1, vector<int>(K)));
		for (int a = 0; a < n; a++){
			for (int i = 0; i<m; i++){
				cin >> tab[i][a][0];
			}
		}
		for (int i = 0; i<m; i++){
			for (int log = 1; log <= log2(n); log++){
				for (int a = 0; a+(1<<(log-1))< n; a++){
					tab[i][a][log] = min(tab[i][a][log-1],tab[i][a+(1<<(log-1))][log-1]);
				}
			}
		}
		while (q--){
			cin >> x1 >> y1 >> x2 >> y2;
			x1--;x2--;y1--;y2--;
			int len = x2-x1+1;
			int k = log2(len);
			int mini = 1e9+7;
			for (int i = y1; i<=y2; i++){
				mini = min(mini, min(tab[i][x1][k],tab[i][x2+1-(1<<k)][k]));
			}
			cout << mini << "\n";
		}
	}
	return 0;
}
