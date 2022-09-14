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

int c[2];
bool ok;
const int MAX = 2e5+7;
vpii graf[MAX];
vi color;

void dfs(int v){
	c[color[v]]++;
	for (auto x: graf[v]){
		if (color[x.st] == -1){
			color[x.st] = color[v]^x.nd;
			dfs(x.st);
		} else {
			if (color[x.st]^color[v] != x.nd){
				ok = 0;
				return;
			}
		}
	}
}

void solve(){
	int n, m; cin >> n >> m;
	rep(i, 0, n+1) graf[i].clear();
	rep(i, 0, m){
		int a, b; cin >> a >> b;
		string s; cin >> s;
		if (s[0] == 'i'){
			//a and b are in different teams
			graf[a].pb({b, 1});
			graf[b].pb({a, 1});
		} else {
			graf[a].pb({b, 0});
			graf[b].pb({a, 0});
		}
	}
	int ans = 0;
	ok = 1;
	color.assign(n+1, -1);
	rep(i, 1, n+1){
		if (color[i] == -1){
			c[0] = c[1] = 0;
			color[i] = 0;
			dfs(i);
			ans += max(c[0], c[1]);
		}
	}
	if (!ok) cout << "-1\n";
	else cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
