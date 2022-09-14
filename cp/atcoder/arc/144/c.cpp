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

struct segtree{
	vector<int>tab;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 1);
		for (int i = size-1; i>=1; i--){
			tab[i] = tab[2*i] + tab[2*i+1];
		}
	}

	void update(int x){
		x += size;
		tab[x] = 0;
		while (x){
			x/=2;
			tab[x] = tab[2*x] + tab[2*x+1];
		}
	}

	int query(int l, int r){
		int ans = 0;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n, k; cin >> n >> k;
	segtree seg(n+1);
	if (n < 2*k) {
		cout << "-1\n";
		return;
	}
	vector<int>a;
	for (int i = 1; i<=n; i++){
		int val = -1;
		if (i + k <= n && seg.query(i+k, i+k) == 1 && i+k > n-k){
			a.emplace_back(i+k);
			continue;
		}
		// debug(i);
		if (i - k >= 1){
			int l = 1, r = i-k;
			// debug(l, r);
			int ans = -1;
			while (r>=l){
				int mid = (l+r)/2;
				if (seg.query(1, mid) > 0){
					ans = mid;
					r = mid-1;
				} else {
					l = mid+1;
				}
			}
			if (ans != -1){
				val = ans;
				seg.update(val);
			}
		}
		// debug(val);
		if (val == -1 && i+k <= n){
			int l = i+k, r = n;
			// debug(l, r);
			int ans = -1;
			while (r>=l){
				int mid = (l+r)/2;
				if (seg.query(i+k, mid) > 0){
					ans = mid;
					r = mid-1;
				} else {
					l = mid+1;
				}
			}
			if (ans != -1){
				val = ans;
				seg.update(val);
			} 
		} 
		// debug(val);
		a.emplace_back(val);
	}
	// debug(a);
	vector<int>b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	if (b.size() == n){
		for (auto x: a)cout << x << " ";
		cout << "\n";
	} else {
		cout << "-1\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
