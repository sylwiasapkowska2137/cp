#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

const LL MOD = 1e9+7;

struct mi {
	LL v; explicit operator LL() const { return v; }
	mi() { v = 0; }
	mi(LL _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		while (v < 0) v += MOD;
	}
	friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, LL p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
	friend ostream& operator<<(ostream& os, const mi& m) {
		os << m.v; return os;
	}
	friend istream& operator>>(istream& is, mi& m) {
		LL x; is >> x;
		m.v = x;
		return is;
	}
};

const int MAX = 3e6+7;
mi silnia[MAX], inwersja[MAX];

mi choose(int a, int b){
	if (b > a || a < 0 || b < 0)return 0;
	return silnia[a]*inwersja[b]*inwersja[a-b];
}

void solve(){
	int n, q, x;
	cin >> n >> q;
	silnia[0] = 1;
	inwersja[0] = 1;
	rep(i, 1, 3*n+3) {
		silnia[i] = silnia[i-1]*i;
		inwersja[i] = inv(silnia[i]);
	}
	mi dp[3*n+1][3], dwumian[3*n+2];
	rep(k, 0, 3) dp[0][k] = n;
	rep(x, 0, 3*n+2){
		dwumian[x] = choose(3*n, x);
		//debug(dwumian[x]);
	}
	rep(x, 1, 3*n+1){
		dp[x][0] = (dwumian[x+1]-2*dp[x-1][0]-dp[x-1][1])/3;
		dp[x][1] = dp[x][0] + dp[x-1][0];
		dp[x][2] = dp[x][1] + dp[x-1][1];
	}
	while (q--){
		cin >> x;
		cout << dp[x][0]+dwumian[x] << "\n";
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
