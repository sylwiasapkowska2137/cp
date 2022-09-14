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

const int MAX = 4e5+7;
vi graf[MAX];

void solve(){
	string s;
	getline(cin, s);
	int n, k; cin >> n >> k;
	vi depth(n+1, 0);
	vi deg(n+1, 0);
	rep(i, 1, n+1) graf[i].clear();
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
		deg[a]++;
		deg[b]++;
	}
	queue<int>q;
	rep(i, 1, n+1){
		if (sz(graf[i]) == 1){
			q.push(i);
			deg[i]--;
		}
	}
	
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (auto x: graf[v]){
			deg[x]--;
			if (deg[x] == 1){
				depth[x] = depth[v]+1;
				q.push(x);
			}
		}
	}
	int ans = 0;
	rep(i, 1, n+1) if (depth[i]>=k) ans++;
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
