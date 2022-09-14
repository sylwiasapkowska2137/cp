#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 1007;
bool tab[MAX][MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	char c;
	cin >> n;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin >> c;
			if (c == 'B') tab[i][j] = 1;
		}
	}
	
	return 0;
}
