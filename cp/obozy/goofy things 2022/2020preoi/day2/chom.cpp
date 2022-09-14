//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

struct segtree{
	vector<int>tab;
	int size = 1;

	void init(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
	}
	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 6;
		while (r-l>1){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<int>a(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	segtree seg;
	seg.init(n+1, a);
	while (q--){
		int l, r; cin >> l >> r;
		--l;--r;
		cout << seg.query(l, r) << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
