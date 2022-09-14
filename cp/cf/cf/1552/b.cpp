#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define ok cerr << "\n"
#define pb push_back

const int MAX = 5e4+7;
int cnt[MAX][5];

void solve(){
	int n, w = 1, x;
	cin >> n;
	for (int i = 1; i<=n; i++){
		for (int j = 0; j<5; j++){
			cin >> cnt[i][j];
		}
	}
	for (int i = 1; i<=n; i++){
		int ans = 0;
		for (int j = 0; j<5; j++){
			if (cnt[i][j]<cnt[w][j]) ans++;
		}
		if (ans >= 3) w = i;
	}
	for (int i = 1; i<=n; i++) {
		if (i == w) continue;
		int ans = 0;
		for (int j = 0; j<5; j++){
			if (cnt[i][j]<cnt[w][j]) ans++;
		}
		if (ans >= 3){
			cout << "-1\n";
			return;
		}
	}
	cout << w << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}




