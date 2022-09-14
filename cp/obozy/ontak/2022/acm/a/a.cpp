#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return {i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef XOX
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (c it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(x...) " [" #x ": " << (x) << "] "

#define int long long
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define pii pair<int,int>
#define vt vector

void test_case() {
	int n,m;
	cin>>n>>m;
	vt<vt<int>> N(n+1,vt<int>(m+1));
	vt<vt<int>> E(n+1,vt<int>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>N[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>E[i][j];
		}
	}
	vt<vt<vt<int>>> dp(n+2,vt<vt<int>>(m+2,vt<int>(2)));
	vt<vt<int>> sufcol(n+2,vt<int>(m+2));
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			sufcol[i][j] += sufcol[i][j+1] + E[i][j];
		}
	}
	vt<vt<int>> prewie(n+2,vt<int>(m+2));
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			prewie[i][j] += prewie[i-1][j] + N[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp[i][j][0] = prewie[i][j] + max(dp[i][j+1][0], dp[i][j+1][1]);
			dp[i][j][1] = sufcol[i][j] + max(dp[i-1][j][0], dp[i-1][j][1]);
		}
	}
	// for (int i = 1; i<=n; i++){
	// 	for (int j = 1; j<=m; j++){
	// 		cerr << dp[i][j][0] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	// cerr << "\n";
	// for (int i = 1; i<=n; i++){
	// 	for (int j = 1; j<=m; j++){
	// 		cerr << dp[i][j][1] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	// cerr << "\n";
	// for (int i = 1; i<=n; i++){
	// 	for (int j = 1; j<=m; j++){
	// 		cerr << prewie[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	// cerr << "\n";
	// for (int i = 1; i<=n; i++){
	// 	for (int j = 1; j<=m; j++){
	// 		cerr << sufcol[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	// cerr << "\n";
	cout << max(dp[n][1][0], dp[n][1][1]) << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		test_case();
	}
}
