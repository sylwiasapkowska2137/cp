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

const int K = 27, MAX = 5007;
const LL MOD = 998244353;
LL dp[K][MAX], fact[MAX];

LL power(LL a, LL b){
	if (!b) return 1LL;
	LL k = power(a, b/2);
	k = (k*k)%MOD;
	if (b&1) return k = (a*k)%MOD;
	return k;
}

LL inv(LL a){
	return power(a, MOD-2);
}

LL C(int n, int k){
	return (fact[n]*inv((fact[k]*fact[n-k])%MOD))%MOD;
}

void solve(){
	string s; cin >> s;
	fact[0] = 1LL;
	rep(i, 1, MAX) fact[i] = (fact[i-1]*(LL)i)%MOD;
	int n = sz(s);
	vi freq(30, 0);
	rep(i, 0, n) freq[s[i]-'a']++;
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
