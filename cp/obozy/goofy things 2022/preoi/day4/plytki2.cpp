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
	LD cross(const Point& p) const {return x * p.y - y * p.x;}
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

bool pointlineintersect(Point &P1, Point &P2, Point &P3){
    if(P2.cross(P1, P3) != 0) return 0;
    return (min(P2.x, P3.x) <= P1.x && P1.x <= max(P2.x, P3.x)) && (min(P2.y, P3.y) <= P1.y && P1.y <= max(P2.y, P3.y));
}


bool check(vector<Point>&P, vector<Point>&Q){
	for (auto &[x, y]:Q) x = -x, y = -y;
	/*
	for (auto [x, y]:P) {
		debug(x, y);
	}
	cerr << "\n";
	for (auto [x, y]:Q) {
		debug(x, y);
	}
	cerr << "\n";
	*/
	reorder(P);
	reorder(Q);
	P.push_back(P[0]);
    P.push_back(P[1]);
    Q.push_back(Q[0]);
    Q.push_back(Q[1]);
	vector<Point>result;
	result.push_back({0, 0});
	int I = 0, J = 0;
    while(I <(int)P.size() - 2 || J <(int)Q.size() - 2){
        result.push_back(P[I] + Q[J]);
        auto cross = (P[I+1]-P[I]).cross(Q[J+1]-Q[J]);
        if(cross >= 0) I++;
        if(cross <= 0) J++;
    }
	for (auto &[x, y]:Q) x = -x, y = -y;
	P.pop_back();
	Q.pop_back();
	P.pop_back();
	Q.pop_back();
    //for (auto [x, y]:result) {
	//	debug(x, y);
	//}
	int N = (int)result.size()-1;
	int cnt = 0;
    bool boundary = false;
	for (int i = 1; i <= N; i++){
		int j = (i == N ? 1 : i + 1);
		if (pointlineintersect(result[0], result[i], result[j])) boundary = true;
		if (result[i].x <= result[0].x && result[0].x < result[j].x && result[0].cross(result[i], result[j]) < 0) cnt++;
		else if (result[j].x <= result[0].x && result[0].x < result[i].x && result[0].cross(result[j], result[i]) < 0) cnt++;
	}
	if (!boundary && cnt&1) {
		//cerr << "inside\n";
		return 0;
	}
	//cerr << "outside\n";
	return 1;
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
		for (int j = 0; j<n; j++){
			if (i == j) {
				d[i][j] = INF;
				continue;
			}
			//ile musimy przesunac wielokąt j by nie pokrywał sie w wielokatem i
			LD L = 0, R = 1e9;
			while (R-L>EPS){
				LD mid = (L+R)/2;
				for (auto& [x, y]:p[j]) x+=mid;
				bool ok = check(p[i], p[j]);
				//debug(ok);
				if (ok) R = mid;
				else L = mid;
				for (auto &[x, y]:p[j]) x-=mid;
				//break;
			}
			d[i][j] = L;
		}
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

//O(n^2(2^n+k log C))