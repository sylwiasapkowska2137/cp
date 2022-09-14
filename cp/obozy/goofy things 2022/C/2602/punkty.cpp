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

int p(int a, int b){
	return a+rng()%(b-a+1);
}

struct Point{
	LL x, y;
	Point() {}
	Point (LL x, LL y): x(x), y(y) {}
	
	friend istream& operator >> (istream& input, Point &t){
		input >> t.x >> t.y;
		return input;
	}
	
	friend ostream& operator << (ostream& output, Point& t){
		output << t.x << " " << t.y << "\n";
		return output;
	}
	
	Point& operator-=(const Point &t){
		x-=t.x;
		y-=t.y;
		return *this;
	}
};

vector<Point>points;
vector<Point>P;

LL dist(Point a, Point b){
	LL x = (a.x-b.x);
	LL y = (a.y-b.y);
	return x*x+y*y;
}

int cross(Point A, Point B, Point C){ 
	A-=C;B-=C; 
	LL c = A.x*B.y-A.y*B.x;
	//return sgn(c); 
	if (c > 0) return 1;
	if (c < 0) return -1;
	return 0;
}

bool cmp(Point A, Point B){
	if (cross(A, B, P[1]) < 0) return 0;
	if (cross(A, B, P[1]) > 0) return 1;
	return dist(A, P[1]) < dist(B, P[1]);
}


vector<Point> otoczka(int n){
	P = points;
	rep(i, 2, n+1){
		if (P[i].x == P[1].x) if (P[i].y < P[1].y) swap(P[i], P[1]);
		if (P[i].x < P[1].x) swap(P[1], P[i]);
	}
	sort(P.begin()+2, P.end(), cmp);
	P.pb(P[1]);
	vector<Point>p;
	rep(i, 1, n+2){
		while (sz(p) > 1 && cross(p.back(), P[i], p[sz(p)-2]) < 0) p.pop_back();
		p.pb(P[i]);
	}
	p.pop_back();
	return p;
}
 
LL cross_area(Point A, Point B, Point C){
	A-=C;B-=C;
	return abs(A.x*B.y-A.y*B.x);
}

LL distant(vector<Point>&p){
	LL ans = dist(p[0], p[1]);
	if (sz(p) == 2) return ans;
	//for (auto x: p) cout << x;
	int R = 1;
	bool ok = 1;
	rep(i, 0, sz(p)){
		int prev = (i == 0)?(sz(p)-1):i-1;
		int next = (i == sz(p)-1)?0:i+1;
		if (cross(p[prev], p[i], p[next])){
			ok = 0;
			break;
		}
	}
	if (ok) return dist(p[0], p.back());
	rep(L, 0, sz(p)){
		//L, (L+1)%sz(p)
		ans = max(ans, dist(p[L], p[R]));
		while (cross_area(p[L], p[(L+1)%sz(p)], p[R]) <= cross_area(p[L], p[(L+1)%sz(p)], p[(R+1)%sz(p)])){
			//debug(L, R);
			R = ((R+1)%sz(p));
			ans = max(ans, dist(p[L], p[R]));
			ans = max(ans, dist(p[(L+1)%sz(p)], p[R]));
		}
	}
	return ans;
}

void solve(){
	int n; cin >> n;
	points.resize(n+1);
	rep(i, 1, n+1) cin >> points[i];
	vector<Point> p = otoczka(n);
	LL curr = distant(p);
	cout << curr << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
