#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
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

bool intersect(pii c, pii d){
	if (c.st > d.st) swap(c, d);
    return c.nd > d.st and c.nd < d.nd;
}

void solve(){
	int n, k; cin >> n >> k;
	vpii tab;
	vector<bool>conn(2*n+1, 0);
	rep(i, 0, k){
		int a, b; cin >> a >> b;
		conn[a] = 1;
		conn[b] = 1;
		if (a>b)swap(a, b);
		tab.pb({a, b});
	}
	vi free;
	rep(i, 1, 2*n+1){
		if (!conn[i]) free.pb(i);
	}
	rep(i, 0, sz(free)/2){
		tab.pb({free[i], free[i+n-k]});
	}
	sort(all(tab));
	/*
	for (auto x: tab){
		debug(x.st);
		debug(x.nd);
		cerr<<"\n";
	}
	cerr << "\n";
	*/
	int ans = 0;
	rep(i, 0, sz(tab)){
		rep(j, i+1, sz(tab)){
			if (intersect(tab[i], tab[j])) ans++;
		}
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
