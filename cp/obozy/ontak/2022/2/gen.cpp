//Sylwia Sapkowska
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int p(int a, int b){
	return a+rng()%(b-a+1);
}


 
struct Point{
	int x, y;
 
	Point(int _x = 0, int _y = 0){
		x = _x;
		y = _y;
	}
 
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
	int c = A*B;
	if (c > 0) return 1;
	if (c < 0) return -1;
	return 0;
}
 
bool cw(Point A, Point B, Point C, bool include_collinear){
	int o = orientation(A, B, C);
	return (o < 0 || (include_collinear && !o));
}
 
bool collinear(Point A, Point B, Point C){
	return orientation(A, B, C) == 0;
}
 
vector<Point> convex_hull(vector<Point>& a, bool include_collinear = false) {
    Point p0 = *min_element(a.begin(), a.end(), [](Point a, Point b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&](Point a, Point b) {
        int o = orientation(p0, a, b);
        if (o == 0) return dist(p0, a) < dist(p0, b);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }
    vector<Point>p;
    for (int i = 0; i < (int)a.size(); i++) {
        while (p.size() > 1 && !cw(p[p.size()-2], p.back(), a[i], include_collinear))
            p.pop_back();
        p.push_back(a[i]);
    }
    return p;
}
 

void solve(){
	int T = p(2, 10);
	int P = p(1, T);
	for (int i = 0; i<T; i++) cout << (char)(p(0, 2)+'a');
	cout << "\n";
	for (int i = 0; i<P; i++) cout << (char)(p(0, 2)+'a');
	cout << "\n";
}

void solve2(){
	cout << "1\n1\n";
	int n = p(1, 10);
	vector<Point>points;
	vector<pair<int, int>>xd;
	for (int i = 0; i<n; i++){
		xd.emplace_back(p(1,10), p(1, 10));
	}
	sort(xd.begin(), xd.end());
	xd.erase(unique(xd.begin(),xd.end()), xd.end());
	for (auto [x, y]:xd){
		points.emplace_back(x, y);
	}
	points = convex_hull(points, 1);
	reverse(points.begin(), points.end());
	cout << (int)points.size() << endl;
	for (auto [x, y]:points){
		cout << x << " " << y << "\n";
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
