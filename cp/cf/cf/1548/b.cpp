#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

struct segtree{
	vector<LL>tab;
	int size = 1;
	
	void init(int n){
		tab.clear();
		size = 1;
		while (size < n) size*=2;
		tab.assign(2*size+1, 1);
	}
	
	LL query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = 0;
		while (r-l>1){
			if (!(l&1)) ans = __gcd(ans, tab[l+1]);
			if (r&1) ans = __gcd(ans, tab[r-1]);
			l/=2;r/=2;
		}
		return ans;
	}
};

segtree seg;

bool warunek(int len, int n){
	for (int start = 0; start+len<n-1; start++){
		if (seg.query(start, start+len)>1) return 1;
	}
	return 0;
}

void solve(){
	int n;
	LL curr, prev;
	cin >> n >> prev;
	seg.init(n-1);
	for (int i = 0; i<n-1; i++) {
		cin >> curr;
		seg.tab[i+seg.size] = abs(curr-prev);
		prev = curr;
	}
	for (int i = seg.size-1; i>0; i--) seg.tab[i] = __gcd(seg.tab[2*i], seg.tab[2*i+1]);
	int start = 0, koniec = n-1, ans = 0;
	while (koniec >= start){
		int m = (start+koniec)/2;
		if (warunek(m, n)){
			ans = m;
			start = m+1;
		} else koniec = m-1;
	}
	if (warunek(koniec, n))ans++;
	cout << ans+1 << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
