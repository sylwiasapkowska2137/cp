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
    LD x, y;
    Point(){}
    Point(LD _x, LD _y){
        x = _x, y = _y;
    }
    Point& operator-=(const Point &t){
		x-=t.x;
		y-=t.y;
		return *this;
	}
};

struct O{
    Point x;
    LD r; 

    O(){}
    O(int _x, int _y, int _r){
        x.x = _x, x.y = _y, r = _r;
    }
};

LD pole(Point A, Point B, Point C){
	B-=A, C-=A;
	return abs(C.y*B.x-C.x*B.y);
}

LD dist2(Point A, Point B){
    A-=B;
    return sqrt(A.x*A.x+A.y*A.y);
}

const LD EPS = 0.000005;

bool dist(Point A, Point B, Point C, LD r){
    LD x = pole(A, B, C);
    x/=dist2(B, C);
    if (x <= r) return 0;
    //debug(r);
    LD ab = dist2(A, B);
    LD ac = dist2(A, C);
    LD bd = sqrt(ab-x);
    LD cd = sqrt(ac-x);
    LD ans = dist2(B, C)-bd-cd;
    return (ans>EPS);
}

void solve(){
	int n; cin >> n;
    vector<O>tab;
    for (int i = 0; i<n; i++){
        int x, y, r; cin >> x >> y >> r;
        tab.emplace_back(x, y, r);
    }
    int ans = n;
    LD R = 2.0*2137;
    Point start = {0, 0};
    for (LD i = 0; i<360.0; i+=0.1){
        LD angle = PI*(LD)i/(180.0);
        LD y = R*tan(angle);
        //debug(y);
        Point curr = {R*sin(angle), R*cos(angle)};
        //cerr << curr.x << " " << curr.y << "\n";
        //if (i == 90.0 || i == 270.0) curr.x = 0;
        //else if (i > 90.0 && i < 270.0) curr.x *= -1;
        int cnt = 0;
        for (int j = 0; j<n; j++){
            if (dist(tab[j].x, start, curr, tab[j].r)){
                cnt++;
            }
        }
        //if (cnt == 0) debug(i);
        ans = min(ans, cnt);
    }
    cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
