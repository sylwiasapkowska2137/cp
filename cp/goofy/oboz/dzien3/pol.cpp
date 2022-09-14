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

const int MAXK = 11, MAXN = 2003;
int p[MAXK][MAXN];
int dp[MAXN][MAXN];
// dp2[MAXN][MAXN];
int n, k, size;
LL ans;
bool ok = 0;
vi z1, z2;

void count(vi x1, vi x2){
	memo(dp);
	//memo(dp2);
	
	vi prev(n), curr(n);
	do {
		if (ok) rep(i, 0, n) prev[p[k][i]] = i;
		else rep(i, 0, n) prev[i] = i;
		rep(i, 0, sz(x1)){
			rep(j, 0, n) curr[p[x1[i]][j]] = prev[j]; 
			swap(prev, curr);
		}
		rep(i, 0, n) dp[prev[i]][i]++;
	} while (next_permutation(all(x1)));
	
	
	do {
		rep(i, 0, n) prev[i] = i;
		rep(i, 0, sz(x2)){
			rep(j, 0, n) curr[p[x2[i]][j]] = prev[j]; 
			swap(prev, curr);
		}
		//rep(i, 0, n) dp2[prev[i]][i]++;
		rep(i, 0, n) ans += dp[i][prev[i]];
	} while (next_permutation(all(x2)));
	/*
	rep(i, 0, n){
		rep(j, 0, n){
			ans += (LL)dp[i][j]*(LL)dp2[j][i];
		}
	}
	*/
}

void combi(int i){
	if (sz(z1) + sz(z2) == k){
		count(z1, z2);
		return;
	}
	if (sz(z1) < size){
		z1.pb(i);
		combi(i+1);
		z1.pop_back();
	}
	if (sz(z2) < k-size){
		z2.pb(i);
		combi(i+1);
		z2.pop_back();
	}
}

void solve(){
	cin >> n >> k;
	
	rep(i, 0, k){
		rep(j, 0, n) {
			cin >> p[i][j];
			p[i][j]--;
		}
	}
	
	if (k == 11){
		ok = 1;
		k--;
	}
	
	size = k/2+k%2;
	combi(0);
	if (ok) ans*=11;
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
