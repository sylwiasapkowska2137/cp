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
#define memo(x, val) memset(x, val, sizeof(x))
#define debug(x) cerr << x << " "

const int MAX = 5e5+7, INF = 1e9+7;
int dp[MAX];
vpii graf[MAX];
int n;

int count_dp(int v){
	//debug(v);
	if (v>n) return 0;
	if (dp[v]!=INF) return dp[v];
	for (auto x: graf[v]){
		if (x.st < v) continue;
		//wiekszy, albo x+1, albo x+2;
		if (x.st == v+1){
			dp[v] = min(dp[v], count_dp(v+2)+x.nd);
		} else if (x.st == v+2){
			//sprawdzic krawedz v+1, v+3
			bool ok = 0;
			int waga = 0;
			for (auto w: graf[v+1]){
				if (w.st == v+3){
					ok = 1;
					waga = w.nd;
				}
			}
			if (ok){
				dp[v] = min(dp[v], count_dp(v+4)+x.nd+waga);
			}
		}
	}
	return dp[v];
}

void solve(){
	int m; cin >> n >> m;
	if (n&1){
		cout << "-1\n";
		return;
	}
	rep(i, 1, n+1) dp[i] = INF;
	rep(i, 0, m){
		int a, b, c; cin >> a >> b >> c;
		graf[a].pb({b, c});
		graf[b].pb({a, c});
	}
	int x = count_dp(1);
	if (x == INF) cout << "-1\n";
	else cout << x << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}

