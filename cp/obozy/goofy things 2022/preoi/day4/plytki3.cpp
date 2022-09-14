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

typedef long double LD;

const LD INF = 1e18, EPS = 1e-10;

struct Point{
	LD x, y;

	Point(){}
	Point(LD _x, LD _y){x = _x, y = _y;}
	Point operator+(const Point& p) const {return Point{x + p.x, y + p.y};}
	Point operator - (const Point & p) const {return Point{x - p.x, y - p.y};}
	int cross(const Point& p) const {
		LD c = x*p.y-y*p.x;
		if (abs(c) < EPS || isnanl(c)) return 0;
		return (c>0)?1:-1;
	}
	void read(){ cin >> x >> y;}
	LD cross(const Point& b, const Point& c) const { return (b - *this).cross(c - *this);}
};

void reorder(vector<Point>&P){
    int pos = 0;
    for(int i = 1; i<(int)P.size(); i++){
        if(P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
            pos = i;
    }
    rotate(P.begin(), P.begin() + pos, P.end());
}

void reorder2(vector<Point>&P){
    int pos = 0;
    for(int i = 1; i<(int)P.size(); i++){
        if(P[i].y > P[pos].y || (P[i].y == P[pos].y && P[i].x > P[pos].x))
            pos = i;
    }
    rotate(P.begin(), P.begin() + pos, P.end());
}

bool pointlineintersect(Point &P2, Point &P3){
    if(P2.cross({0, 0}, P3) != 0) return 0;
    return (min(P2.x, P3.x) <= 0 && 0 <= max(P2.x, P3.x)) && (min(P2.y, P3.y) <= 0 && 0 <= max(P2.y, P3.y));
}

bool pointintriangle(Point pt, Point v1, Point v2, Point v3){
	int d1 = v2.cross(pt, v1);
	int d2 = v3.cross(pt, v2);
	int d3 = v1.cross(pt, v1);
	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return !(has_neg && has_pos);
}

bool check(vector<Point>&P, vector<Point>&Q){
	for (auto &[x, y]:Q) x = -x, y = -y;
	vector<Point>result;
	result.push_back({0, 0});
	int I = 0, J = 0;
    while(I < (int)P.size() - 2 || J <(int)Q.size() - 2){
        result.push_back(P[I] + Q[J]);
        int cross = (P[I+1]-P[I]).cross(Q[J+1]-Q[J]);
        if(cross >= 0) I++;
        if(cross <= 0) J++;
    }
	for (auto &[x, y]:Q) x = -x, y = -y;
	int N = (int)result.size()-1;
	int cnt = 0;
	for (int i = 1; i <= N; i++){
		int j = (i == N ? 1 : i + 1);
		if (pointlineintersect(result[i], result[j])) return 1;
		if (result[i].x <= 0 && 0 < result[j].x && result[0].cross(result[i], result[j]) < 0) cnt++;
		else if (result[j].x <= 0 && 0 < result[i].x && result[0].cross(result[j], result[i]) < 0) cnt++;
	}
	return (!(cnt&1));
}

const int MAX = 15;
LD d[MAX][MAX];
vector<Point>p[MAX];

void solve(){
	int n; cin >> n;
	vector<vector<long double>>dp((1<<n), vector<long double>(n, INF));
	for (int i = 0; i<n; i++){
		int k; cin >> k;
		LD mini = INF;
		LD maxi = -INF;
		for (int j = 0; j<k; j++) {
			LD x, y; cin >> x >> y;
			p[i].emplace_back(x, y);
			mini = min(mini, p[i][j].x);
			maxi = max(maxi, p[i][j].x);
		}
		dp[(1<<i)][i] = maxi-mini;
		for (auto &[x, y]:p[i]) x-=mini;
	}

	cout << fixed << setprecision(12);
	cerr << fixed << setprecision(12);
	for (int i = 0; i<n; i++){
		reorder(p[i]);
		p[i].push_back(p[i][0]);
		p[i].push_back(p[i][1]);
		for (int j = 0; j<n; j++){
			if (i == j) {
				d[i][j] = INF;
				continue;
			}
			//if (!(i == 0 && j == 1)) continue;
			reorder2(p[j]);
			p[j].push_back(p[j][0]);
			p[j].push_back(p[j][1]);
			//ile musimy przesunac wielokąt j by nie pokrywał sie w wielokatem i
			LD L = 0, R = 1e9;
			while (R-L>EPS){
				LD mid = (L+R)/2;
				//mid = 1.9;
				for (auto& [x, y]:p[j]) x+=mid;
				bool ok = check(p[i], p[j]);
				//debug(ok);
				if (ok) R = mid;
				else L = mid;
				for (auto &[x, y]:p[j]) x-=mid;
				//break;
			}
			p[j].pop_back();
			p[j].pop_back();
			d[i][j] = L;
		}
		p[i].pop_back();
		p[i].pop_back();
	}
	/*
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			cerr << d[i][j] << " ";
		}
		cerr << "\n";
	}
	debug(len);
	*/
	for (int mask = 1; mask<(1<<n); mask++){
		for (int v = 0; v<n; v++){
			for (int x = 0; x<n; x++){
				if (!(mask&(1<<x))){
					dp[mask^(1<<x)][x] = min(dp[mask^(1<<x)][x], dp[mask][v]+d[x][v]);
				}
			}
			//debug(mask, v, dp[mask][v]);
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
