//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

// #define int long long
const int oo = 1e9+7, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

struct TreeMax{
	typedef pair<int, int> T;
	vector<T>tab;
	int size = 1;

	TreeMax(int n){
		while (size < n) size*=2;
		tab.assign(2*size, {-oo, -oo});
	}

	void update(int x, T v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = max(tab[2*x], tab[2*x+1]);
		}
	}

	T query(int l, int r){
		T ans = {-oo, -oo};
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

	TreeSum(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
	}

	int query(int l, int r){
		int ans = 0;
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
		}
		return ans;
	}

	void update(int x, int v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = tab[2*x] + tab[2*x+1];
		}
	}
};

void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++) cin >> a[i];
	TreeMax t1(n+1);
	TreeSum t2(n+1);
	for (int i = 1; i<=n; i++) {
		t1.update(i, {a[i], i});
		t2.update(i, 1);
	}
	
	int turn = 0;
	vector<int>ret(n+1);
	while (1){
		pair<int, int>x = t1.query(1, n);
		// debug(x);
		if (x.first == -oo) break;
		int pos = x.second;
		t1.update(x.second, {-oo, -oo});
		t2.update(x.second, 0);
		ret[x.second] = turn;
	
		{
			int L = 1, R = pos-1, ans = oo;
			while (R >= L){
				int mid = (L+R)/2;
				if (t2.query(mid, pos-1) > k){
					L = mid+1;
				} else {
					ans = mid;
					R = mid-1;
				}
			}
			// debug(ans);
			if (ans != oo){
				// debug(ans);
				while (1){
					pair<int, int>curr = t1.query(ans, pos-1);
					if (curr.first == -oo) break;
					ret[curr.second] = turn;
					t1.update(curr.second, {-oo, -oo});
					t2.update(curr.second, 0);
				}
			}
		}


		{
		
			int L = pos+1, R = n, ans = oo;
			// debug(pos, L, R);	
			while (R >= L){
				int mid = (L+R)/2;
				// debug(mid, t2.query(pos+1, mid));
				if (t2.query(pos+1, mid) > k){
					R = mid-1;
				} else {
					ans = mid;
					L = mid+1;
				}
			}
			if (ans != oo){
				// debug(ans);
				while (1){
					pair<int, int>curr = t1.query(pos+1, ans);
					if (curr.first == -oo) break;
					ret[curr.second] = turn;
					t1.update(curr.second, {-oo, -oo});
					t2.update(curr.second, 0);
				}
			}
		}
		turn ^= 1;
		// break;
	}
	for (int i = 1; i<=n; i++) cout << ret[i] << " ";
	cout << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
