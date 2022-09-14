//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

typedef long double LD;

struct Point{
	int x, y;

	Point(){}
	Point(int _x, int _y) {x = _x, y = _y;}

	Point& operator-=(const Point &he){
		x -= he.x;
		y -= he.y;
		return *this;
	}

	Point operator-(const Point &he){
		return Point{x-he.x, y-he.y};
	}

	int cross(const Point &he){
		return he.y*x-he.x*y;
	}

	int cross(Point &a, Point &b){
		return (a-*this).cross(b-*this);
	}
};


int dist(Point A, Point B){
	A -= B;
	return A.x*A.x+A.y*A.y;
}
 
int sgn(int x){
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}

int orientation(Point A, Point B, Point C){
	A-=C; B-=C;
	int c = B.y*A.x-B.x*A.y;
	return sgn(c);
}
 
bool cw(Point A, Point B, Point C, bool include_collinear){
	int o = orientation(A, B, C);
	return (o < 0 || (include_collinear && !o));
}
 
bool collinear(Point A, Point B, Point C){
	return orientation(A, B, C) == 0;
}


vector<Point> otoczka(vector<Point>a, bool include_collinear = 0){
	Point p0 = *min_element(a.begin(), a.end(), [](auto x, auto y){return tie(x.y, x.x) < tie(y.y, y.x);});
	sort(a.begin(), a.end(), [&](const Point &A, const Point &B){
		int o = orientation(p0, A, B);
		if (!o) return dist(p0, A) < dist(p0, B);
		return (o < 0);
	});
	if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }
	vector<Point>p;
	for (int i = 0; i<(int)a.size(); i++){
		while (p.size() > 1 && !cw(p[p.size()-2], p.back(), a[i], include_collinear)) p.pop_back();
		p.emplace_back(a[i]);
	}
	return p;
}

LD d(Point a, Point b){
	a -= b;
	return sqrt(a.x*a.x+a.y*a.y);
}

bool between(int a, int b, int c, int d){
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return max(a, c) <= min(b, d);
}


bool segment_inter(Point A, Point B, Point C, Point D){
	if (!C.cross(A, D) && !C.cross(B, D)) return between(A.x, B.x, C.x, D.x) && between(A.y, B.y, C.y, D.y);
	return sgn(A.cross(B, C)) != sgn(A.cross(B, D)) && sgn(C.cross(D, A)) != sgn(C.cross(D, B));
}

struct e{
	int a, b; 
	LD c;
	e(int _a = 0, int _b = 0, LD _c = 0){
		a = _a;
		b = _b;
		c = _c;
	}
};

void solve(){
	cerr << fixed << setprecision(5);
	int n; cin >> n;
	vector<Point>a(n);
	for (auto &[x, y]: a) cin >> x >> y;
	int m; cin >> m;
	vector<Point>b(m);
	for (auto &[x, y]: b) cin >> x >> y;

	vector<e>edges;
	vector<Point>A = otoczka(a);

	map<pair<int, int>, int>cha;
	for (int i = 0; i<n; i++) cha[{a[i].x, a[i].y}] = i;
	vector<vector<int>>g(n+m+2);
	pair<int, int>maxi = {-oo, -oo};
	int idx = -1;
	for (int i = 0; i<n; i++){
		if (maxi < make_pair(a[i].x, a[i].y)){
			maxi = make_pair(a[i].x, a[i].y);
			idx = i;
		}
	}
	function<void(int, int, LD)>add = [&](int a, int b, LD c){
		edges.emplace_back(a, b, c);
		debug(a, b);
		g[a].emplace_back(b);
		// g[b].emplace_back(a);
	};

	for (int i = 0; i<n; i++){
		int nx = (i == n-1?0:i+1);
		add(i, nx, d(a[i], a[nx]));
	}
	for (int i = 0; i<(int)A.size(); i++){
		int nx = (i == 0?(int)A.size()-1:i-1);
		bool ok = 0;
		for (int k = 0; k<m; k++) ok |= segment_inter(A[i], A[nx], b[k], b[(k == m-1?0:k+1)]);
		if (!ok) add(cha[{A[i].x, A[i].y}], cha[{A[nx].x, A[nx].y}], d(A[i], A[nx]));
	}
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++){
			bool ok = 0;
			for (int k = 0; k<m; k++){
				int nx = (k == m-1?0:k+1);
				if (k == j || nx == j) continue;
				ok |= segment_inter(a[i], b[j], b[k], b[nx]);
			}
			for (int k = 0; k<n; k++){
				int nx = (k == n-1?0:k+1);
				if (k == i || nx == i) continue;
				ok |= segment_inter(a[i], b[j], a[k], a[nx]);
			}
			if (!ok) {
				if (i != idx) ok |= segment_inter(a[i], b[j], Point{maxi.first, maxi.second}, Point({oo, maxi.second}));
				if (!ok) {
					add(i, j+n+1, d(a[i], b[j]));
				}
			}
		}
	}
	for (int i = 0; i<m; i++) {
		int nx = (i == m-1?0:i+1);
		add(i+n+1, nx+n+1, d(b[i], b[nx]));
	}
	debug(maxi);
	vector<Point>c = a;
	c.emplace_back(a[idx]);
	c[idx].y++;
	c[n].y--;
	for (auto v: b) c.emplace_back(v);

	vector<LD>dist(n+m+4, oo);
	for (auto x:g[idx]) {
		// g[x].emplace_back(n);
	}

	sort(edges.begin(), edges.end(), [](auto a, auto b){
		if (a.a == b.a) return a.b < b.b;
		return a.a < b.a;
	});


	for (int i = 0; i<=n+m; i++){
		sort(g[i].begin(), g[i].end());
		g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
		debug(i, g[i]);
	}

	// return;
	function<void(int)>dijkstra = [&](int from){
		set<pair<LD, int>>s;
		s.insert({0, from});
		dist[from] = 0;
		debug(from);
		vector<bool>vis(n+m+4);
		while (s.size()){
			auto [dd, v] = *s.begin();
			s.erase(s.begin());
			if (vis[v]) continue;
			vis[v] = 1;
			for (auto x:g[v]){
				bool ok = !segment_inter(c[v], c[x], Point{maxi.first, maxi.second}, Point({oo, maxi.second}));
				if (!ok) continue;
				// debug(dd, v, x);
				LD X = dd+d((v == idx || v == n?a[idx]:c[v]), c[x]);
				if (X < dist[x]){
					// debug(x, v, X);
					dist[x] = X;
					s.insert({dist[x], x});
				}
			}
		}
	};

	dijkstra(idx);
	debug(dist);
	cout << fixed << setprecision(15);
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}