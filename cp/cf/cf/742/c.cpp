#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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
LL ans = 0;


void solve(){
	int n;cin >> n;
	int c = n;
	vi digits;
	while (n>0){
		digits.pb(n%10);
		n/=10;
	}
	reverse(all(digits));
	vi odd, even;
	rep(i, 0, sz(digits)){
		if (i&1) even.pb(digits[i]);
		else odd.pb(digits[i]);
	}
	LL a = 0, b = 0;
	for (auto x: even){
		a*=10;
		a+=x;
	}
	for (auto x: odd){
		b*=10;
		b+=x;
	}
	cout << (a+1)*(b+1)-2 << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
