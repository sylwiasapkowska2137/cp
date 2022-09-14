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


struct Point{
	int x, y;
	
	friend istream & operator >> (istream &input, Point &t){
		input >> t.x >> t.y;
		return input;
	}
	
	Point& operator -= (Point &other){
		x-=other.x;
		y-=other.y;
		return *this;
	}
};

LL cross(Point A, Point B, Point C){
	A-=C; B-=C;
	return A.x*B.y-A.y*B.x;
}

bool cmp(Point a, Point b){
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

void solve(){
	Point a, b, c; cin >> a >> b >> c;
	if ((a.x == b.x && a.x == c.x) || (a.y == b.y && a.y == c.y)){
		cout << "1\n";
		return;
	}
	//a i b, check c
	if ((c.x == a.x && ((a.y <= c.y && c.y <= b.y) || ((a.y >= c.y && c.y >= b.y)))) || (c.y == a.y && ((a.x <= c.x && c.x <= b.x) || ((a.x >= c.x && c.x >= b.x))))) {
		cout << "2\n";
		return;
	}
	swap(a, c);
	if ((c.x == a.x && ((a.y <= c.y && c.y <= b.y) || ((a.y >= c.y && c.y >= b.y)))) || (c.y == a.y && ((a.x <= c.x && c.x <= b.x) || ((a.x >= c.x && c.x >= b.x))))) {
		cout << "2\n";
		return;
	}
	swap(c, b);
	if ((c.x == a.x && ((a.y <= c.y && c.y <= b.y) || ((a.y >= c.y && c.y >= b.y)))) || (c.y == a.y && ((a.x <= c.x && c.x <= b.x) || ((a.x >= c.x && c.x >= b.x))))) {
		cout << "2\n";
		return;
	}
	swap(a, b);
	if ((c.x == a.x && ((a.y <= c.y && c.y <= b.y) || ((a.y >= c.y && c.y >= b.y)))) || (c.y == a.y && ((a.x <= c.x && c.x <= b.x) || ((a.x >= c.x && c.x >= b.x))))) {
		cout << "2\n";
		return;
	}
	swap(a, c);
	if ((c.x == a.x && ((a.y <= c.y && c.y <= b.y) || ((a.y >= c.y && c.y >= b.y)))) || (c.y == a.y && ((a.x <= c.x && c.x <= b.x) || ((a.x >= c.x && c.x >= b.x))))) {
		cout << "2\n";
		return;
	}
	swap(b, c);
	if ((c.x == a.x && ((a.y <= c.y && c.y <= b.y) || ((a.y >= c.y && c.y >= b.y)))) || (c.y == a.y && ((a.x <= c.x && c.x <= b.x) || ((a.x >= c.x && c.x >= b.x))))) {
		cout << "2\n";
		return;
	}
	cout << "3\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
