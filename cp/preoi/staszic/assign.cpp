#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "

struct segtree{
	vector <int> tab;
	int size = 1;
	int log;
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size, -1);
		log = log2((double)size);
	}
	
	void propagate(int v){
		if (tab[v]!= -1){
			tab[2*v] = tab[v];
			tab[2*v+1] = tab[v];
			tab[v] = -1; 
		}
	}
	
	void update(int l, int r, int val){
		l = l+size;
		r = r+size;
		for (int i = log; i>=1; i--){
			propagate(l/(1<<i));
			propagate(r/(1<<i));
		}
		tab[l] = val;
		tab[r] = val;
		while (l/2 != r/2){
			if (!(l&1)) tab[l+1] = val;
			if (r&1) tab[r-1] = val;
			r/=2;
			l/=2;
		}
	}
	
	int query(int pos){
		pos+=size;
		int res = 0;
		while (pos > 0){
			if (tab[pos]!=-1) res = tab[pos];
			pos/=2;
		}
		return res;
	}
};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, q, t, l, r, v, i;
	cin >> n >> q;
	segtree seg;
	seg.init(n);
	while (q--){
		cin >> t;
		if (t == 1){
			cin >> l >> r >> v;
			seg.update(l, r-1, v);
			//for (auto x: seg.tab) debug(x);
			//cerr << "\n";
		} else {
			cin >> i;
			cout << (seg.query(i)) << "\n";
		}
	}	
	return 0;
}
