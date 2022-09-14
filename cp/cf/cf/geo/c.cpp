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
	
	friend istream &operator>>(istream &input, Point &t) { 
		input >> t.x >> t.y;
		return input;            
	}
	
	friend ostream &operator <<(ostream &output, Point &t){
		output << t.x << " " << t.y << "\n";
		return output;
	}
};

LL cross(Point a, Point b, Point c){
	Point A = {a.x-c.x, a.y-c.y};
	Point B = {b.x-c.x, b.y-c.y};
	//cout << A << B;
	return A.x*B.y-A.y*B.x;
}

void solve(){
	//setIO("area");
	int n; cin >> n;
	vector<Point>a(n);
	rep(i, 0, n) cin >> a[i];
	LL ans = 0LL;
	rep(i, 1, n) {
		ans += cross(a[i], a[i-1], a[0]);
	}
	ans = abs(ans);
	cout << fixed << setprecision(1) << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
