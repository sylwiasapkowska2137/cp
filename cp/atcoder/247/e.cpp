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

struct segmax{
	vector<int>tab;
	int size = 1;

	segmax(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		for (int i =0; i<n; i++) tab[i+size] = a[i];
		for (int i = size-1; i>=0; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
	}

	int query(int l, int r){
		int ans = 0;
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

struct segmin{
	vector<int>tab;
	int size = 1;

	segmin(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size+1, oo);
		for (int i =0; i<n; i++) tab[i+size] = a[i];
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
	int n, X, Y; cin >> n >> X >> Y;
	//max = X, min = Y;
	vector<int>a(n);
	for (int i = 0; i<n; i++){
		cin >> a[i];
	}
	segmin mini(n, a);
	segmax maxi(n, a);
	int ret = 0;
	for (int l = 0; l<n; l++){
		int L = l, R = n-1, ans = l;
		bool ok = 1;
		while (R >= L){
			int mid = (L+R)/2;
			int x = maxi.query(l, mid);
			int y = mini.query(l, mid);
			if (x == X && y == Y){
				ans = mid;
				L = mid+1;
				continue;
			}
			if (x >= X && y <= Y){
				//max za duze, minimum za male
				R = mid-1;
				continue;
			}
			if (x <= X && y >= Y){
				//minimum za duze, maximum za male
				L = mid+1;
				continue;
			}
			ok = 0;
			break;
		}
		if (!ok) continue;
		L = l, R = n-1;int ans2 = l;
		while (R >= L){
			int m = (L+R)/2;
			if (maxi.query(l, m) >= X){
				ans2 = m;
				R = m-1;
			} else L = m+1;
		}
		L = l, R = n-1;int ans3 = l;
		while (R >= L){
			int m = (L+R)/2;
			if (mini.query(l, m) <= Y){
				ans3 = m;
				R = m-1;
			} else L = m+1;
		}
		debug(l, ans, ans2, ans3);
		int x = maxi.query(l, ans);
		int y = mini.query(l, ans);
		if (x == X && y == Y){
			ret += (ans-max(ans2, ans3)+1);
		}
	}
	cout << ret << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
