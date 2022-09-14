//Sylwia Sapkowska
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "
#define PI 3.14159265359

LL losuj(LL a, LL b){ 
	return a+rng()%(b-a+1);
}

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

struct Point{
	LL x, y;
};

vector<Point>tab;

LL dist(Point A, Point B){
	LL x = A.x-B.x;
	LL y = A.y-B.y;
	return x*x+y*y;
}

int cross(Point A, Point B, Point C){
	Point X = Point{A.x-C.x, A.y-C.y};
	Point Y = Point{B.x-C.x, B.y-C.y};
	LL c = X.x*Y.y-X.y*Y.x;
	if (c > 0) return 1;
	if (c < 0) return -1;
	return 0;
}

bool cmp(Point A, Point B){
	if (cross(A, B, tab[0]) < 0) return 0;
	if (cross(A, B, tab[0]) > 0) return 1;
	return dist(A, tab[0]) > dist(B, tab[0]);
}

bool cmp3(Point A, Point B){
	if (cross(A, B, tab[0]) < 0) return 0;
	if (cross(A, B, tab[0]) > 0) return 1;
	return dist(A, tab[0]) < dist(B, tab[0]);
}

bool cmp2(Point A, Point B){
	if (A.x == B.x) return A.y < B.y;
	return A.x < B.x;
}

vector<Point>otoczka(vector<Point>tab, int N){
	vector<Point>p;
	rep(i, 0, N+1){
		while (sz(p) > 1 && cross(p.back(), tab[i], p[sz(p)-2]) < 0) p.pop_back();
		p.pb(tab[i]);
		//for (auto x: p) cerr << "(" << x.x << ", " << x.y << ") ";
		//cerr << "\n";
	}
	p.pop_back();
	return p;
}

void solve(){
	int n; cin >> n;
	tab.resize(n);
	rep(i, 0, n) cin >> tab[i].x >> tab[i].y;
	vector<Point>input = tab;
	int m; cin >> m;
	tab.resize(n+m);
	rep(i, 0, m) cin >> tab[n+i].x >> tab[n+i].y;
	
	int N = sz(tab);
	rep(i, 1, N){
		if (tab[i].x == tab[0].x) if (tab[i].y < tab[0].y) swap(tab[i], tab[0]);
		if (tab[i].x < tab[0].x) swap(tab[i], tab[0]);
	}
	sort(tab.begin()+1, tab.end(), cmp);
	tab.pb(tab[0]);
	vector<Point>p = otoczka(tab, N);
	
	if (sz(p) == n) {
		sort(all(input), cmp2);
		sort(all(p), cmp2);
		rep(i, 0, sz(p)){
			if (input[i].x!=p[i].x || input[i].y != p[i].y) {
				cout << "NO\n";
				return;
			}
		}
		tab.pop_back();
		sort(tab.begin()+1, tab.end(), cmp3);
		tab.pb(tab[0]);
		p = otoczka(tab, N);
		sort(all(p), cmp2);
		rep(i, 0, sz(p)){
			if (input[i].x!=p[i].x || input[i].y != p[i].y) {
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
	}
	else cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
