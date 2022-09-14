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

struct segment{
	int dist, l, r;
	segment(){}
	segment(int dist, int l, int r): dist(dist), l(l), r(r) {}
};

bool operator < (segment a, segment b){
	if (a.dist == b.dist) return a.l > b.l;
	return a.dist < b.dist;
}

void solve(){
	int n, X, z; cin >> n >> X >> z;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	pq<segment>q;
	rep(i, 1, n) q.push(segment{a[i]-a[i-1], a[i-1], a[i]});
	vpii k(z);
	rep(i, 0, z){
		cin >> k[i].st;
		k[i].nd = i;
	}
	sort(all(k));
	int curr = 0;
	rep(i, 0, z){
		while (curr < k[i].st){
			//s
		}
		
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
