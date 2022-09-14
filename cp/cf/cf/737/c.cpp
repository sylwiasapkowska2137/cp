#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define pll pair<LL, LL>
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)

const LL MOD = 1e9+7;
const int MAX = 2e5+7;
int dp[MAX][2];


struct mi {
	LL v; explicit operator LL() const { return v; }
	mi() { v = 0; }
	mi(LL _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
   
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
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	mi operator++(int) { mi temp; temp.v = v++; return temp; }
	mi operator--(int) { mi temp; temp.v = v--; return temp; }
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


mi s[MAX];

void silnia(){
	s[0] = 1;
	rep(i, 1, MAX) s[i] = s[i-1]*i;
}

mi choose(int n, int k){
	return s[n]/(s[k]*s[n-k]);
}


void solve(){
	int n, k;
	cin >> n >> k;
	mi dp[k+1][2];
	memset(dp, 0, sizeof(dp));
	mi even = 0LL, odd = 0LL;
	rep(i, 0, n){
		if (i&1) odd += choose(n, i);
		else even += choose(n, i);
	}
	dp[0][0] = 1;
	rep(i, 0, k){
		dp[i+1][1] += dp[i][1]*odd;
		dp[i+1][1] += dp[i][1]*even;
		dp[i+1][0] += dp[i][0]*even;
		dp[i+1][1] += dp[i][1];
		if (n&1) dp[i+1][0] += dp[i][0];
		else dp[i+1][1] += dp[i][0];
	}
	cout << dp[k][0]+dp[k][1] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	silnia();
	int t;
	cin >> t;
	while (t--) solve();
	
	
	return 0;
}



