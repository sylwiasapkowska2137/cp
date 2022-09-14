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

struct segmin{
	vector<int>tab;
	int size = 1;

	segmin(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, oo);
		for (int i = 0; i<n; i++) tab[i+size] = a[i];
		for (int i = size-1; i>=0; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = oo;
		while(r-l>1){
			if (!(l&1))ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

struct segmax{
	vector<int>tab;
	int size = 1;

	segmax(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, -oo);
		for (int i = 0; i<n; i++) tab[i+size] = a[i];
		for (int i = size-1; i>=0; i--) tab[i] = max(tab[2*i], tab[2*i+1]);
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = -oo;
		while(r-l>1){
			if (!(l&1))ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}

};

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}
	segmin mini(n, a);
	segmax maxi(n, a);
	for (int x = 0; x<n-1; x++){
		//[0, x]
		int curr = maxi.query(0, x);
		int L = x+1, R = n-2;
		int ans = -1;
		bool ok = 1;
		while (R>=L){
			int mid = (L+R)/2;
			int a = mini.query(x+1, mid);
			int b = maxi.query(mid+1, n-1);
			//debug(mid, a, b);
			if (a == curr && b == curr){
				ans = mid;
				break;
			}
			if (a >= curr && b >= curr){
				ans = mid;
				L = mid+1;
				continue;
			} 
			if (a <= curr && b <= curr){
				ans = mid;
				R = mid-1;
				continue;
			}
			//nie da sie
			ok = 0;
			break;
		}
		if (!ok) continue;
		//debug(x, ans);
		//[0,x], [x+1, ans], [ans+1, n-1];
		if (ans == -1) continue;
		int a = maxi.query(0, x);
		int b = mini.query(x+1, ans);
		int c = maxi.query(ans+1, n-1);
		if (a == b && b == c){
			cout << "YES\n";
			cout << x+1 << " " << ans-x << " " << (n-ans-1) << "\n";
			return;
		}
	}
	cout << "NO\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}