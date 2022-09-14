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

struct Point{
	long long x, y;
	Point(){}
	Point(long long _x, long long _y){
		x = _x, y = _y;
	}
};

long long dist(Point A, Point B){
	A.x-=B.x;
	A.y-=B.y;
	return A.x*A.x+A.y*A.y;
}

int orientation(Point A, Point B, Point C){
	A.x-=C.x, A.y-=C.y;
	B.x-=C.x, B.y-=C.y;
	long long c = A.y*B.x-A.x*B.y;
	if (c > 0) return 1;
	if (c < 0) return -1;
	return 0;
}



vector<Point>otoczka(vector<Point>a, int n){
	Point p0 = *min_element(a.begin(), a.end(), [](Point A, Point B){return make_pair(A.y, A.x) < make_pair(B.y, B.x);});
	sort(a.begin(), a.end(), [&p0](const Point&A, const Point&B){
		int o = orientation(p0, A, B);
		if (o == 0) return dist(p0, A) < dist(p0, B);
		return (o<0);
	});
	vector<Point>p;
	for (int i = 0; i<(int)a.size(); i++){
		while (p.size() > 1 && orientation(p[p.size()-2], p.back(), a[i]) >= 0) p.pop_back();
		p.push_back(a[i]);
	}
	return p;
}

void solve(){
	int n; cin >> n;
	vector<Point>p(n);
	for (int i = 0; i<n; i++){
		cin >> p[i].x >> p[i].y;
	}
	vector<Point>hull = otoczka(p, n);	
	int H = (int)hull.size();
	//for (auto [x, y]:hull) cerr << x << " " << y << "\n";
	set<pair<int, int>>ans;
	for (int i = 0; i<H; i++){
		int prev = (i==0)?H-1:i-1;
		int next = (i==H-1)?0:i+1;
		if (dist(hull[i], hull[prev])+dist(hull[i], hull[next]) >= dist(hull[prev], hull[next])){
			ans.insert({hull[i].x, hull[i].y});
		}
	}
	vector<int>out;
	for (int i = 0; i<n; i++){
		if (ans.find({p[i].x, p[i].y}) != ans.end()){
			out.push_back(i+1);
		}
	}
	cout << (int)out.size() << "\n";
	for (auto x: out) cout << x << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
