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
	int t, a, b;
	T(){}
	T(int _t, int _a, int _b) {t = _t, a = _a, b = _b;}
};

struct TreeMin{
	vector<int>tab;
	int size = 1;

	TreeMin(int n, vector<int>&a){
		while (size < n) size*=2;
		tab.assign(2*size, oo);
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>=1; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
	}

	void update(int x, int v){
		x += size;
		tab[x] += v;
		while (x){
			x/=2;
			tab[x] = min(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		int ans = oo;
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
		}
		return ans;
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vector<int>c(n+1);
	for (int i = 1; i<=n; i++) cin >> c[i];
	vector<int>cars;
	vector<T>parts;
	for (int i = 0; i<m; i++){
		int t, type; cin >> t >> type;
		if (type == 1){
			int a, b; cin >> a >> b;
			parts.emplace_back(t, a, b);
		} else cars.emplace_back(t);
	}
	
	TreeMin t(n+2, c);
	int p = 0, ptr = 0;
	for (int i = 0; i<(int)cars.size(); i++){
		p = max(p+1, cars[i]);
		while (ptr < (int)parts.size() && t.query(1, n) < i+1){
			auto [tt, a, b] = parts[ptr]; 
			t.update(a, b);
			p = max(p, tt-a+1);
			ptr++;
		}
	}
	cout << p+n-1 << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
