//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long double LD;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
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
	vector<int>tab;
	int size = 1;

	segtree(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, oo);
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=0; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
	}

	int query(int l, int r){
		int ans = oo;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n, s; cin >> n >> s;
	vector<int>a(n+1), pref(n+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i];
		pref[i] = pref[i-1]+a[i];
	}
	// debug(pref);
	segtree seg(n+2, pref);
	int len = 0, LL, RR;
	for (int l = 1; l<=n; l++){
		int L = l, R = n, ans = -1;
		while (R >= L){
			int mid = (L+R)/2;
			if (s + seg.query(l, mid)-pref[l-1] >= 0){
				ans = mid;
				L = mid+1;
			} else R = mid-1;
		}
		if (ans != -1){
			if (len < ans-l+1){
				len = ans-l+1;
				LL = l;
				RR = ans;
			}
		}
	}
	if (len == 0){
		cout << "-1\n";
	} else {
		cout << LL << " " << RR << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}