#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define pb push_back
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int K = 20; 
const LL INF = 1e18;
LL cnt[K][K];
LL dp[(1<<K)+1];
vector<int>indeks[K];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		a[i]--;
		indeks[a[i]].pb(i);
	}
	
	//count cnt
	for (int i = 0; i<K; i++){
		for (int j = 0; j<K; j++){
			if (i == j) continue;
			if (indeks[i].empty() || indeks[j].empty()) continue;
			int pos2 = 0;
			for (int pos1 = 0; pos1 < (int)indeks[i].size(); pos1++) {
				while (1) {
					if (pos2 == (int)indeks[j].size()-1 || indeks[j][pos2+1] > indeks[i][pos1]) break;
					pos2++;
				}
				if (indeks[i][pos1] > indeks[j][pos2]) cnt[i][j] += pos2 + 1;
			}
		}
	}
	
	for (int i = 1; i<(1<<K); i++) dp[i] = INF;
	dp[0] = 0;
	for (int mask = 0; mask<(1<<K); mask++){
		for (int i = 0; i<K; i++){
			if (mask&(1<<i)) continue;
			LL sum = 0LL;
			for (int j = 0; j<K; j++){
				if (mask&(1<<j)) sum += cnt[j][i];
			}
			dp[mask|(1<<i)] = min(dp[mask|(1<<i)], dp[mask]+sum);
		}
	}
	cout << dp[(1<<K)-1] << "\n";
	return 0;
}
