//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

struct bus{
	int a, b, s;
	bus(){}
	bus(int _a, int _b, int _s){
		a = _a, b = _b, s = _s;
	}
};

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
		while (x > 0){
			x /= 2;
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
	int n, m, k; cin >> n >> m >> k;
	vector<bus>tab;
	vector<int>scaler;
	for (int i = 0; i<k; i++){
		int a, b, s; cin >> a >> b >> s;
		tab.emplace_back(a, b, 	 s);
		scaler.emplace_back(b);
	}
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	sort(tab.begin(), tab.end(), [](auto a, auto b){
		if (a.a == b.a) return a.b < b.b;
		return a.a < b.a;
	});
	segtree seg((int)scaler.size()+1);
	for (auto [a, b, s]:tab){
		int it = (int)(lower_bound(scaler.begin(),scaler.end(), b)-scaler.begin());
		int x = seg.query(0, it);
		seg.update(it, x+s);
	}
	cout << seg.query(0, seg.size-1) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
