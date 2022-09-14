#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second

const int MAX = 3007;
bool vis[MAX][MAX];
int h[MAX][MAX];
int n;
char s[MAX][MAX];
LL ans;
/*
int calc(int i, int j){
	if (s[i][j]!='1') return 0;
	if (vis[i][j]) return h[i][j];
	vis[i][j] = 1;
	h[i][j] = min(calc(i+1, j), min(calc(i+1, j-1), calc(i+1, j+1)))+1;
	ans += (LL)(h[i][j]);
	return h[i][j];
}*/

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			cin >> s[i][j];
		}
	}
	for (int i = n; i>=1; i--){
		for (int j = n; j>=1; j--){
			if (s[i][j] == '1') {
				h[i][j] = min(h[i+1][j], min(h[i+1][j-1], h[i+1][j+1]))+1;
				ans += (LL)(h[i][j]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

