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

LL low(int k){
	return k*(k+1)/2;
}

LL high(int n, int ile){
	return ile*(2*n+1-ile)/2;
}

void solve(){
	int n, l, r, s;
	cin >> n >> l >> r >> s;
	int ile = r-l+1;
	LL lo = low(ile), hi = high(n, ile); //n-(ile-1), n-(ile-2), .., n-1, n-0 -> n-(n-ile+1)+1
	if (s < lo || s > hi) cout << "-1\n";
	else {
		//cout << "ok\n";
		vector<bool>interval(n+1, 0);
		vi special;
		repd(i, n, 1){
			if (ile > 0 && high(i, ile)>=s && s-i>=low(ile-1)) {
				s-=i;
				ile--;
				special.pb(i);
				interval[i] = 1;
			}
		}
		//rep(i, 1, n+1) debug(interval[i]);
		//cerr << "\n";
		
		int ptr = 1, x = 1;
		while (ptr < l){
			if (!interval[x]){
				cout << x << " ";
				ptr++;
			}
			x++;
		}
		for (auto x: special) cout << x << " ";
		while (x<=n){
			if (!interval[x]){
				cout << x << " ";
			}
			x++;
		}
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}

