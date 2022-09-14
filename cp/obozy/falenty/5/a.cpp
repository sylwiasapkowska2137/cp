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

// #define int long long
// const int oo = 1e18, oo2 = 1e9+7, K = 30;
// const int mod = 998244353;

struct T{
	int x, y, t;
	T(int _x = 0, int _y = 0, int _t = 0){
		x = _x, y = _y, t = _t;
	}
};

struct TreeSum{
	vector<int>tab;
	int size = 1;

	TreeSum(int n){
		while (size < n) size*=2;
		tab.resize(2*size);
	}

	void update(int x){
		x += size;
		tab[x]++;
		while (x){
			x/=2;
			tab[x] = tab[2*x] + tab[2*x+1];
		}
	}

	int query(int l, int r){
		int ans = 0;
		for (l += size-1, r += size+1; r-l>1; r/=2, l/=2){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
		}
		return ans;
	}
};
vector<int>s;
int get(int x){return (int)(lower_bound(s.begin(), s.end(), x)-s.begin());};

void solve(){
	int n, q; cin >> n >> q;
	vector<T>tab;
	
	for (int i = 0; i<n; i++){
		int a, b; cin >> a >> b;
		int x = a+b, y = b-a;
		tab.emplace_back(x, y, 0);
		s.emplace_back(x);
	}
	for (int i = 0; i<q; i++){
		int a, b; cin >> a >> b;
		int x = a+b, y = b-a;
		tab.emplace_back(x, y, i+1);
		s.emplace_back(x);
	}
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	vector<int>ans(q+1);
	sort(tab.begin(), tab.end(), [](auto a, auto b){
		if (a.y == b.y) {
			if (a.x == b.x) return a.t < b.t;
			return a.x < b.x;
		}
		return a.y > b.y;
	});
	TreeSum t((int)s.size()+3);
	for (auto [x, y, type]:tab){
		// debug(x, y, type);
		if (!type) t.update(get(x)); 
		else ans[type] = t.query(0, get(x));
	}
	for (int i = 1; i<=q; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
