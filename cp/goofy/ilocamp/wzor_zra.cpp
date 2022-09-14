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
	
	unsigned long long dist(point& other){
		LL a = (other.x-x)*(other.x-x);
		LL b = (other.y-y)*(other.y-y);
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
	unsigned long long ans = ULLONG_MAX;
	unsigned long long maxi = 0;
	rep(i, 0, n){
		ans = min(ans, (unsigned long long)tab[i].st + maxi);
		maxi = max(maxi, (unsigned long long)tab[i].nd);
	}
	rep(i, 0, n) swap(tab[i].st, tab[i].nd);
	sort(all(tab));
	reverse(all(tab));
	maxi = 0;
	rep(i, 0, n){
		ans = min(ans, (unsigned long long)tab[i].st + maxi);
		maxi = max(maxi, (unsigned long long)tab[i].nd);
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}

