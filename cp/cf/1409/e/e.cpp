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
const int oo = 1e18;

struct segtree{
	vector<int>tab;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}

	void update(int x, int v){
		x += size;
		tab[x] = max(tab[x], v);
		while (x){
			x/=2;
			tab[x] = max(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n, k; cin >> n >> k;
	vector<int>x(n), y(n), scaler;
	map<int, int>cnt;
	for (int i = 0; i<n; i++) {
		cin >> x[i];
		scaler.emplace_back(x[i]);
		cnt[x[i]]++;
	}
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	vector<int>pref((int)scaler.size()+1);
	map<int, int>mapa;
	for (int i = 0; i<(int)scaler.size(); i++) mapa[scaler[i]] = i+1;
	for (int i = 0; i<n; i++) cin >> y[i];
	int L = (int)scaler.size()-1;
	int R = L;
	int sum = cnt[scaler.back()];
	vector<int>ans((int)scaler.size());
	while (R >= 0){
		while (L-1 >= 0 && scaler[R]-scaler[L-1] <= k){
			L--;
			sum += cnt[scaler[L]];
		}
		if (scaler[R]-scaler[L] <= k){
			ans[R] = sum;
		}
		sum -= cnt[scaler[R]];
		R--;
	}
	int ptr = 0;
	int maxi = 0;
	int out = 1;
	for (int i = 0; i<(int)scaler.size(); i++){
		int v = lower_bound(scaler.begin(), scaler.end(), scaler[i]-k)-scaler.begin();
		while (ptr < v) {
			maxi = max(maxi, ans[ptr]);
			ptr++;
		}
		out = max(out, ans[i]+maxi);
	}
	cout << out << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
	
	return 0;
}