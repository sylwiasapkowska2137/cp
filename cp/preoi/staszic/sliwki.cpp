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

struct segtree{
	int size = 1;
	vector <int> tab;
	vector <vector <int> > k;
	
	void init(int n){
		while (size<n) size*=2;
		tab.assign(2*size+1, 0);
		k.resize(2*size+1);
		for (int i = 0; i<=2*size; i++) k[i].assign(6, 0);
	}
	
	void add(int pos, int val){
		pos = pos+size-1;
		tab[pos]+=val;
		for (int i = 1; i<=5; i++) {
			if (tab[pos] % i == 0) k[pos][i] = 1;
			else k[pos][i] = 0;
		}
		while(pos>1){
			pos/=2;
			tab[pos] = tab[pos<<1]+tab[pos<<1|1];
			for (int i = 1; i<=5; i++) {
				k[pos][i] = k[pos<<1][i] + k[pos<<1|1][i];
			}
		}
	}
	
	int query(int l, int r, int ka){
		l = l+size-1;
		r = r+size+1;
		int res = 0;
		while (r-l>1){
			if (!(l&1)) res+=k[l+1][ka];
			if (r&1) res+=k[r-1][ka];
			r/=2;
			l/=2;
		}
		return res;
	}
};

int main(){
	fastio;
	int n, q, pos, val, l, r, k;
	string t;
	cin >> n >> q;
	segtree seg;
	seg.init(n);
	for (int i = 0; i<n; i++)seg.add(i+1, 0);
	while (q--){
		cin >> t;
		if (t[0]=='D'){
			cin >> pos >> val;
			seg.add(pos, val);
		} else {
			cin >> l >> r >> k;
			cout << seg.query(l-1, r-1, k) << "\n";
		}
	}
	return 0;
}
