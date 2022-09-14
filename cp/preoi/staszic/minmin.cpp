#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "

struct segtree{
	vector <int> tab, star;
	int size = 1, log;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
		star.assign(2*size, INT_MAX);
		log = log2(double(size));
	}
	
	void propagate(int v){
		tab[2*v] = min(tab[2*v], tab[v]);
		tab[2*v+1] = min(tab[2*v+1], tab[v]);
		tab[v] = INT_MAX;
	}
	
	int query(int l, int r, int val){
		l+=size;
		r+=size;
		int res = INT_MAX;
		for (int i = log; i>=1; i--){
			propagate(l/(1<<i));
			propagate(r/(1<<i));
		}
		tab[l] = min(val, tab[l]);
		tab[r] = min(val, tab[r]);
		while (l > 0){
			if (r - l > 1){
				if (!(l&1)) res = min(res, star[l+1]);
				if (r&1) res = min(res, star[r-1]);
			}
			if (r < size){
				star[l] = min(star[2*l], star[2*l+1]);
				star[r] = min(star[2*r], star[2*r+1]);
			}
			r/=2;
			l/=2;
		}
		return res;
	}
	
	
	
};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	segtree seg;
	seg.init(n);
	while (q--){
		
	}
	return 0;
}
