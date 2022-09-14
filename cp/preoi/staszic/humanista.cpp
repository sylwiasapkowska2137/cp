//https://sio2.staszic.waw.pl/c/algo-sredniozaaw-2020-2021/p/hum/
#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "

struct segtree{
	int size = 1;
	vector <int> tab;
	
	void init(int n){
		while (size < n) size *= 2;
		tab.assign(2*size, 0);
	} 
	
	void build(vector <int> &a){
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>0; i--) tab[i] = tab[i<<1]^tab[i<<1|1];
	}
	
	void set(int pos, int val){
		pos = pos+size-1;
		tab[pos] = val;
		while (pos>1){
			pos/=2;
			tab[pos] = tab[pos<<1]^tab[pos<<1|1];
		}
	}
	
	void swap(int a, int b){
		int posa = tab[a+size-1];
		int posb = tab[b+size-1];
		set(a, posb);
		set(b, posa);
	}
	
	int calc(int l, int r, int x, int lx, int rx){
		if (lx > r || l > rx) return 0;
		if (lx >= l && r >= rx) return tab[x];
		int m = (lx+rx)/2;
		return calc(l,r,2*x,lx,m)^calc(l,r,2*x+1,m+1,rx);
	}
	
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string t;
	int n, q, l, r;
	cin >> n >> q;
	vector <int> a(n);
	for (int i = 0; i<n; i++){
		cin >> a[i];
	}
	segtree seg;
	seg.init(n);
	seg.build(a);
	//for (auto x: seg.tab) debug(x);
	//cerr << "\n";
	while (q--){
		cin >> t >> l >> r;
		if (t[0]=='c'){
			cout << seg.calc(l, r, 1, 1, seg.size) << "\n";
		} else {
			seg.swap(l, r);
			//for (auto x: seg.tab) debug(x);
			//cerr << "\n";
		}
	}
	return 0;
}
