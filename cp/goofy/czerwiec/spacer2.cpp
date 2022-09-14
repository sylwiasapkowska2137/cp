#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int,int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 1007, MAXK = 21;
LL dp[MAX][MAX][MAXK], poziom[MAX][MAX], pion[MAX][MAX];
int tab[MAX][MAX];
int n, m, r, k, len;
deque<pair<LL, int>>q;

void pop(int index){
	while (!q.empty() && q.front().nd < index) q.pop_front();
}

void push(LL val, int index){
	while (!q.empty() && q.back().st >= val) q.pop_back();
	q.push_back({val, index});
}

LL minimum(){
	return q.front().st;
}

void pop2(int index){
	while (!q.empty() && q.front().nd > index) q.pop_front();
}

void countmin(int K){
	for (int x = 0; x<n; x++){
		q.clear();
		for (int y = 0; y<m; y++){
			if (y > len) pop(y-len);
			push(dp[x][y][K-1], y);
			poziom[x][y] = minimum();
		}
		q.clear();
		//w drugą stronę min
		for (int y = m-1; y>=0; y--){
			int index = m-1-y;
			if (index > len+1) pop(index-len-1);
			push(dp[x][y][K-1], index);
			poziom[x][y] = min(poziom[x][y], minimum());
		}
	}
	
	for (int x = 0; x<n; x++){
		for (int y = 0; y<m; y++){
			debug(poziom[x][y]);
		}
		cerr << "\n";
	}
	cerr << "\n";
	
	for (int y = 0; y<m; y++){
		q.clear();
		for (int x = 0; x<n; x++){
			if (x > len) pop(x-len);
			push(poziom[x][y], x);
			pion[x][y] = minimum();
		}
		q.clear();
		//w drugą stronę min
		for (int x = n-1; x>=0; x--){
			int index = m-1-x;
			if (index > len+1) pop(index-len-1);
			push(poziom[x][y], index);
			pion[x][y] = min(pion[x][y], minimum());
		}
	}
	
	for (int x = 0; x<n; x++){
		for (int y = 0; y<m; y++){
			debug(pion[x][y]);
		}
		cerr << "\n";
	}
	cerr << "\n";
	
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n >> m >> r >> k;
	len = r;
	for (int x = 0; x<n; x++){
		for (int y = 0; y<m; y++){
			cin >> tab[x][y];
		}
	}
	
	//k = 0;
	dp[0][0][0] = (LL)tab[0][0];
	for (int x = 1; x<n; x++) dp[x][0][0] = dp[x-1][0][0]+tab[x][0];
	for (int y = 1; y<m; y++) dp[0][y][0] = dp[0][y-1][0]+tab[0][y];
	for (int x = 1; x<n; x++){
		for (int y = 1; y<m; y++){
			dp[x][y][0] = min(dp[x-1][y][0], dp[x][y-1][0])+tab[x][y];	
		}
	}
	
	for (int x = 0; x<n; x++){
		for (int y = 0; y<m; y++){
			debug(dp[x][y][0]);
		}
		cerr << "\n";
	}
	
	for (int K = 1; K<=k; K++){
		countmin(K);
		
		//count dp[x][y][K]
		
		
	}
	
	return 0;
}
