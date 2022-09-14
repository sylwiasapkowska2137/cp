#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 1007, KMAX = 21;
LL dp[MAX][MAX][KMAX], poziom[MAX][MAX], pion[MAX][MAX];
int tab[MAX][MAX], r, n, m, k;
deque<pii>q;//(element, indeks)

void pop(int index){
	while (!q.empty() && q.front().nd <= index) q.pop_front();
}

void push(int val, int index){
	while (!q.empty() && q.back().st >= val) q.pop_back();
	q.push_back({val, index});
}

int minimum(){
	return q.front().st;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	cin >> n >> m >> r >> k;
	int R = r;
	for (int i = 1; i<=n; i++){
		for (int j = 1;j<=m; j++){
			cin >> tab[i][j];
		}
	}
	for (int z = 0; z<=k; z++){
		for (int i = 1; i<=n; i++) dp[i][0][z] = 1e15;
		for (int i = 1; i<=m; i++) dp[0][i][z] = 1e15;
	}
	dp[1][0][0] = 0LL;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			dp[i][j][0] = min(dp[i-1][j][0], dp[i][j-1][0])+tab[i][j];
			debug(dp[i][j][0]);
		}
		cerr << "\n";
	}
	cerr << "\n";
	
	int len = r+r+1;
	for (int K = 1; K<=k; K++){
			
		
		for (int x = 1; x<=n; x++){
			q.clear();
			for (int y = 1; y<=m; y++){
				if (y > len) pop(y-len);
				push(dp[x][y][K-1], y);
				poziom[x][y] = minimum(); 
			}
		}
			
		for (int y = 1; y<=m; y++){
			q.clear();
			for (int x = 1; x<=n; x++){
				if (x > len) pop(x-len);
				push(poziom[x][y], x);
				pion[x][y] = minimum(); 
			}
		}
		
		
		/*
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=m; j++){
				debug(poziom[i][j]);
			}
			cerr << "\n";
		}
		cerr << "\n";
		*/
		
		for (int i = 1; i<=n; i++){
			for (int j = 1; j<=m; j++){
				debug(pion[i][j]);
			}
			cerr << "\n";
		}
		cerr << "\n";
		
		for (int x = 1; x<=n; x++){
			for (int y = 1; y<=m; y++){	
				//debug(dp[x][y][K-1]);
				//debug(pion[min(n, x+r)][min(m, y+r)]+tab[x][y]);
				dp[x][y][K] = min(dp[x][y][K-1],  pion[min(n, x+r)][min(m, y+r)]+tab[x][y]); 
				//dp[x][y][K] = min(dp[x][y][K], min(dp[x][y-1][K], dp[x-1][y][K])+tab[x][y]);
				debug(dp[x][y][K]);
				//cerr << "\n";
			}
			cerr << "\n";
		}	
		cerr << "\n";
		
		
	}
	cout << dp[n][m][k];
	return 0;
}


