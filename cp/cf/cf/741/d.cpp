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

void solve(){
	int n, q; cin >> n >> q;
	string S; cin >> S;
	vector<bool>s(n+1, 0);
	rep(i, 1, n+1) if (S[i-1]=='+') s[i] = 1;
	vi pref(n+1);
	pref[0] = 0;
	rep(i, 1, n+1){
		pref[i] = pref[i-1];
		if (s[i] == (i&1)) pref[i]++;
		else pref[i]--;
	}
	while (q--){
		int a, b; cin >> a >> b;
		int len = b-a+1;
		if (len&1) cout << "1\n";
		else {
			if (pref[b]-pref[a-1]) {
				cout << "2\n";
				
			}
			else cout << "0\n";
		}
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

