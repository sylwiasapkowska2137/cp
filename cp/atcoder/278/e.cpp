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
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

void solve(){
	int H, W, n, h, w; cin >> H >> W >> n >> h >> w;
	vector a(H+1, vector<int>(W+1));
	vector<int>all(n+1);
	int haha = 0;
	for (int i = 1; i<=H; i++){
		for (int j = 1; j<=W; j++){
			cin >> a[i][j];
			all[a[i][j]]++;
			if (all[a[i][j]] == 1) haha++;
		}
	}
	vector ans(H+1, vector<int>(W+1));
	for (int col = 1; col <= H-h+1; col++){
		vector<int>diff(n+1);
		int ile = haha;
		
		auto add = [&](int x){
			diff[x]++;
			if (diff[x] == all[x]) ile--;
		};
		auto rem = [&](int x){
			diff[x]--;
			if (diff[x] == all[x]-1) ile++;
		};
		for (int i = 1; i<=w; i++){
			for (int j = col; j<col+h; j++){
				add(a[j][i]);
				// debug(j, i);
			}
		}
		ans[col][1] = ile;
		for (int row = 2; row + w - 1 <= W; row++){
			// debug(row);
			for (int j = col; j<col+h; j++){
				rem(a[j][row-1]);
				// debug(a[j][row-1], j, row-1);
			}
			// cerr << "a\n";
			for (int j = col; j<col+h; j++){
				add(a[j][row+w-1]);
				// debug(a[j][row+w-1], j, row+w-1);
			}
			// debug(ile);
			ans[col][row] = ile;
		}
		// debug(diff);
		// break;
	}
	for (int i = 1; i<=H-h+1; i++){
		for (int j = 1; j<=W-w+1; j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
