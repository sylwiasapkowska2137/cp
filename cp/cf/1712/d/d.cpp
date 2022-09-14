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

struct TreeMin{
	typedef pair<int, int> T;
	vector<T>tab;
	int size = 1;

	T f(T a, T b) {return min(a, b);};

	TreeMin(int n, vector<int>&a){
		while (size < n) size *= 2;
		tab.assign(2*size, {oo, oo});
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = {a[i], i};
		for (int i = size-1; i>=1; i--) tab[i] = f(tab[2*i], tab[2*i+1]); 
	}

	T query(int l, int r){
		T ans = {oo, oo};
		for (l += size-1, r += size+1; r-l>1; r/=2, l/=2){
			if (!(l&1)) ans = f(ans, tab[l+1]);
			if (r&1) ans = f(ans, tab[r-1]);
		}
		return ans;
	}

	void update(int x, T v){
		x += size;
		tab[x] = v;
		while (x){
			x/=2;
			tab[x] = f(tab[2*x], tab[2*x+1]);
		}
	}
};

void solve(){
	int n, k; cin >> n >> k;
	vector<int>a(n+1);
	for (int i = 1; i<=n; i++){
		cin >> a[i];
	}
	const int oo2 = 1e9;

	auto check = [&](int X){
		TreeMin t(n+1, a);
		int ck = k;
		while (1){
			pair<int, int>c = t.query(1, n);
 			if (c.first * 2 < X){
				t.update(c.second, {oo2, 0});
				ck--;
				if (ck < 0) return 0;
			} else break;
		}
		// debug(X);
		for (int i = 2; i<=n; i++){
			int a = t.query(i-1, i-1).first;
			int b = t.query(i, i).first;
			int cnt = 2;
			if (a >= X) cnt--;
			if (b >= X) cnt--;
			// debug(a, b, ck, cnt);
			if (ck >= cnt){
				if (a < X) t.update(i-1, {oo2, 0});
				if (b < X) t.update(i, {oo2, 0});
				pair<int, int>c = t.query(1, n);
				if (min(2*c.first, t.query(i-1, i).first) >= X){
					return 1;
				}
			}
			t.update(i-1, {a, i-1});
			t.update(i, {b, i});
		}
		return 0;
	};	

	int l = 1, r = oo2, ans = 0;
	while (r>=l){
		int mid = (l+r)/2;
		if (check(mid)){
			ans = mid;
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}