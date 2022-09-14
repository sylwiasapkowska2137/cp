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
	int x, y, i;
	T(){}
	T(int _l, int _r, int _i){
		x = _l, y = _r, i = _i;
	}
};

struct TreeSum{
	vector<int>tab;
	int size = 1;

	TreeSum(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
	}

	int f(int a, int b){return a+b;};

	void update(int x, int v){
		x += size;
		tab[x] = f(tab[x], v);
		while (x){
			x/=2;
			tab[x] = f(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		int ans = 0;
		for (l += size-1, r += size+1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans = f(ans, tab[l+1]);
			if (r&1) ans = f(ans, tab[r-1]); 
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;	
	vector<T>a;
	vector<int>s;
	for (int i = 0; i<n; i++){
		int l, r; cin >> l >> r;
		a.emplace_back(l, r, i);
		s.emplace_back(l);
	}
	sort(a.begin(), a.end(), [](auto x, auto y){
		if (x.y == y.y) return x.x < y.x;
		return x.y > y.y;
	});
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	auto get = [&](int x){return (int)(lower_bound(s.begin(), s.end(), x)-s.begin());};
	vector<int>A(n), B(n);
	TreeSum t(s.size()+3);
	for (auto [x, y, i]: a){
		int X = get(x);
		B[i] = t.query(0, X);
		t.update(X, 1);
	}
	reverse(a.begin(), a.end());
	t.tab.assign(2*t.size, 0);
	for (auto [x, y, i]:a){
		int X = get(x);
		A[i] = t.query(X, t.size-1);
		t.update(X, 1);
	}
	for (int i = 0; i<n; i++) cout << A[i] << " ";
	cout << "\n";
	for (int i = 0; i<n; i++) cout << B[i] << " ";
	
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
