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

struct Point{
	int x, y;

	Point(){}
	Point(int _x, int _y) {x = _x, y = _y;}

	Point& operator-=(const Point &he){
		x -= he.x;
		y -= he.y;
		return *this;
	}

	int operator*(const Point &he){
		return he.y*x-he.x*y;
	}
};

int dist(Point A, Point B){
	A -= B;
	return A.x*A.x+A.y*A.y;
}
 
int orientation(Point A, Point B, Point C){
	A-=C; B-=C;
	int c = B.y*A.x-B.x*A.y;
	if (c > 0) return 1;
	if (c < 0) return -1;
	return 0;
}
 
bool cw(Point A, Point B, Point C){
	int o = orientation(A, B, C);
	return o < 0;
}

void otoczka(vector<Point>&a){
	Point p0 = *min_element(a.begin(), a.end(), [](auto x, auto y){return tie(x.y, x.x) < tie(y.y, y.x);});
	sort(a.begin(), a.end(), [&](const Point &A, const Point &B){
		int o = orientation(p0, A, B);
		if (!o) return dist(p0, A) < dist(p0, B);
		return (o < 0);
	});
	vector<Point>p;
	for (int i = 0; i<(int)a.size(); i++){
		while (p.size() > 1 && !cw(p[p.size()-2], p.back(), a[i])) p.pop_back();
		p.emplace_back(a[i]);
	}
	a = p;
}

void solve(){
	int n; cin >> n;
	vector<Point>a(n);
	for (auto &[x, y]: a) cin >> x >> y;
	int m; cin >> m;
	vector<Point>b(m);
	for (auto &[x, y]: b) cin >> x >> y;
	otoczka(a);
	long double ans = 0;
	int H = (int)a.size(); 
	for (int i = 0; i<H; i++){
		int nx = (i == H-1?0:i+1);
		ans += sqrt(dist(a[i], a[nx]));
	}
	cout << fixed << setprecision(15) << ans << "\n"; 
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
