//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
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

const int oo = 1e9, K = 20;

void solve(){
	int n, q; cin >> n >> q;
	vector<vector<int>>tab(n+1, vector<int>(K, 0));
	for (int i = 1; i<=n; i++) cin >> tab[i][0];
	for (int j = 1; j<K; j++){
		for (int i = 1; i+(1<<(j-1))<=n; i++){
			tab[i][j] = max(tab[i][j-1], tab[i+(1<<(j-1))][j-1]);
		}
	}
	function<int(int, int)>query = [&](int l, int r){
		int len = r-l+1;
		int k = log2(len);
		return max(tab[l][k], tab[r-(1<<k)+1][k]);
	};
	
	int prev = 0;
	while (q--){
		int a, b; cin >> a >> b;
		int nowy = a+(prev%100);
		if (nowy <= n) a = nowy;
		int L = a, R = n, ans = -1;
		while (R>=L){
			int mid = (L+R)/2;
			if (query(a, mid) > b){
				ans = mid;
				R = mid-1;
			} else L = mid+1;
		}
		if (ans == -1) ans = 0;
		cout << ans << "\n";
		prev = ans;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
