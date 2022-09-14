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

struct Point{
	int x, y;
	Point() {}
	Point (int _x, int _y){
		x = _x, y = _y;
	}
	Point& operator-=(const Point &t){
		x-=t.x;
		y-=t.y;
		return *this;
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
	B-=A, C-=A;
	return abs(C.y*B.x-C.x*B.y);
}

int pole2(Point A, Point B, Point C){
	B-=A, C-=A;
	return C.y*B.x-C.x*B.y;
}

void solve(){
	int n, k; cin >> n >> k;
	vector<Point>points;
	for (int i = 0; i<n; i++){
		int x, y; cin >> x >> y;
		points.emplace_back(x, y);
	}
	vector<Point>p = otoczka(points);
	// for (auto [x, y]:p){
	// 	debug(x, y);
	// }
	int H = (int)p.size();
	if (k == 3){
		int a = 0, b = 1, c = 2;
		int ans = pole(p[a], p[b], p[c]);
		while (1){
			while (c != a){
				while (c!=a && pole(p[a], p[b], p[(c == H-1)?0:c+1]) >= pole(p[a], p[b], p[c])){
					c = (c == H-1)?0:c+1;
				}
				int X = pole(p[a], p[b], p[c]);
				ans = max(ans, X);
				b = (b==H-1)?0:b+1;
			}
			a = (a == H-1)?0:a+1;
			if (a == 0) {
				break;
			}
			b = (a == H-1)?0:a+1;
			c = (b == H-1)?0:b+1;
		}
		if (ans&1) cout << ans/2 << ".5\n";
		else cout << ans/2 << ".0\n";
		return;
	} 
	int ret = 0;
	for (int mask = 0; mask<(1<<H); mask++){
		if (__builtin_popcountll(mask) > k) continue;
		vector<int>idx;
		for (int i = 0; i<H; i++){
			if (mask&(1<<i)){
				idx.emplace_back(i);
			}
		}
		int curr = 0;
		for (int i = 0; i<(int)idx.size(); i++){
			curr += pole2(p[idx[0]], p[idx[i]], p[idx[(i == (int)idx.size()-1)?0:i+1]]);
		}
		//debug(idx, curr);
		ret = max(ret, abs(curr));
	}
	if (ret&1) cout << ret/2 << ".5\n";
	else cout << ret/2 << ".0\n";
}


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t = 1; 
	while (t--) solve();
	
	return 0;
}
