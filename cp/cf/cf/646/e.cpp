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

const int MAX = 2e5+7;
int a[MAX], b[MAX], c[MAX];
vi graf[MAX];

void dfs(int v, int pa = -1){
	for (auto x: graf[v]){
		if (x!=pa){
			a[x] = min(a[x], a[v]);
			dfs(x, v);
		}
	}
}

void solve(){
	int n; cin >> n;
	vi s, e;
	rep(i, 1, n+1){
		cin >> a[i] >> b[i] >> c[i];
		s.pb(b[i]);
		e.pb(c[i]);
	}
	rep(i, 1, n){
		int x, y; cin >> x >> y;
		graf[x].pb(y);
		graf[y].pb(x);
	}
	sort(all(s));
	sort(all(e));
	rep(i, 0, sz(s)){
		if (s[i]!=e[i]){
			cout << "-1\n";
			return;
		}
	}
	//debug("yay");
	dfs(1);
	rep(i, 1, n+1) debug(a[i]);
	cerr << "\n";
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
