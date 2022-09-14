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
	
	void init(vector<int>&a){
		size = 1;
		int n = a.size();
		tab.clear();
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		for (int i = 0; i<n; i++) tab[i+size] = a[i];
		for (int i = size-1; i>0; i--) tab[i] = __gcd(tab[2*i], tab[2*i+1]);
	}
	
	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans = __gcd(ans, tab[l+1]);
			if (r&1) ans = __gcd(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
	
};

segtree seg;

bool warunek(int m, int n){
	for (int i = 0; i<n; i++){
		if (i+m<n){
			if (seg.query(i, i+m)>1) return 0; 
		} else {
			if (__gcd(seg.query(i, n-1), seg.query(0, (i+m)%n)) >1) return 0;
		}
	}
	return 1;
}

void solve(){
	int n, nwd = 0;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		nwd = __gcd(nwd, a[i]);
	}
	for (int i = 0; i<n; i++){
		a[i]/=nwd;
	}
	seg.init(a);
	
	int start = 0, koniec = n, ans = n;
	while (koniec >= start){
		int m = (start+koniec)/2;
		if (warunek(m, n)){
			ans = m;
			koniec = m-1;
		} else start = m+1;
	}
	cout << ans << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
