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
typedef long double ld;
const ld eps = 1e-8;
const ld PI = 3.14159265359;

vector<pair<ld, ld>> gen(int n, int r){
	vector<pair<ld, ld>>ret;
	ret.emplace_back(r, 0);
	ld x = r, y = 0;
	ld alpha = 1.0 - ((ld)(n-2.0)/ n);
	alpha = alpha * PI;
	// debug(alpha);
	for (int i = 1; i<n; i++){
		ld x2 = x * cos(alpha) - y * sin(alpha);
		ld y2 = y * cos(alpha) + x * sin(alpha);
		ret.emplace_back(x2, y2);
		x = x2, y = y2;
	}
	return ret;
}

void rotate(vector<pair<ld, ld>>&curr, ld alpha){
	for (auto &[x, y]:curr){
		ld x2 = x * cos(alpha) - y * sin(alpha);
		ld y2 = y * cos(alpha) + x * sin(alpha);
		x = x2, y = y2;
	}
}

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int losuj(int a, int b){return a+rng()%(b-a+1);}

struct T{
	int type; ld x1, x2, y;
	T(){}
	T(int _type, ld _x1, ld _x2, ld _y): type(_type), x1(_x1), x2(_x2), y(_y) {}
};

//-1, to -1 na przedziale, 1 to +1 na przedziale, 0, to query

struct Tree{
	vector<int>tab, lazy;
	int size = 1;

	Tree(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		lazy.assign(2*size, 0);
	}

	void push(int x, int lx, int rx){
		if (lazy[x] == 0 || lx == rx) return;
		tab[2*x] += lazy[x];
		tab[2*x+1] += lazy[x];
		lazy[2*x] += lazy[x];
		lazy[2*x+1] += lazy[x];
		lazy[x] = 0;
	}

	void update(int x, int lx, int rx, int l, int r, int v){
		push(x, lx, rx);
		if (lx > r || rx < l) return;
		if (lx >= l && rx <= r) {
			tab[x] += v;
			lazy[x] += v;
			return;
		}
		int m = (lx+rx)/2;
		update(2*x, lx, m, l, r, v);
		update(2*x+1, m+1, rx, l, r, v);
		tab[x] = min(tab[2*x], tab[2*x+1]);
	}

	int query(int x, int lx, int rx, int l, int r){
		push(x, lx, rx);
		if (lx > r || rx < l) return oo;
		if (lx >= l && rx <= r) return tab[x];
		int m = (lx+rx)/2;
		return min(query(2*x, lx, m, l, r), query(2*x+1, m+1, rx, l, r));
	}
};

bool check(vector<pair<ld, ld>>&points, int&n, int&R, ld mid){
	vector<pair<ld, ld>>curr = gen(25, R);
	curr.emplace_back(-R, 0);
	curr.emplace_back(0, R);
	curr.emplace_back(0, -R);
	// debug(curr);
	for (int rep = 0; rep<5; rep++){
		vector<T>sweep;
		vector<ld>scaler;
		for (auto [x, y]: curr)	{
			sweep.emplace_back(0, y, y, x);
			scaler.emplace_back(y);
		}
		for (auto [x, y]: points){
			sweep.emplace_back(1, y-mid, y+mid, x-mid);
			sweep.emplace_back(-1, y-mid, y+mid, x+mid);
			scaler.emplace_back(y-mid);
			scaler.emplace_back(y+mid);
		}
		sort(scaler.begin(), scaler.end());
		vector<ld>ss = {scaler[0]};
		for (int i = 1; i<=n; i++){
			if (scaler[i] - scaler[i-1] > eps){
				ss.emplace_back(scaler[i]);
			}
		}
		sort(sweep.begin(), sweep.end(), [&](auto x, auto y){
			if (x.type == y.type) return x.y < y.y;
			ld A = x.y, B = y.y;
			if (x.type < y.type) B += eps;
			else A += eps;
			return A < B;
		});
		auto get = [&](ld x){
			x -= eps;
			return (int)(lower_bound(ss.begin(), ss.end(), x)-ss.begin());
		};
		Tree t(n+2);
		for (auto [type, x1, x2, y]: sweep){
			if (type == 0){
				if (t.query(1, 0, t.size-1, get(x1), get(x2))) {
					;
				} else {
					return 0;
				}
			} else {
				t.update(1, 0, t.size-1, get(x1), get(x2), type);
			}
		}

		ld angle = losuj(0, 359) * PI / 180.0;
		rotate(curr, angle);
	}
	return 1;
}

void solve(){
	cerr << fixed << setprecision(10);
	cout << fixed << setprecision(10);
	int n, R; cin >> n >> R;
	vector<pair<ld, ld>>points(n);
	for (auto &[x, y]: points) cin >> x >> y;
	ld l = 0, r = oo2;
	ld eps2 = 1e-5;
	while (r-l > eps2){
		ld mid = (l+r)/2.0;
		if (check(points, n, R, mid)) r = mid;
		else l = mid;
	}
	cout << 2.0*l << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
