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

const LL MOD = 1e18;
map<vi, vector<vi>>graf;

LL silnia(LL n){
	if (n <= 1) return 1;
	LL x = 1;
	rep(i, 2, n+1) {
		x*=(LL)i;
		if (x >= MOD) x%=MOD;
	}
	return x;
}
const int MAX = 10;
LL f[MAX];


void solve(){
	int n; cin >> n;
	rep(i, 0, MAX) f[i] = silnia(i);
	vi p(n);
	rep(i, 0, n) p[i] = i;
	LL ans = 0LL;
	vi res, maxi;
	int current = 0;
	map<int, int>cnt;
	do{
		vi curr = p;
		vi pos(n);
		int tmp = 0;
		rep(i, 0, n) pos[curr[i]] = i;
		while (!(is_sorted(all(curr)))){
			//debug("a");
			int top = curr[0];
			int prev = top-1;
			if (prev == -1) prev = n-1;
			tmp += pos[prev];
			cnt[pos[prev]]++;
			//debug(pos[prev]);
			rep(i, 0, n){
				if (curr[i] == prev) {
					pos[curr[i]] = 0;
					break;
				} else pos[curr[i]]++;
			}
			
			vi nowy;
			nowy.pb(prev);
			rep(i, 0, n) if (curr[i]!=prev) nowy.pb(curr[i]);
			graf[curr].pb(nowy);
			swap(nowy, curr);
		}
		res.pb(tmp);
		ans+=tmp;
		if (tmp > current) {
			current = tmp;
			maxi = p;
		}
	} while (next_permutation(all(p)));
	cout << ans << "\n";
	for (auto x: cnt){
		//debug(x.st);
		//debug(x.nd);
		
		debug(x.st*x.nd);
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
