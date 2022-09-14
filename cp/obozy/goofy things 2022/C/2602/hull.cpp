//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
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
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x, val) memset(x, val, sizeof(x))
#define PI 3.14159265359


struct Point{
	LL x, y;
	Point() {}
	Point (LL _x, LL _y){
		x = _x, y = _y;
	}
	Point& operator-=(const Point &t){
		x-=t.x;
		y-=t.y;
		return *this;
	}
};

LL dist(Point A, Point B){
	A -= B;
	return A.x*A.x+A.y*A.y;
}

vector<Point>points;

int orientation(Point A, Point B, Point C){
	A-=C; B-=C;
	LL c = B.y*A.x-B.x*A.y;
	if (c > 0) return 1;
	if (c < 0) return -1;
	return 0;
}

bool cw(Point A, Point B, Point C, bool include_collinear){
	int o = orientation(A, B, C);
	return (o < 0 || (include_collinear && !o));
}

bool collinear(Point A, Point B, Point C){
	return (orientation(A, B, C) == 0);
}

void otoczka(vector<Point>&a, bool include_collinear = false){
	Point p0 = *min_element(all(a), [](Point A, Point B){return make_pair(A.y, A.x) < make_pair(B.y, B.x);});
	sort(all(a), [&p0](const Point& A, const Point& B){
		int o = orientation(p0, A, B);
		if (!o) return dist(p0, A) < dist(p0, B);
		return (o < 0);
	});
	if (include_collinear){
		int i = sz(a)-1;
		while (i && collinear(p0, a[i], a.back())) i--;
		reverse(a.begin()+i+1, a.end());
	}
	vector<Point>p;
	rep(i, 0, sz(a)){
		while (sz(p) > 1 && !cw(p[sz(p)-2], p.back(), a[i], include_collinear)) p.pop_back();
		p.pb(a[i]);
	}
	cout << sz(p) << "\n";
	for (auto x: p) cout << x.x << " " << x.y << "\n";
}

void solve(){
	int n; cin >> n;
	rep(i, 0, n){
		int x, y; cin >> x >> y;
		points.emplace_back(x, y);
	}
	otoczka(points, 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
