#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
#define dbg if(1)

const int MAX = 1007;
LL dp[MAX][MAX];
const LL MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int h, w;
	char c;
	cin >> h >> w;
	for (int i = 1; i<=h; i++){
		for (int j = 1; j<=w; j++){
			cin >> c;
			if (i == 1 && j == 1){
				if (c == '#'){
					cout << "0\n";
					return 0;
				} else dp[i][j] = 1;
			} else {
				if (c == '#') dp[i][j] = 0;
				else dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
			}
			
		}
	}
	cout << dp[h][w] << "\n";
	return 0;
}




