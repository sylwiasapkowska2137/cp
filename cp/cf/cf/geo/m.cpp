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

struct Line{
	LL A, B, C;
	
	friend istream& operator >> (istream& input, Line &t){
		input >> t.A >> t.B >> t.C;
		return input;
	}
	
	friend ostream& operator << (ostream& output, Line& t){
		output << t.A << " " << t.B << " " << t.C <<  "\n";
		return output;
	}
	
};

Line make_line(Point X, Point Y){
	LL A = X.y-Y.y;
	LL B = Y.x-X.x;
	LL C = A*X.x+B*X.y;
	return Line{A, B, -C};
}

LL cross(Point A, Point B, Point C){
	A-=C;B-=C;
	return abs(A.x*B.y-A.y*B.x);
}

LD dist(Point a, Point b){
	LD x = (a.x-b.x);
	LD y = (a.y-b.y);
	return (LD)sqrt(x*x+y*y);
}

void solve(){
	setIO("line1");
	Point A, B;
	cin >> A >> B;
	Line ans = make_line(A, B);
	cout << ans; 
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
