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

const int MAX = 1e6+7;
vi pos[MAX];
void solve(){
	vi ans(MAX, -1);
	int n; cin >> n;
	rep(i, 1, n+1){
		int x; cin >> x;
		pos[x].pb(i);
	} 
	rep(i, 1, MAX){
		if (sz(pos[i])){
			if (sz(pos[i]) == 1) ans[i] = 0;
			else {
				bool ok = 1;
				int x = pos[i][1]-pos[i][0];
				rep(j, 2, sz(pos[i])){
					if (pos[i][j]-pos[i][j-1]!=x){
						ok = 0;
						break;
					}
				}
				if (ok) ans[i] = x;
			}
		}
	}
	vpii out;
	rep(i, 1, MAX){
		if (ans[i]!=-1) out.pb({i, ans[i]});
	}
	cout << sz(out) << "\n";
	for (auto x: out) cout << x.st << " " << x.nd << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
