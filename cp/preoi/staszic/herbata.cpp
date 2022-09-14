#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define ULL unsigned LL
#define st first
#define nd second
#define pii pair <int, int>
#define pb push_back
#define debug(x) cerr << x << " "

struct segtree{
	int size = 1;
	vector <LL> tab;
	
	void init(int n){
		while (size < n) size *= 2;
		tab.assign(2*size+2, 0);
	}
	
	void build(vector <LL> &a){
		for (int i = 1; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>0; i--) tab[i] = tab[i*2]+tab[i*2+1];
	}
	
	void update(int pos, LL val){
		pos+=size;
		while (pos>0){
			tab[pos] += val;
			pos/=2; 
		}
	}
	
	LL sum(int l, int r, int x, int lx, int rx){
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && r >= rx) return tab[x];
		int m = (lx+rx)/2;
		return sum(l, r, 2*x, lx, m) + sum(l, r, 2*x+1, m, rx);
    }
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	
	int n, q, a, b, type;
	cin >> n >> q;
	segtree st, sq;
	st.init(n);
	sq.init(n);
	vector <LL> ar(n+1, 0), square(n+1, 0);
	for (int i = 1; i<=n; i++) {
		cin >> ar[i];
		square[i] = ar[i]*ar[i];
	}
	st.build(ar);
	sq.build(square);
	while (q--){
		cin >> type >> a >> b;
		if (type == 0)	{
			st.update(a, b-st.tab[a+st.size]);
			LL val = st.tab[a+st.size];
			sq.update(a, val*val-sq.tab[a+sq.size]);
		}
		else {
			LL u = st.sum(a, b+1, 1, 1, st.size);
			LL v = sq.sum(a, b+1, 1, 1, sq.size);
			cout << (u*u-v)/2 << "\n";
		}
	}
	return 0;
}
