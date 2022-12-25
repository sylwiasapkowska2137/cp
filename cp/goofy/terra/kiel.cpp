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

struct T{
	int m = 0, c = 0, k = 0;
	T(){}
	T(int _m, int _c, int _k):m(_m), c(_c), k(_k){}
	T operator+=(T he){
		m += he.m;
		c += he.c;
		k += he.k;
		return *this;
	}
};

void gen(vector<T>&a, int L, int R, vector<T>&b){
	vector<T>curr;
	for (int i = L; i<=R; i++) curr.emplace_back(a[i]);
	int n = (int)curr.size();
	for (int mask = 0; mask<(1<<n); mask++){
		T x;
		for (int i = 0; i<n; i++){
			if (mask&(1<<i)){
				x += curr[i];
			}
		}
		b.emplace_back(x.m, x.m-x.c, x.c-x.k);
	}
	if (R == (int)a.size()-1){
		for (auto &[m, c, k]:b){
			c = -c, k = -k;
		}
	}
	sort(b.begin(), b.end(), [&](auto x, auto y){
		if (x.c == y.c) return x.k < y.k;
		return x.c < y.c;
	});
}

struct TreeMax{
	vector<int>tab;
	int size = 1;

	TreeMax(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, -oo);
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
		int ans = -oo;
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	vector<T>a;
	for (int i = 0; i<n; i++){
		int m, c, k; cin >> m >> c >> k;
		a.emplace_back(m, c, k);
	}
	int mid = n/2;
	vector<T>L, R;
	gen(a, 0, mid, L);
	gen(a, mid+1, n-1, R);
	int ans = 0;
	int ptr = -1;
	vector<int>s;
	for (auto &[m, k, c]:L) s.emplace_back(c);	
	for (auto &[m, k, c]:R) s.emplace_back(c);	
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	TreeMax t(s.size()+5);
	auto get = [&](int x){ return (int)(lower_bound(s.begin(), s.end(), x)-s.begin());};
	for (int i = 0; i<(int)L.size(); i++){
		while (ptr + 1 < (int)R.size() && R[ptr+1].c <= L[i].c){
			ptr++;
			t.update(get(R[ptr].k), R[ptr].m);
		}
		ans = max(ans, L[i].m + t.query(0, get(L[i].k)));
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
