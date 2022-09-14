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

vi suffix(string s, int n){
	s+=(char)('z'+1);n++;
	vector<pair<char, int>>a(n);
	for (int i = 0; i<n; i++) a[i] = {s[i], i};
	sort(a.begin(), a.end());
	
	vector<int>p(n), c(n);
	//p[i] - numer cyklicznego podsłowa długości 2^k zaczynającego się w i-tym indeksie
	//c[i] - equivalence class
	//k = 0
	for (int i = 0; i<n; i++) p[i] = a[i].nd;
	c[p[0]] = 0;
	for (int i = 1; i<n; i++){
		c[p[i]] = c[p[i-1]];
		if (a[i].st != a[i-1].st) c[p[i]]++;
	}
	/*
	debug("preprocess");
	cerr << "\n";
	for (auto x: p) debug(x);
	cerr << "\n";
	for (auto x: c) debug(x);
	cerr << "\n";
	*/
	int k = 0;
	while ((1<<k)<n){
		vector<pair<pii, int>>a(n);
		for (int i = 0; i<n; i++) a[i] = {{c[i], c[(i+(1<<k))%n]}, i};
		sort(a.begin(), a.end());
		
		for (int i = 0; i<n; i++) p[i] = a[i].nd;
		c[p[0]] = 0;
		for (int i = 1; i<n; i++){
			c[p[i]] = c[p[i-1]];
			if (a[i].st != a[i-1].st) c[p[i]]++;
		}
		/*
		debug("k =");
		debug(k);
		cerr << "\n";
		for (auto x: p) debug(x);
		cerr << "\n";
		for (auto x: c) debug(x);
		cerr << "\n";
		*/
		k++;
	}
	return p;
}

void solve(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vi p = suffix(s, n);
	bool was = 0;
	int ans = n+1;
	//for (auto x: p) debug(x);
	//cerr << "\n";
	rep(i, 0, n){
		if (was) ans = min(ans, p[i]);
		if (!p[i]) was = 1;
	}
	if (ans < n) s.erase(ans, n);
	int K = k/sz(s);
	rep(i, 0, K) cout << s;
	K = k%sz(s);
	rep(i, 0, K) cout << s[i];
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
