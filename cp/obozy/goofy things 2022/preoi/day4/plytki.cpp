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
	long double x, y; 
	void read(){
		cin >> x >> y;
	}	
	Point(){}
	Point (long double _x, long double _y){
		x = _x, y = _y;
	}

	Point& operator-=(const Point &t){
		x-=t.x;
		y-=t.y;
		return *this;
	}
};

int sgn(long long x){
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}

int orientation(Point A, Point B, Point C){
	A-=C; B-=C;
	long long c = B.y*A.x-B.x*A.y;
	return sgn(c);
}

const long long INF = 1e9+7;

struct Line{
	LL A, B, C;

	long long f(long long x){
		long long ans = -C-A*x;
		if (!B) return 0;
		if (ans%B != 0) return INF;
		return ans/B;
	}
};

Line make_line(Point X, Point Y){
	LL A = X.y-Y.y;
	LL B = Y.x-X.x;
	LL C = A*X.x+B*X.y;
	LL gcd = __gcd(A, B);
	gcd = __gcd(gcd, C);
	if (A < 0){
		A = -A, B = -B, C = -C;
	}
	if (gcd){
		A/=gcd, B /= gcd, C /= gcd;
	}
	return Line{A, B, -C};
}

bool inter(LL a, LL b, LL c, LL d){
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return min(a, c) <= max(b, d);
}

bool intersection(Point A, Point B, Point C, Point D){
	if (orientation(A, D, C) == 0 && orientation(B, D, C) == 0) return inter(A.x, B.x, C.x, D.x) && inter(A.y, B.y, C.y, D.y);
	return sgn(orientation(B, C, A)) != sgn(orientation(B, D, A)) && sgn(orientation(D, A, C)) != sgn(orientation(D, B, C));
}

void solve(){
	int n; cin >> n;
	vector<vector<Point>>p(n, vector<Point>());
	for (int i = 0; i<n; i++){
		int k; cin >> k;
		p[i].resize(k);
		for (int j = 0; j<k; j++) p[i][j].read();
	}
	const long double EPS = 1e-9;
	vector<vector<long double>>d(n, vector<long double>(n, INF));
	cout << fixed << setprecision(10);
	cerr << fixed << setprecision(10);
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			if (i == j) continue;
			//if (!(i == 2 && j == 0)) continue;

			long double L = 0, R = INF;
			while (R-L>EPS){
				long double mid = (L+R)/2;
				int pi = p[i].size();
				int pj = p[j].size();
				//mid = 3;
				for (auto &[x, y]:p[j]) x+=mid;
				bool ok = 1;
				//o ile musimy przesunac wielokąt j by nie pokrywal sie z i
				for (int k = 0; k<pi; k++){
					for (int l = 0; l<pj; l++){
						int nk = (k+1)%pi;
						int nl = (l+1)%pj;
						
						if (intersection(p[j][l], p[j][nl], p[i][k], p[i][nk])){
							debug(k, l);
							Line A = make_line(p[j][l], p[j][nl]);
							Line B = make_line(p[i][k], p[i][nk]);
							if (A.A == B.A && A.B == B.B && A.C == B.C) continue;
							cerr << "a\n";
							bool bound = 0;
							if (A.f(p[i][k].x) == p[i][k].y) bound = 1;
							if (A.f(p[i][nk].x) == p[i][nk].y) bound = 1;
							//if (B.f(p[j][l].x) == p[j][l].y) bound = 1;
							//if (B.f(p[j][nl].x) == p[j][nl].y) bound = 1;
							debug(bound);
							if (!bound) {
								ok = 0;
								break;
							}
						} 
						if (!ok) break;
					}
					if (!ok) break;
				}
				debug(ok);
				for (auto &[x, y]:p[j]) x-=mid;
				if (ok) R = mid;
				else L = mid;
				//break;
			}
			d[i][j] = L;
		}
	}
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			cerr << d[i][j] << " ";
		}
		cerr << "\n";
	}
	//return;
	const long double INF2 = 1e18;
	vector<vector<long double>>dp((1<<n), vector<long double>(n, INF2));
	for (int i = 0; i<n; i++) {
		dp[0][i] = 0;
	}
	for (int mask = 0; mask<(1<<n); mask++){
		for (int v = 0; v<n; v++){
			for (int x = 0; x<n; x++){
				if (v == x) continue;
				if (!(mask&(1<<x))){
					dp[mask^(1<<x)][x] = min(dp[mask^(1<<x)][x], dp[mask][v]+d[x][v]);
				}
			}
			debug(mask, v, dp[mask][v]);
		}
	}
	long double ans = INF;
	for (int i = 0; i<n; i++) ans = min(ans, dp[(1<<n)-1][i]);
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
