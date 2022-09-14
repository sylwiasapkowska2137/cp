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

struct segtree{
	vector<vector<pair<int,int>>>tab;
	vector<vector<int>>pref;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.resize(2*size+1);
		pref.assign(2*size+1, {0});
	}


	void update(int x, int lx, int rx, int l, int r, int val, int czas){
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r){
			tab[x].emplace_back(val, czas);
			pref[x].emplace_back(pref[x].back()+val);
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, val, czas);
		update(2*x+1, m+1, rx, l, r, val, czas);
	}

	int sum(int x, int czas){
		x+=size;
		int ret = 0;
		while (x){
			int l = 0, r = (int)tab[x].size()-1, ans = -1;
			while (r>=l){
				int m = (l+r)/2;
				if (tab[x][m].second >= czas){
					ans = m;
					r = m-1;
				} else l = m+1;
			}

			if (ans != -1){
				ret += pref[x].back()-pref[x][ans];
			}
			x/=2;
		}
		return ret;
	}
};



void solve(){
	int n, m, q; cin >> n >> m >> q;
	vector<pair<int, int>>row(n+1, {0, -1});
	int czas = 0;
	segtree seg(m+1);
	while (q--){
		int t; cin >> t;
		if (t == 1){
			int l, r, x; cin >> l >> r >> x;
			seg.update(1, 0, seg.size-1, l, r, x, czas);
		} 
		if (t == 2){
			int i, x; cin >> i >> x;
			row[i] = {x, czas};
		}
		if (t == 3){
			int i, j; cin >> i >> j;
			cout << row[i].first+seg.sum(j, row[i].second+1) << "\n";
		}
		czas++;
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
