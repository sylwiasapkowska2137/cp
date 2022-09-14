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

const int oo = 1e9, K = 30;

struct segment{
	int x, y1, y2, add;
	segment(int _x = 0, int _y1 = 0, int _y2 = 0, int _add = 0){
		x = _x, y1 = _y1, y2 = _y2, add = _add;
	}
};

struct rect{
	int x1, x2, y1, y2;
	void read(){
		cin >> x1 >> y1 >> x2 >> y2;
	}
};

const int sz = (1<<18);
int tab[2*sz+1];
	
void update(int l, int r, int v){
	l = l+sz-1;
	r = r+sz+1;
	while (r-l>1){
		if (!(l&1)) tab[l+1] += v;
		if (r&1) tab[r-1] += v;
		l/=2;r/=2;
	}
}

int query(int x){
	x += sz;
	int ans = 0;
	while (x){
		ans += tab[x];
		x/=2;
	}
	return ans;
}

void solve(){
	int n, m, q; cin >> n >> m >> q;
	vector<segment>sweep;
	vector<rect>rec(n);
	for (int i = 0; i<n; i++){
		rec[i].read();
		sweep.emplace_back(rec[i].x1, rec[i].y1, rec[i].y2, 1);
		sweep.emplace_back(rec[i].x2, rec[i].y1, rec[i].y2, -1);
	}
	int X[] = {1, 1, 0, -1, -1, -1, 0, 1};
	int Y[] = {0, 1, 1, 1, 0, -1, -1, -1};
	for (int i = 0; i<m; i++){
		int v, x, d; cin >> v >> x >> d;
		x--;
		for (int j = 0; j<d; j++){
			rec[x].x1 += X[v];
			rec[x].x2 += X[v];
			rec[x].y1 += Y[v];
			rec[x].y2 += Y[v];
			sweep.emplace_back(rec[x].x1, rec[x].y1, rec[x].y2, 1);
			sweep.emplace_back(rec[x].x2, rec[x].y1, rec[x].y2, -1);
		}
	}
	for (int i = 0; i<q; i++){
		int x, y; cin >> x >> y;
		sweep.emplace_back(x, y, i, 0);
	}
	sort(sweep.begin(), sweep.end(), [&](auto a, auto b){
		if (a.x == b.x) return a.add > b.add;
		return a.x < b.x;
	});
	vector<int>ans(q);
	for (auto [x, y1, y2, add]:sweep){
		if (add == 0) ans[y2] = query(y1);
		else update(y1, y2, add);
	}
	for (int i = 0; i<q; i++) cout << ans[i] << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
