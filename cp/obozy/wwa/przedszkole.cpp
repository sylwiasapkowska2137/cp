#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

struct segtree{
	int size = 1;
	vector<int>tab;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
		for (int i = 1; i<=n; i++) tab[i+size] = 1;
		for (int i = size-1; i>=0; i--){
			tab[i] = tab[2*i]+tab[2*i+1];
		}
	}
	
	int suma(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;r/=2; 
		}
		return ans;
	}
	
	
	void update(int pos){
		pos+=size;
		tab[pos] = 0;
		while (pos>0){
			pos/=2;
			tab[pos] = tab[2*pos]+tab[2*pos+1];
		}
	}
	
	int kth(int x, int lx, int rx, int k){
		//debug(x);
		if (lx == rx) return lx;
		int m = (lx+rx)/2;
		if (k <= tab[2*x]) return kth(2*x, lx, m, k);
		else return kth(2*x+1, m+1, rx, k-tab[2*x]);
	}
	
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	segtree seg;
	seg.init(n);
	int x, t;
	cin >> x;
	seg.update(x);
	cout << x << "\n";
	for (int i = 1; i<q; i++){
		cin >> t;
		int val = (seg.suma(0, x)+t)%(n-i);
		if (!val) val = n-i;
		//cout << val << " ";
		
		x = seg.kth(1, 0, seg.size-1, val);
		seg.update(x);
		cout << x << "\n";
	}
	
	return 0;
}
