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
 
const int MAX = 1e6+1;
vi graf[MAX];
vi dp1, dp2, special;
int ile;

void dfs(int v, int pa = -1){
	if (special[v]) dp1[v] = 0;
	for (auto x: graf[v]){
		if (x!=pa){
			dfs(x, v);
			dp1[v] = max(dp1[v], dp1[x]+1);
		}
	}
}

void dfs2(int v, int pa = 0){
	if (special[pa]) dp2[v] = max(dp2[v], 1);
	dp2[v] = max(dp2[v], dp2[pa]);
	for (auto x: graf[v]){
		if (x != pa){
			dp2[x] = dp2[v]+1;
			for (auto w: graf[v]){
				if (x != pa && w != pa && x != w){
					dp2[x] = max(dp2[x], dp1[w]+2);
				}
			}
			dfs2(x, v);
		}
	}
}


void solve(){
	int n; cin >> n;
	dp1.assign(n+1, INT_MIN);
	dp2.assign(n+1, INT_MIN);
	special.assign(n+1, 0);
	int ile = 0;
	rep(i, 1, n+1) {
		cin >> special[i];
		ile += special[i];
	}
	if (ile == 0){
		cout << "-1\n";
		return;
	}
	
	rep(i, 1, n){
		int a, b; cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	dfs(1);
	dfs2(1);
	int ans = INT_MAX;
	
	/*
	rep(i, 1, n+1) debug(dp1[i]);
	cerr << "\n";
	rep(i, 1, n+1) debug(dp2[i]);
	cerr << "\n";
	*/
	rep(i, 1, n+1){
		ans = min(ans, max(dp1[i], dp2[i]));
	}
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}

