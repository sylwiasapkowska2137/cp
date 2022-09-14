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
const int oo = 1e18, K = 30;

struct segment{
	int a, b, c, d;
	void read(){
		cin >> a >> b >> d >> c;
	}
};

struct segtree{
	vector<int>tab;
	int size = 1;

	segtree(int n){
		while (size < n) size*=2;
		tab.assign(2*size, oo);
	}

	void clear(){
		tab.assign(2*size, oo);
	}

	void update(int x, int v){
		x += size;
		tab[x] = min(tab[x], v);
		while (x){
			x/=2;
			tab[x] = min(tab[2*x], tab[2*x+1]);
		}
	}

	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = oo;
		while (r-l>1){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n, m; cin >> n >> m;
	vector<segment>a(m);
	vector<int>scaler;
	for (int i = 0; i<m; i++) {
		a[i].read();
		scaler.emplace_back(a[i].a);
		scaler.emplace_back(a[i].b);
		scaler.emplace_back(a[i].d);
	}
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	vector<int>dpL(m, oo), dpR(m, oo);
	auto get = [&](int x){return (int)(lower_bound(scaler.begin(), scaler.end(), x)-scaler.begin());};
	segtree seg((int)scaler.size()+1);
	for (int i = 0; i<m; i++){
		dpL[i] = min(a[i].a == 1 ? a[i].c : oo, seg.query(get(a[i].a), get(a[i].b))+a[i].c);
		seg.update(get(a[i].d), dpL[i]);
	}
	// debug(dpL);
	seg.clear();
	for (int i = 0; i<m; i++){
		dpR[i] = min(a[i].b == n ? a[i].c : oo, seg.query(get(a[i].a), get(a[i].b))+a[i].c);
		seg.update(get(a[i].d), dpR[i]);
	}
	// debug(dpR);
	int ans = oo;
	for (int i = 0; i<m; i++) ans = min(ans, dpL[i]+dpR[i]-a[i].c);
	if (ans == oo) cout << "-1\n";
	else cout << ans << "\n";
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
