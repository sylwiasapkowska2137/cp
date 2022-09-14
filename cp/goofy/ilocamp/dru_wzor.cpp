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


struct Q{
	int a, b, i;
};

const int MAX = 5e5+7, D = 52;
int a[MAX][3];
int n, d;
const LL INF = -1e16;
vll ans;


void fastscan(int &number){
	bool negative = false;
	register int c;
	number = 0;
	c = getchar();
	if (c=='-') {
		negative = true;
		c = getchar();
	}
	for (; (c>47 && c<58); c=getchar()) 
		number = number *10 + c - 48;
	if (negative) number *= -1;
}

void solve(vector<Q> *queries, int lx, int rx){
	if ((*queries).empty()) return;
	if (lx == rx){
		rep(k, 0, 3){
			if (a[lx][k]%d == 0){
				for (auto x: *queries) ans[x.i] = max(ans[x.i], (LL)a[lx][k]);
			}
		}
		return;
	}
   
	int len = rx-lx+2;
	LL suf[len][d], pref[len][d];
	rep(i, 0, len){
			rep(j, 0, d){
					pref[i][j] = INF;
					suf[i][j] = INF;
			}
	}
   
	int m = (lx+rx)/2;
	pref[0][0] = 0;
	rep(i, m+1, rx+1){
		rep(j, 0, d){
			rep(k, 0, 3){
				int x = (a[i][k]+j)%d;
				pref[i+1-(m+1)][x] = max(pref[i+1-(m+1)][x], pref[i-(m+1)][j]+a[i][k]);
			}
		}
	}
   
	suf[m+1-lx][0] = 0;
	repd(i, m, lx){
		rep(j, 0, d){
			rep(k, 0, 3){
				int x = (a[i][k]+j)%d;
				suf[i-lx][x] = max(suf[i-lx][x], suf[i+1-lx][j]+a[i][k]);
			}
		}
	}
	vector<Q>left, right;
	for (auto x: (*queries)){
		if (x.a <= m && x.b > m){
			rep(i, 0, d){
				ans[x.i] = max(ans[x.i], suf[x.a-lx][i]+pref[x.b-m][(d-i)%d]);
			}
			continue;
		}
		if (x.b <= m) left.pb(x);
		else right.pb(x);
	}
	solve(&left, lx, m);
	solve(&right, m+1, rx);
}

void solve(){
	fastscan(n);
	fastscan(d);
	rep(i, 1, n+1){
		rep(j, 0, 3) fastscan(a[i][j]);
	}
	int q; fastscan(q);
	vector<Q>queries(q);
	ans.assign(q, -1);
	rep(i, 0, q){
		fastscan(queries[i].a);
		fastscan(queries[i].b);
		queries[i].i = i;
	}
	solve(&queries, 1, n);
	rep(i, 0, q) cout << ans[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
	return 0;
}

