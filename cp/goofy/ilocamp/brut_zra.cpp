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

struct point{
	LL x, y;
	
	friend istream& operator >> (istream& stream, point& p) {
		return stream >> p.x >> p.y;
	}
	
	LL dist(point& other){
		LL a = abs((other.x-x))*abs((other.x-x));
		LL b = abs((other.y-y))*abs((other.y-y));
		return a+b;
	}
};


void solve(){
	int n; cin >> n;
	point a, b; cin >> a >> b;
	vpll tab;
	rep(i, 0, n){
		point x; cin >> x;
		tab.pb({x.dist(a), x.dist(b)});
	}
	sort(all(tab));
	reverse(all(tab));
	
	LL ans = LLONG_MAX;
	rep(i, 0, n){
		LL ra = tab[i].st, rb = 0;
		rep(j, 0, i){
			if (tab[j].st > ra) rb = max(rb, tab[j].nd);
		}
		ans = min(ans, ra+rb);
	}
	rep(i, 0, n){
		swap(tab[i].st, tab[i].nd);
	}
	sort(all(tab));
	reverse(all(tab));
	rep(i, 0, n){
		LL ra = tab[i].st, rb = 0;
		rep(j, 0, i){
			if (tab[j].st > ra) rb = max(rb, tab[j].nd);
		}
		ans = min(ans, ra+rb);
	}
	
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}

