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

const LL MOD = 998244353;
const int MAX = 1e4+7, MASK = (1<<10)+7;
pll dp[MAX][MASK][2][2];
LL pw[MAX];
int M, m;
string n; 

LL mul(LL a, LL b){
	return (a*b)%MOD;
}
 
void add(int &a, int b){
	a += b;
	if (a>=MOD) a-=MOD;
}

pii solve(int pos,int zero,int tight,int mask){
	if(pos == sz(n)){
		if ((mask&M)==M&&!zero){
			return {1,0};
		} else {
			return {0,0};
		}
	}
	pii ret = dp[pos][mask][zero][tight];
	if (ret.st>=0) return ret;
	ret = {0, 0};
	int x = n[pos]-'0';
	rep(k, 0, 10){
		if(tight&&k>x) break;
		int new_zero=zero&&k==0;
		int new_tight=tight&&k==x;
		int new_mask=mask;
		if(k>0||!zero) new_mask|=(1<<k);
		pii next = solve(pos+1,new_zero,new_tight,new_mask);
		add(ret.st, next.st);
		add(ret.nd, next.nd);
		add(ret.nd, mul(pw[sz(n)-1-pos], mul(next.st,k)));
	}
	return dp[pos][mask][zero][tight] = ret;
}

void solve(){
	cin >> n;
	int m; cin >> m;
	rep(i, 0, m){
		int x; cin >> x;
		M|=(1<<x);
	} 
	rep(pos, 0, sz(n)){
		rep(mask, 0, (1<<10)){
			rep(t, 0, 2){
				rep(z, 0, 2){
					dp[pos][mask][t][z] = {-1, -1};
				}
			}
		}
	}
	pw[0] = 1;
	rep(i, 1, MAX) pw[i] = (pw[i-1]*10LL)%MOD;
	pll ans = solve(0, 1, 1, 0);
	cout << ans.nd << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
