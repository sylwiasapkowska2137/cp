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

struct SEG{
	vector<int>tab;
	int size = 1;

	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size, -oo);
	}

	void update(int x, int v){
		x += size;
		tab[x] = max(tab[x], v);
		while (x){
			x/=2;
			tab[x] = max(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		int ans = -oo;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vector<int>a(n+1), w(n+1), scaler;
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		scaler.emplace_back(a[i]);
	}	
	for (int i = 1; i<=n; i++) cin >> w[i];
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	for (int i = 1; i<=n; i++) a[i] = (int)(lower_bound(scaler.begin(), scaler.end(), a[i])-scaler.begin())+1;
	int dp[n+1][21][2][2];
	for (int i = 0; i<=n; i++){
		for (int j = 0; j<=20; j++){
			for (int k = 0; k<2; k++){
				for (int l = 0; l<2; l++){
					dp[i][j][k][l] = -oo;
				}
			}
		}
	}
	int ans = -oo;
	SEG seg[21][2][2];
	for (int k = 1; k<=20; k++){
		for (int i = 0; i<2; i++){
			for (int j = 0; j<2; j++){
				seg[k][i][j].init(n+1);
			}
		}
	}
	
	for (int i = 1; i<=n; i++){
		dp[i][a[i]][1][0] = w[i];
		dp[i][a[i]][1][1] = w[i];
		seg[a[i]][1][0].update(a[i], w[i]);
		seg[a[i]][1][1].update(a[i], w[i]);
		for (int k = 0; k<2; k++){
			for (int l = 0; l<2; l++){
				for (int fi = 1; fi <= 20; fi++){
					if (l) {
						int x = seg[fi][k^1][l^1].query(0, a[i]-1);
						if (x > -oo){
							dp[i][fi][k][l] = max(dp[i][fi][k][l], x+w[i]);
							seg[fi][k][l].update(a[i], dp[i][fi][k][l]);
						}
						
					} else {
						int x = seg[fi][k^1][l^1].query(a[i]+1, n);
						if (x > -oo) {
							dp[i][fi][k][l] = max(dp[i][fi][k][l], x+w[i]);
							seg[fi][k][l].update(a[i], dp[i][fi][k][l]);
						}
					}
					// for (int j = 1; j<i; j++){
					// 	//dp[i][k][l]
					// 	if (l && a[j] < a[i]) {
					// 		dp[i][fi][k][l] = max(dp[i][fi][k][l], dp[j][fi][k^1][l^1]+w[i]); 
					// 	}
					// 	if (!l && a[j] > a[i]) dp[i][fi][k][l] = max(dp[i][fi][k][l], dp[j][fi][k^1][l^1]+w[i]);
					// }
				}
			}
		}
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=20; j++){
			for (int l = 0; l<2; l++){
				if (l && a[i] > j) ans = max(ans, dp[i][j][0][l]);
				if (!l && a[i] < j) ans = max(ans, dp[i][j][0][l]);
			}
		}
	}
	if (ans == -oo) cout << "NO\n";
	else cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
