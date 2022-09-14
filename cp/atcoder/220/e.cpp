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

const LL MOD = 998244353;
const int MAXN = 2e6+7;

void solve(){
	LL n, d; cin >> n >> d;
	vll pot(MAXN);
	pot[0] = 1;
	rep(i, 1, MAXN){
		pot[i] = (pot[i-1]*2)%MOD;
	}
	LL ans = 0LL;
	rep(i, 1, n+1){
		if(i+d <= n) (ans += pot[d+i-1]) %= MOD;
		if(min(n - i,d - 1)>=max(1LL,i - n + d)){
			LL num = min(n - i,d - 1LL) - max(1LL,i - n + d) + 1;
			(ans += num*pot[d+i-3]% MOD) %= MOD;
		}
	}
	ans = (2*ans)%MOD;
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
