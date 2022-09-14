#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

struct segtree{
	vector<int>tab;
	int size = 1;
	
	void init(int n, vector<int>&lcp){
		while (size < n) size*=2;
		tab.assign(2*size+1, INT_MAX);
		for (int i = 0; i<(int)lcp.size(); i++) tab[i+size] = lcp[i];
		for (int i = size-1; i>0; i--) tab[i] = min(tab[2*i], tab[2*i+1]);
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


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s;
	cin >> n >> s;
	s+="$";n++;
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
	debug("preprocess");
	cerr << "\n";
	for (auto x: p) debug(x);
	cerr << "\n";
	for (auto x: c) debug(x);
	cerr << "\n";
	
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
		debug("k =");
		debug(k);
		cerr << "\n";
		for (auto x: p) debug(x);
		cerr << "\n";
		for (auto x: c) debug(x);
		cerr << "\n";
		
		k++;
	}
	k = 0;
	vector<int>lcp(n, 0); //lcp[i] = lcp(p[i], p[i+1]);
	
	for (int i = 0; i<n; i++){
		if (c[i] == n-1) {
			k = 0;
			continue;
		}
		int j = p[c[i]+1];
		while (i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
		lcp[c[i]] = k;
		if (k) k--;
	}
	
	debug("lcp:");
	cerr << "\n";
	for (auto x: lcp) debug(x);
	cerr << "\n";
	
	segtree seg;
	seg.init(n, lcp);
	vector<LL>ans(n, 0);
	
	for (int i = 0; i<n; i++){
		for (int j = i; j<n; j++){
			//lcp(p[i], p[j]) = min_i...j-1
			ans[p[i]] += (i == j)? i : seg.query(i, j-1);
		}
	}
	for (auto x: ans) debug(x);
	return 0;
}






