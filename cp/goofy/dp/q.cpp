#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

struct segtree{
	vector<LL>tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0LL);
	}
	
	void update(int pos, LL val){
		pos += size;
		tab[pos] = max(tab[pos], val);
		while (pos > 0){
			pos/=2;
			tab[pos] = max(tab[2*pos], tab[2*pos+1]);
		}
	}
	
	
	LL query(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = 0;
		while (r-l>1){
			if (!(l&1)) ans = max(ans, tab[l+1]);
			if (r&1) ans = max(ans, tab[r-1]);
			l/=2;r/=2; 
		}
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int>h(n+1), a(n+1);
	for (int i = 1; i<=n; i++) cin >> h[i];
	segtree seg;
	seg.init(n+2);
	for (int i = 1; i<=n; i++) cin >> a[i];
	for (int i = 1; i<=n; i++){
		seg.update(h[i], seg.query(0, h[i]-1) + (LL)a[i]);
	}
	cout << seg.query(0, n) << "\n";
	return 0;
}
