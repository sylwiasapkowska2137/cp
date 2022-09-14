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
const int mx = 11;
const int blocksize = 3;

struct Block{
	int numer;
	int cnt[mx][mx];
	int curr[mx];
	int values[blocksize][mx];

	void add(int pos, int x){
		int c = 0;
		pos %= blocksize;
		while (x){
			values[pos][c] = (x%10);
			cnt[c][(x%10)]++;
			x/=10;
			c++;
		}
	}

	void d(){
		cerr << numer << "\n";
		for (int i = 0; i<blocksize; i++){
			for (int j = 0; j<3; j++){
				debug(i, j, values[i][j]);
			}
		}
	}

	int f(int x){
		if (x == curr[x]) return x;
		return f(curr[x]);
	}

	void change(int l, int r, int x, int y){
		l %= blocksize; r%=blocksize;
		for (int i = l; i<=r; i++){
			for (int j = 0; j<mx; j++){
				if (values[i][j] == -1) continue;
				if (f(values[i][j]) == x){
					values[i][j] = y;
					cnt[j][x]--;
					cnt[j][y]++;
				}
			}
		}
	}

	void change_all(int x, int y){
		curr[x] = y;
	}

	int sum(int l, int r){
		l %= blocksize; r%=blocksize;
		int ans = 0;
		for (int i = l; i<=r; i++){
			int p = 1;
			for (int num = 0; num < mx; num++){
				// debug(values[i][num], p);
				if (values[i][num] == -1) continue;
				ans += f(values[i][num])*p;
				p *= 10;
			}
		}
		// debug(ans);
		return ans;
	}

	int sum_all(){
		int ans = 0;
		int p = 1;
		for (int pos = 0; pos < mx; pos++){
			for (int i = 0; i<mx; i++){
				ans += cnt[pos][i] * p * f(i);
			}
			p *= 10;
		}
		return ans;
	}
};


void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n);
	vector<Block>tab(n/blocksize+4);
	for (int i = 0; i<(int)tab.size(); i++) {
		tab[i].numer = i;
		for (int j = 0; j<mx; j++) tab[i].curr[j] = j;
		memset(tab[i].values, -1, sizeof(tab[i].values));
	}
	for (int i = 0; i<n; i++){
		cin >> a[i];
		tab[i/blocksize].add(i, a[i]);
	}
	while (q--){
		int t; cin >> t;
		// debug(t);
		if (t == 1){
			int l, r, x, y;
			cin >> l >> r >> x >> y;
			l--;r--;
			if (l/blocksize == r/blocksize){
				tab[l/blocksize].change(l, r, x, y);
				continue;
			}
			int left = tab.size()-1, right = tab.size()-1;
			if (l % blocksize != 0){
				int R = (l + blocksize - (l%blocksize)) - 1;
				tab[l/blocksize].change(l, R, x, y);
				left = l/blocksize+1;
			}
			if (r % blocksize != blocksize - 1){
				int L = r - r%blocksize;
				tab[L/blocksize].change(L, r, x, y);
				right = L/blocksize-1;
			}
			debug(left, right);
			for (int i = left; i<=right; i++){
				tab[i].change_all(x, y);
			}
		} else {
			int l, r; cin >> l >> r;
			l--;r--;
			int ans = 0;
			if (l/blocksize == r/blocksize){
				ans = tab[l/blocksize].sum(l, r);
				cout << ans << "\n";
				continue;
			}
			int left = tab.size()-1, right = tab.size()-1;
			if (l % blocksize != 0){
				int R = (l + blocksize - (l%blocksize)) - 1;
				ans += tab[l/blocksize].sum(l, R);
				left = l/blocksize+1;
			}
			if (r % blocksize != blocksize - 1){
				int L = r - r%blocksize;
				ans += tab[L/blocksize].sum(L, r);
				right = L/blocksize-1;
			}
			debug(left, right);
			for (int i = left; i<=right; i++){
				ans += tab[i].sum_all();
			}
			cout << ans << "\n";
			// break;
		}
		// tab[0].d();
		// tab[1].d();
		// break;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
