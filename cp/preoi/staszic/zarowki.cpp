#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct segtree{
	int size = 1;
	vector <int> tab;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size, 0);
	}
	
	void build(vector <bool> a){
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = (int)a[i];
		//for (int i = size-1; i>0; i--) tab[i] = tab[i<<1]+tab[i<<1|1];
	}

	void add(int l, int r){
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) tab[l+1]++;
			if (r&1) tab[r-1]++;
			r/=2;
			l/=2;
		}
	}

	int query(int pos){
		pos = pos+size-1;
		int res = tab[pos];
		while (pos>0){
			pos/=2;
			res+=tab[pos];
		}
		return res;
	}
	
	
};

int main(){
	fastio;
	int n, q, pos, l, r;
	cin >> n >> q;
	string s, t;
	cin >> s;
	vector <bool> arr(n, 0);
	for (int i = 0; i<n; i++){
		if (s[i]=='o') arr[i] = 1; 
	}
	segtree seg;
	seg.init(n);
	seg.build(arr);
	//for (auto x: seg.tab) debug(x);
	//cerr << "\n";
	while (q--){
		cin >> t;
		if (t[0]=='Q'){
			cin >> pos;
			if (seg.query(pos)%2 == 1) cout << "ON\n";
			else cout << "OFF\n";
		} else {
			cin >> l >> r;
			seg.add(l-1, r-1);
			//for (auto x: seg.tab) debug(x);
			//cerr << "\n";
		}
	}
	return 0;
}
