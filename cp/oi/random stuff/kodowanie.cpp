#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "

struct segtree{
	int size = 1;
	vector <int> tab;
	
	void init(int n){
		while (size < n)size*=2;
		tab.assign(2*size, 1);
		tab[0] = 0;
		for (int i = size-1; i>0; i--) tab[i] = tab[i*2]+tab[i*2+1];
	}
	
	void update(int pos){
		pos = pos+size-1;
		tab[pos] = 0;
		while (pos>1){
			pos/=2;
			tab[pos]--;
		}
	}
	
	int nth(int k, int x, int lx, int rx){
		if (rx == lx) return lx;
		int m = (lx + rx)/2;
		if (tab[2*x] > k) return nth(k, 2*x, lx, m);
		else return nth(k-tab[2*x], 2*x+1, m+1, rx);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, val;
	cin >> n;
	vector <int> a(n), ans;
	segtree seg;
	seg.init(n);
	for (int i = 0; i<n; i++){
		cin >> a[i];
	}
	for (int i = n-1; i>=0; i--){
		if (a[i]>i){
			cout << "NIE\n";
			return 0;
		}
		val = seg.nth(a[i], 1, 1, seg.size);
		ans.push_back(n-val+1);
		seg.update(val);
	}
	reverse(ans.begin(), ans.end());
	for (auto x: ans)cout << x << "\n";
	return 0;
}
