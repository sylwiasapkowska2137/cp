//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
const int oo = 1e18, K = 30;
int N, M;


void solve(){
	int n, m; cin >> n >> m;
	vector a(n+1, vector<int>(m+1));
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			cin >> a[i][j];
		}
	}

	cin >> N >> M;
	vector<int>b;
	for (int i = 0; i<N*M; i++) {
		int x; cin >> x;
		b.emplace_back(x);
	}

	for (int mask = 0; mask < (1<<n); mask++){
		for (int mask2 = 0; mask2 < (1<<m); mask2++){
			vector<int>tab;
			int x = __builtin_popcount(mask);
			for (int i = 1; i<=n; i++){
				for (int j = 1; j<=m; j++){
					if ((mask&(1<<(i-1))) || (mask2&(1<<(j-1)))) continue;
					tab.emplace_back(a[i][j]);
				}
			}
			if (tab == b && n-x == N){
				cout << "Yes\n";
				exit(0);
			}

		}
	}
	cout << "No\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
