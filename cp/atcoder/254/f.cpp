	//Sylwia Sapkowska
	#include <bits/stdc++.h>
	#pragma GCC optimize("O3")
	#pragma GCC target ("avx2")
	#pragma GCC optimize("Ofast")
	#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
	#pragma GCC optimize("unroll-loops")
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

	#define int long long
	const int oo = 1e18, K = 30;

	mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
	int p(int a, int b){
		return a+rng()%(b-a+1);
	}

	struct segtree{
		vector<int>tab;
		int size = 1;

		segtree(int n, vector<int>&a, bool ok){
			while (size < n) size*=2;
			tab.assign(2*size+1, 0);
			if (ok){
				for (int i = 1; i<n; i++) {
					tab[i+size] = a[i]-a[i-1];
				}
			} else {
				for (int i = 0; i<n; i++){
					tab[i+size] = a[i];
				}
			}
			

			for (int i = size-1; i>=1; i--) tab[i] = __gcd(tab[2*i], tab[2*i+1]);
		}


		int query(int l, int r){
			l = l+size-1;
			r = r+size+1;
			int ans = 0;
			while (r-l>1){
				if (!(l&1)) ans = __gcd(ans, tab[l+1]);
				if (r&1) ans = __gcd(ans, tab[r-1]);
				l/=2;r/=2;
			}
			return ans;
		}
	};

	void solve(){
		int n, q; cin >> n >> q;
		vector<int>a(n), b(n);
		for (int i = 0; i<n; i++) cin >> a[i];
		for (int i = 0; i<n; i++) cin >> b[i];
		segtree A(n, a, 1), B(n, b, 1), AA(n, a, 0), BB(n, b, 0);
		while (q--){
			int h1, h2, w1, w2; cin >> h1 >> h2 >> w1 >> w2;
			h1--;h2--;w1--;w2--;
			int x = (h1==h2?0:A.query(h1+1, h2));
			int y = (w1==w2?0:B.query(w1+1, w2));
			int ans = __gcd(x, y);
			for (int i = 0; i<111; i++){
				ans = __gcd(ans, (a[p(h1, h2)]+b[p(w1, w2)]));
			}
			cout << abs(ans) << "\n";
		}
	}

	int32_t main(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		int t = 1;
		while (t--) solve();
		
		return 0;
	}
