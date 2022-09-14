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

struct segsum{
	vector<int>tab;
	int size = 1;

	segsum(int n){
		while (size < n) size*=2;
		tab.resize(2*size);
		// for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
		// for (int i = size-1; i>=1; i--) tab[i] = tab[2*i] + tab[2*i+1];
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}

	void update(int x){
		x += size;
		tab[x] = 1;
		while (x){
			x/=2;
			tab[x] = tab[2*x] + tab[2*x+1];
		}
	}
};

struct segmax{
	vector<int>tab;
	int size = 1;

	segmax(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.resize(2*size, -oo);
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = -oo;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}

	int find(int x, int lx, int rx, int v){
		if (lx == rx) return lx;
		int m = (lx+rx)/2;
		if (tab[2*x+1] >= v) return find(2*x+1, m+1, rx, v);
		return find(2*x, lx, m, v);
	}

	void erase(int x, int lx, int rx){
		if (lx == rx){
			tab[x] = -oo;
			return;
		}
		int m = (lx+rx)/2;
		if (tab[2*x] >= tab[2*x+1]) erase(2*x, lx, m);
		else erase(2*x+1, m+1, rx);
		tab[x] = max(tab[2*x], tab[2*x+1]);
	}

	void update(int x, int val){
		x += size;
		tab[x] = val;
		while (x){
			x/=2;
			tab[x] = max(tab[2*x], tab[2*x+1]);
		}
	}
};

void solve(){
	int n, q; cin >> n >> q;
	vector<pair<int, int>>ab(n);
	for (int i = 0; i<n; i++){
		cin >> ab[i].first >> ab[i].second;
	}
	sort(ab.begin(), ab.end(), [](auto x, auto y){return max(x.first, x.second) < max(y.first, y.second);});
	vector<int>x(q);
	for (int i = 0; i<q; i++) cin >> x[i];
	vector<pair<int, int>>s;
	for (int i = 0; i<q; i++) s.emplace_back(x[i], i);
	sort(s.begin(), s.end());
	int ptr = q-1;
	segmax smax(q+1, x);
	segsum seg(q+1);
	int ans = 0;
	for (int i = n-1; i>=0; i--){
		int flip = 0;
		auto [a, b] = ab[i]; 
		if (a < b) {
			swap(a, b);
			flip = 1;
		}
		while (smax.tab[1] >= a) smax.erase(1, 0, seg.size-1);
		while (ptr >= 0 && s[ptr].first >= a){
			seg.update(s[ptr].second);
			ptr--;
		}
		int curr = flip;
		int idx = 0;
		if (smax.tab[1] >= b){
			//find 1
			idx = smax.find(1, 0, seg.size-1, b);
			curr = 0;
		}
		curr = (curr + seg.query(idx, q))%2;
		if (!curr){
			ans += a;
			// debug(a);
		} else {
			ans += b;
			// debug(b);
		}
	}
	cout << ans << "\n";

}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
