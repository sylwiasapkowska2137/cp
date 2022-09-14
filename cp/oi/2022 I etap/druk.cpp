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

const int MAX = 1007;
bool vis[MAX][MAX];
int V[MAX][MAX];
vector<string>tab, xd;
vi ans;
int n, m;

void check(string s){
	int d = sz(s);
	//debug(s);
	//i, j jak sprawdizc czy w poziomie czy w pionie
	queue<pii>q;
	
	q.push({0, 0});
	//cerr << "\n";
	memo(vis);
	memo(V);
	int tmp  = 0;
	while (!q.empty()){
		pii v = q.front();q.pop();
		
		
		if (v.st >= n || v.nd >= m) continue; 
		if (vis[v.st][v.nd]) continue;
		vis[v.st][v.nd] = 1;
		//debug(v.st);
		//debug(v.nd);
		//poziomy
		if (v.st + d <= n){
			bool ok = 1;
			rep(i, v.st, v.st+d){
				if (tab[i][v.nd]!=s[i-v.st]){
					ok = 0;
					break;
				}
			}
		
			if (ok){
				//vis[v.st+d][v.nd] = 1;
				q.push({v.st+d, v.nd});
				//vis[v.st][v.nd+1] = 1;
				q.push({v.st, v.nd+1});
				//debug("pion");
				tmp++;
				rep(i, v.st, v.st+d){
					V[i][v.nd]++;
				}
				//continue;
			}
			
		}
		if (v.nd + d <= m){ //pionowy
			bool ok = 1;
			rep(i, v.nd, v.nd+d){
				if (tab[v.st][i] != s[i-v.nd]){
					ok = 0;
					break;
				}
			}
			
			if (ok){
				//vis[v.st][v.nd+d] = 1;
				q.push({v.st, v.nd+d});
				//vis[v.st+1][v.nd] = 1;
				q.push({v.st+1, v.nd});
				//debug("poziom");
				tmp++;
				rep(i, v.nd, v.nd+d){
					V[v.st][i]++;
				}
			}
		}
		//cerr <<"\n";
	}
	if (tmp >= n*m/d){
		bool ok = 1;
		rep(i, 0, n){
			rep(j, 0, m){
				//debug(V[i][j]);
				if (V[i][j] == 0) ok = 0;
			}
			//cerr << "\n";
		}
		if (!ok) return;
		ans.pb(d);
		xd.pb(s);
	}
}

void solve(){
	cin >> n >> m;
	tab.resize(n);
	rep(i, 0, n) cin >> tab[i];
	
	
	
	set<int>used;
	for (int i = 1; i*i<=n; i++){
		if (n%i == 0){
			if (used.find(i) == used.end()){
				//i
				string t;
				rep(len, 0, i) t+=tab[len][0];
				check(t);
				t.clear();
				if (m >= i) {
					rep(len, 0, i) t+=tab[0][len];
					check(t);
				}
				used.insert(i);
			}
			if (used.find(n/i) == used.end()){
				//n/i
				string t;
				rep(len, 0, n/i) t+=tab[len][0];
				check(t);
				t.clear();
				if (m >= n/i) {
					rep(len, 0, n/i) t+=tab[0][len];
					check(t);
				}
				used.insert(n/i);
			}
		}
	}
	
		for (int i = 1; i*i<=m; i++){
		if (m%i == 0){
			if (used.find(i) == used.end()){
				//i
				string t;
				if (n >= i) {
					rep(len, 0, i) t+=tab[len][0];
					check(t);
					t.clear();
				}
				rep(len, 0, i) t+=tab[0][len];
				check(t);
				used.insert(i);
			}
			if (used.find(m/i) == used.end()){
				//n/i
				string t;
				if (n >= m/i) {
					rep(len, 0, m/i) t+=tab[len][0];
					check(t);
					t.clear();
				}
				rep(len, 0, m/i) t+=tab[0][len];
				check(t);
				used.insert(m/i);
			}
		}
	}
	
	sort(all(ans));
	ans.erase(unique(all(ans)), ans.end());
	cout << sz(ans) << "\n";
	for (auto x: ans) cout << x << " ";
	//cerr << "\n";
	//for (auto x: xd) debug(x);
	//cerr << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
