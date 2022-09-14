#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

vector<vector<LL>>tab, pref;
int n, m, c, d;

bool warunek(int z){
	
}

LL binsearch(int start, int koniec){
	LL ans = -1;
	while (koniec-start>1){
		int z = (start+koniec)/2;
		debug(z);
		if (warunek(z)){
			koniec = z-1;
		} else start = z+1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> c >> d;
	tab.resize(n+1, vector<LL>(m+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> tab[i][j];
		}
	}

	
	return 0;
}
