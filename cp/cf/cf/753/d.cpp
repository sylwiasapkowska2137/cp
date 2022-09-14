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

const int INF = -1e9;

void solve(){
	int n; cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	string s; cin >> s;
	map<int, int>bigger, smaller;
	rep(i, 0, n){
		if (s[i] == 'B'){
			smaller[a[i]]++;
		} else {
			bigger[-a[i]]++;
		}
	}
	vi pref(n+1, 0);
	LL curr = 0;
	for (auto x: smaller){
		curr+=x.nd;
		if (x.st < curr){
			cout << "NO\n";
			return;
		}
	}
	curr = 0;
	for (auto x: bigger){
		curr += x.nd;
		if (n+x.st+1 < curr){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
