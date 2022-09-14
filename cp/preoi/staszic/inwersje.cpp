#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pii pair <int, int>
#define st first
#define nd second
#define pb push_back

struct segtree{
	int size = 1;
	vector <int> tab;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 1);
		for (int i = size-1; i>0; i--) tab[i] = tab[i<<1]+tab[i<<1|1];
	}
	
	int query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int res = 0;
		while (r-l>1){
			if (!(l&1)) res+=tab[l+1];
			if (r&1) res+=tab[r-1];
			l/=2;
			r/=2;
		}
		return res;
	}
	
	void set(int pos){
		pos = pos+size;
		tab[pos] = 0;
		while (pos>1){
			pos/=2;
			tab[pos] = tab[pos<<1]+tab[pos<<1|1];
		}
	}	
};

int main(){
	fastio;
	int n, x, res = 0;
	cin >> n;
	vector <pii> a;
	for (int i = 0; i<n; i++){
		cin >> x;
		a.pb({x,i});
	}
	segtree seg;
	seg.init(n);
	sort(a.begin(), a.end());
	for (int i = 0; i<n; i++){
		res += seg.query(0, a[i].nd-1);
		seg.set(a[i].nd);
	}
	cout << res;
	return 0;
}


