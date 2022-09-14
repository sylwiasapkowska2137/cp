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

void solve(){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	int curr = 0;
	rep(i, 0, n) {
		if (s[i]=='T') curr+=2;
		else curr++;
	}
	int curr2 = curr;
	vpii ans(2*n+2, {-1, -1});
	int L = 0, R = n-1;
	while (L<=R && curr>=0){
		ans[curr] = {L, R};
		if (s[L]=='T') L++;
		else if (s[R] == 'T')	R--;
		else {
			L++;
			R--;
		}
		curr-=2;
	}
	
	//find first occ of W from left and right
	L = 0, R = n-1;
	while (L<n && s[L]!='W') L++;
	while (R>=0 && s[R]!='W') R--;
	if (curr2 == 2*n) goto OK;
	
	if (L <= n-1-R){
		R = n-1;
		curr = curr2 - 2*L - 1;
		L++;
	} else {
		L = 0;
		curr = curr2-2*(n-R-1)-1;
		R--;
	}
	

	//second parity
	while (L<=R && curr>=0){
		ans[curr] = {L, R};
		if (s[L]=='T') L++;
		else if (s[R] == 'T') R--;
		else {
			L++;
			R--;
		}
		curr-=2;
	}
	
	//queries
	OK:;
	while (m--){
		int a; cin >> a;
		if (ans[a].st == -1) cout << "NIE\n";
		else cout << ans[a].st+1 << " " << ans[a].nd+1 << "\n";
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
