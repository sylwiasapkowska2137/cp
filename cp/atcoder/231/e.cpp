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

const LL INF = 1e18;
LL ans = INF;
map<pll, LL>mapa;
vll a;
LL n;

void backtrack(LL next, LL zan, LL mn){
	if (next >= n-1){
		ans = min(ans, mn+zan/a[next]);
		return;
	}
	if (mn >= ans) return;
	if (mapa.find({next, zan}) != mapa.end() && mapa[{next, zan}] <= mn) return;
	mapa[{next, zan}] = mn;
	LL d = a[next+1]/a[next];
	LL k = zan/a[next];
	k%=d;
	backtrack(next+1, zan-a[next]*k, mn+k);
	if(k > 0) backtrack(next+1, zan-a[next]*(k-d), mn+abs(k-d));
	else if(k < 0) backtrack(next+1, zan-a[next]*(k+d), mn+abs(k+d));
}

void solve(){
	LL x; cin >> n >> x;
	a.resize(n);
	rep(i, 0, n) cin >> a[i];
	backtrack(0, x, 0);
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
