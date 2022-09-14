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

const int MAX = 3e5+7;
vi graf[MAX];
vb vis;

void dfs(int v){
	vis[v] = 1;
	for (auto x: graf[v]){
		if (!vis[x]){
			dfs(x);
		}
	}
}

void solve(){
	int n, q; cin >> n >> q;
	while (q--){
		char type; cin >> type;
		if (type == '+'){
			int a, b; cin >> a >> b;
			graf[a].pb(b);
			graf[b].pb(a);
		} else if (type == '-'){
			int a, b; cin >> a >> b;
			for (int &x: graf[a]){
				if (x == b) {
					x = graf[a].back();
					break;
				}
			}
			for (int &x: graf[b]){
				if (x == a) {
					x = graf[b].back();
					break;
				}
			}
			graf[a].pop_back();
			graf[b].pop_back();
		} else {
			vis.assign(n+1, 0);
			int ans = 0;
			rep(i, 1, n+1){
				if (!vis[i]){
					ans++;
					dfs(i);
				}
			}
			cout << ans << "\n";
		}
		//rep(v, 1, n+1) for (auto x: graf[v]) cerr << v << " " << x << "\n";
		//cerr << "\n";
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
