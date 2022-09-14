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


void solve(){
	int n, L, R; cin >> n >> L >> R;
	vi left(L), right(R);
	vi cntL(n+1, 0), cntR(n+1, 0);
	rep(i, 0, L) cin >> left[i];
	rep(i, 0, R) cin >> right[i];
	rep(i, 0, L) cntL[left[i]]++;
	rep(i, 0, R) cntR[right[i]]++;
	//cost 0
	rep(i, 0, n+1) {
		int x = min(cntL[i], cntR[i]);
		cntL[i] -= x;
		cntR[i] -= x;
	}
	
	rep(i, 1, n+1) debug(cntL[i]);
	cerr << "\n";
	rep(i, 1, n+1) debug(cntR[i]);
	cerr << "\n\n";
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
