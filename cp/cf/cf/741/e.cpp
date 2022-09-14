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

vi suffix_array(string s, int n){
	vector<pair<char, int>>a(n);
	rep(i, 0, n) a[i] = {s[i], i};
	sort(all(a));
	vi p(n), c(n);
	//k = 0;
	rep(i, 0, n) p[i] = a[i].nd;
	
	c[p[0]] = 0;
	rep(i, 1, n){
		c[p[i]] = c[p[i-1]];
		if (a[i].st != a[i-1].st) c[p[i]]++;
	}
	
	int k = 0;
	while ((1<<k)<n){
		vector<pair<pii, int>>a(n);
		rep(i, 0, n) a[i] = {{c[i], c[(i+(1<<k))%n]}, i};
		sort(all(a));
		
		rep(i, 0, n) p[i] = a[i].nd;
	
		c[p[0]] = 0;
		rep(i, 1, n){
			c[p[i]] = c[p[i-1]];
			if (a[i].st != a[i-1].st) c[p[i]]++;
		}
		
		k++;
	}
	return p;
}

vi LCP(string s, vi p){
	int n = sz(s);
	vi rank(n, 0), lcp(n, 0);
	rep(i, 0, n) rank[p[i]] = i;
	int k = 0;
	rep(i, 0, n){
		if (rank[i] == n-1){
			k = 0;
			continue;
		}
		int j = p[rank[i]+1];
		while (i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
		lcp[rank[i]] = k;
		if (k) k--;
	}
	return lcp;
}


struct segtree{
	vi tab;
	int size = 1;
	
	void init(int n, vi lcp){
		while (size < n) size*=2;
		tab.assign(2*size+1, INT_MAX);
		rep(i, 0, sz(lcp)) tab[i+size] = lcp[i];
		repd(i, size-1, 1) tab[i] = min(tab[2*i], tab[2*i+1]);
	}
	
	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = INT_MAX;
		while (r-l>1){
			if (!(l&1)) ans = min(ans, tab[l+1]);
			if (r&1) ans = min(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	s+=(char)('z'+1);n++;
	vi p = suffix_array(s, n);
	vi lcp = LCP(s, p);
	segtree seg;
	seg.init(n+1, lcp);
	vi c(n);
	
	/*
	for (auto x: p) debug(x);
	cerr << "\n";
	for (auto x: lcp) debug(x);
	cerr << "\n";
	for (auto x: c) debug(x);
	cerr << "\n";
	return;
	*/
	vll dp(n);
	rep(i, 0, n) c[p[i]] = i;
	
	rep(i, 0, n){
		dp[i] = n-i-1;
		rep(j, 0, i){
			if (c[j]<c[i]) dp[i] = max(dp[i], dp[j]+n-i-1-seg.query(c[j], c[i]-1));
		}
		//debug(dp[i]);
	}
	//cerr << "\n";
	LL ans = 0;
	rep(i, 0, n) ans = max(ans, dp[i]);
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
