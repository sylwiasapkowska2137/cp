//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;

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

#define int long long
const int oo = 1e18, K = 30;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
int ll(int a, int b){
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
	LL c = B.y*A.x-B.x*A.y;
	if (c > 0) return 1;
	if (c < 0) return -1;
	return 0;
}
 
bool cw(Point A, Point B, Point C){
	int o = orientation(A, B, C);
	return o < 0;
}
 
vector<Point> otoczka(vector<Point>&a){
	Point p0 = *min_element(a.begin(), a.end(), [](Point A, Point B){return make_pair(A.y, A.x) < make_pair(B.y, B.x);});
	sort(a.begin(), a.end(), [&p0](const Point& A, const Point& B){
		int o = orientation(p0, A, B);
		if (!o) return dist(p0, A) < dist(p0, B);
		return (o < 0);
	});
	vector<Point>p;
	for (int i = 0; i<(int)a.size(); i++){
		while ((int)p.size() > 1 && !cw(p[(int)p.size()-2], p.back(), a[i])) p.pop_back();
		p.emplace_back(a[i]);
	}
	return p;
}

int pole(Point A, Point B, Point C){
	A-=C; B-=C;
	return abs(B.y*A.x-B.x*A.y);
}

void solve(){
	int n, k; cin >> n >> k;
	vector<Point>points;
	for (int i = 0; i<n; i++){
		int x, y; cin >> x >> y;
		points.emplace_back(x, y);
	}
	vector<Point>p = otoczka(points);
	int H = (int)p.size();
	// for (auto [x, y]:p){
	// 	debug(x, y);
	// }
	int t = n/k*6;//.37
	int ans = 0;
	while (t--){
		int s = ll(0, H-1);
		vector<vector<int>>dp(n+1, vector<int>(k+1, 0));
		int x = H;
		vector<Point>hull;
		for (int i = s; x; i = (i==H-1?0:i+1), x--){
			hull.emplace_back(p[i]);
		}
		// debug(s);
		// for (auto [x, y]:hull){
		// 	debug(x, y);
		// }
		// cerr << "\n";
		for (int i = 0; i<H; i++){
			for (int ile = 3; ile<=k; ile++){
				for (int last = 0; last < i; last++){
					dp[i][ile] = max(dp[i][ile], dp[last][ile-1]+pole(hull[i], hull[last], hull[0]));
				}
			}
		}
		for (int i = 0; i<H; i++){
			for (int j = 0; j<=k; j++){
				if (ans < dp[i][j]){
					ans = dp[i][j];
				}
			}
		}
		
	}
	cout << ans/2 << (ans&1?".5":".0") << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--) solve();
	
	return 0;
}
