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

struct TreeMax{
	vector<pair<int, int>>tab;
	int size = 1;

	TreeMax(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, {-oo, -oo});
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = {a[i], i};
		for (int i = size-1; i>=1; i--) tab[i] = max(tab[2*i],tab[2*i+1]);
	}

	pair<int, int> query(int l, int r){
		pair<int, int> ans = {-oo, -oo};
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
		}
		return ans;
	}
};

struct TreeSum{
	vector<int>tab;
	int size = 1;

	TreeSum(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		for (int i = 1; i<(int)a.size(); i++){
			tab[i+size] = a[i];
		}
		// for (int i = size-1; i>=1; i--){
			// tab[i] = tab[2*i] + tab[2*i+1];
		// }
	}

	void update(int l, int r, int x){
		for (l += size-1, r += size-1; r-l>1; l/=2, r/=2){
			if (!(l&1)) tab[l+1] += x;
			if (r&1) tab[r-1] += x;
		}
	}

	int query(int x){
		x += size;
		int ans = tab[x];
		while (x){
			x/=2;
			ans += tab[x];
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vector<int>a(n+2), b(n+2, oo);
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int i = 1; i<=n; i++) cin >> b[i];	
	TreeMax t(n+3, b);
	TreeSum t2(n+3, a);
	pair<int, int>mx = t.query(1, n);
	int ans = mx.first * a[mx.second];
	t2.update(mx.second, mx.second, -mx.first);
	
	function<void(int, int, int)>rec = [&](int l, int what, int r){
		if (l > r) return;
		pair<int, int>now = t.query(l, what-1);
		int pos = now.second;
		int val = t2.query(pos);
		debug(l, r, now, pos, val);
		if (val > 0) {
			int cost = min({b[l-1], b[r+1], now.first});
			debug(cost);
			ans += val * cost;
			int L = r, R = n;
			int tmp = r;
			while (R >= L){
				int mid = (L+R)/2;
				if (t.query(l, mid).first == cost){
					tmp = mid;
					L = mid+1;
				} else R = mid-1;
			}
			L = 1, R = l;
			int tmp1 = l;
			while (R >= L){
				int mid = (L+R)/2;
				if (t.query(mid, r).first == cost){
					tmp1 = mid;
					R = mid-1;
				} else {
					L = mid+1;
				}
			}
			debug(tmp1, tmp);
			t2.update(tmp1, tmp, -val);
		}
		// rec(l, pos-1);
		// rec(pos+1, r);
	};
	rec(1, mx.second, n);
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
