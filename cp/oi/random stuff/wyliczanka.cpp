#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back

//usun zamiana 1 na 0 w lisciu
//ktenastepne(k)
//pozycja(x) ile jest jedynek na lewo ode mnie
//kte(x) znalezc liscia z kta jedynka
//x = kte(pozycja(x)+tab[i])

struct segtree{
	int size = 1;
	vector <int> tab;
	
	void build(int x, int lx, int rx){
		if (rx-lx==1) return;
		int m = (lx+rx)/2;
		build(2*x, lx, m);
		build(2*x+1, m+1, rx);
		tab[x] = tab[x<<1]+tab[x<<1|1];
	}
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 1);
		build(1, 1, size);
	}
	
	void usun(int pos){
		pos+=size;
		tab[pos]--;
		while (pos>0){
			pos/=2;
			tab[pos]--;
		}
	}
	
	int pozycja(int x){
		int l = size-1;
		int r = x+size+1;
		int res = 0;
		while (r-l>1){
			if (!(l&1)) res+=tab[l+1];
			if (r&1) res+=tab[r-1]; 
			l/=2;
			r/=2;
		}
		return res;
	}
	
	int kte(int k, int x, int lx, int rx){
		if (rx - lx == 1) return x;
		int m = (lx+rx)/2;
		if (tab[2*x]>=k) return kte(k, 2*x, lx, m);
		else return kte(k, 2*x+1, m+1, rx);
	}
};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	vector<int>tab(q);
	for (int i = 0; i<q; i++) cin >> tab[i];
	segtree seg;
	seg.init(n);
	int ans = seg.kte(seg.pozycja(-1)+tab[0], 1, 1, seg.size);
	for (int i = 0; i<q; i++){
		debug(seg.pozycja(i-1));
	}
	return 0;
}

