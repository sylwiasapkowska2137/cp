#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

struct segtree{
	vector <LL> operations; //indeksowanie od 1
	vector <LL> mins; 
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		operations.assign(2*size+1, 0LL);
		mins.assign(2*size+1, 0LL);
	}
	
	void add(int l, int r, int val, int x, int lx, int rx){
		if (lx > r || l > rx) return;
		if (lx >= l && r >= rx){
			mins[x]+=(LL)val;
			operations[x]+=(LL)val;
			return;
		}
		int m = (lx+rx)/2;
		add(l, r, val, 2*x, lx, m);
		add(l, r, val, 2*x+1, m+1, rx);
		mins[x] = max(mins[2*x], mins[2*x+1]) + operations[x];
	}
	
	LL query(int l, int r, int x, int lx, int rx){
		if (lx > r || l > rx) return 0;
		if (lx >= l && r >= rx) return mins[x];
		int m = (lx+rx)/2;
		return max(query(l, r, 2*x, lx, m), query(l, r, 2*x+1, m+1, rx)) + operations[x];
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, z, l, r, a;
	cin >> n >> m >> z;
	segtree seg;
	seg.init(n+1);
	for (int i = 0; i<z; i++){
		cin >> l >> r >> a;
		LL maxi = seg.query(l, r-1, 1, 1, seg.size);
		if (m-maxi >= a){
			cout << "T\n";
			seg.add(l, r-1, a, 1, 1, seg.size);
		} else {
			cout << "N\n";
		}
	}
	return 0;
}


