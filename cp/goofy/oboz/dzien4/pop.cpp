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
 
const int MAX = 2007;
int graf[MAX][MAX];
 
void solve(){
	int n; cin >> n;
	rep(i, 1, n+1){
		rep(j, 1, n+1) {
			cin >> graf[i][j];
		}
	}
	int q;cin >> q;
	while (q--){
		int t; cin >> t;
		vi tab(t);
		rep(i, 0, t) cin >> tab[i];
		int curr = tab[0];
		rep(i, 1, t){
			int x = tab[i];
			if (graf[curr][tab[i]]) curr = tab[i];
		}
		
		//debug(curr);
		int ans = curr;
		rep(i, 0, t){
			if (tab[i] == curr) continue;
			if (!graf[tab[i]][curr] || graf[curr][tab[i]]) {
				ans = -1;
				break;
			}
		}
		cout << ans << "\n";
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
