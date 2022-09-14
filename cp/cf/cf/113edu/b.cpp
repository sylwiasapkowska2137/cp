#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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
	int n; cin >> n;
	string s; cin >> s;
	vi ans;
	int dwa = 0;
	rep(i, 0, n) if (s[i]=='2') dwa++;
	if (dwa == 1 || dwa == 2){
		cout << "NO\n";
		return;
	}
	rep(i, 0, n){
		if (s[i]=='2') ans.pb(i);
	}
	char out[n+1][n+1];
	rep(i, 0, n)rep(j, 0, n) out[i][j] = '=';
	rep(i, 1, sz(ans)){
		out[ans[i]][ans[i-1]] = '+';
		out[ans[i-1]][ans[i]] = '-';
	}
	if (sz(ans)){
		out[ans[0]][ans[sz(ans)-1]] = '+';
		out[ans[sz(ans)-1]][ans[0]] = '-';
	}
	cout << "YES\n";
	rep(i, 0, n){
		rep(j, 0, n){
			if (i == j) cout << "X";
			else cout << out[i][j];
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
