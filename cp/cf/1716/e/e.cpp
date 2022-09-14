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

struct ms{
	int pref, suf, sum, max;
	void d(){
		cerr << pref << " " << suf << " " << sum << " " << max << "\n";
	}
};

ms fix(int x){
	ms ret;
	ret.pref = max(x, 0LL);
	ret.suf = max(x, 0LL);
	ret.max = max(x, 0LL);
	ret.sum = x;
	return ret;	
}

struct node{
	int len;
	vector<ms>a;

	node(int _l) {
		len = _l;
		a.resize(_l);
	}
};

ms merge(ms a, ms b){
	ms ret;
	ret.sum = a.sum + b.sum;
	ret.pref = max(a.pref, a.sum+b.pref);
	ret.suf = max(b.suf, b.sum+a.suf);
	ret.max = max({a.max, b.max, a.suf+b.pref});
	return ret;
}

node rec(int l, int r, int k, vector<int>&a){
	int len = r-l;
	if (len == 1){
		ms A = fix(a[l]);
		ms B = fix(a[r]);
		node ret(2);
		ret.a[0] = merge(A, B);
		ret.a[1] = merge(B, A);
		// debug(l, r);
		// for (int i = 0; i<ret.len; i++){
		// 	ret.a[i].d();
		// }
		return ret;
	}
	node ret(len+1);
	for (int i = l; i<=r; i++) ret.a[i-l] = fix(a[l]);
	int mid = (l+r)/2;
	node A = rec(l, mid, k-1, a);
	node B = rec(mid+1, r, k-1, a);
	int x = (1<<(k-1));
	for (int i = 0; i<=len; i++){
		if (i < x){
			ret.a[i] = merge(A.a[i], B.a[i]);
		} else {
			ret.a[i] = merge(B.a[i-x], A.a[i-x]);
		}
	}
	// debug(l, r);
	// for (int i = 0; i<ret.len; i++){
	// 	ret.a[i].d();
	// }
	return ret;
}

void solve(){
	int n; cin >> n;
	int N = (1<<n);
	vector<int>a(N);
	for (int i = 0; i<N; i++) cin >> a[i];
	node curr = rec(0, N-1, n, a);
	// for (int i = 0; i<curr.len; i++){
	// 	curr.a[i].d();
	// }
	int f = 0;
	int q; cin >> q;
	while (q--){
		int k; cin >> k;
		f ^= (1<<k);
		cout << curr.a[f].max << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}