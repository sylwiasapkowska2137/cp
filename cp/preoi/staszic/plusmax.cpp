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

//dzrewo przedzial-przaedzial (+, max) - dodaj wartosc na przedziale, odczytaj max z przedzialu

struct segtree{
	int size = 1;
	vector <int> tab, sub;
	
	void init(int n){
		while (size<n) size <<= 1;
		tab.assign(2*size+1, 0);
		sub.assign(2*size+1, 0);
	}
	
	void insert(int l, int r, int val){
		l+=size;
		r+=size;
		//int len = 1;
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
					sub[l+1]+=val;
				}
				if (r&1){
					tab[r-1]+=val;
					sub[r-1]+=val;
				}
			}
			if (r < size){
				sub[l] = max(sub[l<<1], sub[l<<1|1]) + tab[l];
				sub[r] = max(sub[r<<1], sub[r<<1|1]) + tab[r];
			}
			l/=2;
			r/=2;
			//len*=2;
		}
	}
	
	int query(int l, int r){
		l+=size-1;
		r+=size+1;
		int res = 0;
		while (l>0){
			res = max(res, (tab[l], tab[r]));
			if (r-l>1){
				if (!(l&1)){
					res = max(res, sub[l+1]);
				}
				if (r&1){
					res = max(res, sub[r-1]);
				}
			}
			l/=2;
			r/=2;
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
			cout << seg.query(a, b) << "\n";
		}
	}
	return 0;
}
