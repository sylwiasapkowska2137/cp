#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

//drzewo przedzialowe przedzial-przedzial (+, +), dodaj wartosc na przedziale, odczytaj sumę z przedzialu

struct segtree{
	int size = 1;
	vector <int> tab, sub;
	
	void init(int n){
		while (size < n) size *=2;
		tab.assign(2*size+1, 0);
		sub.assign(2*size+1, 0);
	}
	
	void insert(int l, int r, int val){
		l+=size;
		r+=size;
		int len = 1;
		tab[l]+=val;
		sub[l]+=val;
		if (l!=r){
			tab[r]+=val;
			sub[r]+=val;
		}
		while (l>0){
			if (r-l>1){
				if (!(l&1)){
					tab[l+1]+=val;
					sub[l+1]+=(val*len);
				}
				if (r&1){
					tab[r-1]+=val;
					sub[r-1]+=(val*len);
				}
			}
			if (r < size){
				sub[l] = sub[l<<1]+sub[l<<1|1] + tab[l]*len;
				sub[r] = sub[r<<1]+sub[r<<1|1] + tab[r]*len;
			}
			l/=2;
			r/=2;
			len*=2;
		}
	}
	
	int suma(int l, int r){
		l+=size;
		r+=size;
		int len = 1, llen = 1, res = 0;
		int rlen = (l!=r ? 1 : 0);
		while (l>0){
			res += (llen*tab[l]) + (rlen*tab[r]);
			if (r-l>1){
				if (!(l&1)){
					res+=sub[l+1];
					llen+=len;
				}
				if (r&1){
					res+=sub[r-1];
					rlen+=len;
				}
			}
			l/=2;
			r/=2;
			len*=2;
		}
		return res;
	}
};

int main(){
	fastio;
	int n, q, t, a, b, val;
	cin >> n >> q;
	segtree seg;
	seg.init(n);
	while (q--){
		cin >> t;
		if (t == 0){ 
			cin >> a >> b >> val;
			seg.insert(a, b, val);
			for (auto x: seg.tab) debug(x);
			cerr << "\n";
		} else {
			cin >> a >> b;
			cout << seg.suma(a, b) << "\n";
		}
	}
	return 0;
}
