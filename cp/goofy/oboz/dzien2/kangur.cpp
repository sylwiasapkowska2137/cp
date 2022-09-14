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

const int MAX = 1e5+7;
struct query{int a, b, indeks;};

void solve(){
	int n, m; cin >> n >> m;
	vll tab(n+1), ans(m, 0);
	vb vis(m, 0);
	int S = ceil(sqrt(n))+20;
	vector<query> q[S+2];
	vector<query>small;
	rep(i, 1, n+1) cin >> tab[i];
	rep(i, 0, m){
		int a, b, c; cin >> a >> b >> c;
		int koniec = a+b*c;
		if (c >= S){
			for (int j = a; j<=koniec; j+=c) ans[i]+=(LL)tab[j];
			vis[i] = 1;
		} else q[c].pb(query{a, koniec, i});
	}
	rep(d, 1, S){
		vll pref(n+2, 0);
		rep(i, 1, min(n+1, d+1)) pref[i] = tab[i];
		rep(i, d+1, n+1) pref[i] = pref[i-d]+tab[i];
		//rep(i, 0, n+1) debug(pref[i]);
		//cerr << "\n";
		for (auto x: q[d]) {
			ans[x.indeks] = pref[x.b];
			if (x.a>=d) ans[x.indeks]-=pref[x.a-d];
		}
	}
	rep(i, 0, m) cout << ans[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
