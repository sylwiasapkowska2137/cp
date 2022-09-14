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
	
	void init(int n){
		while (size < n) size *=2;
		tab.assign(2*size, 0);
	}
	
	void build(vector <int>a){
		for (int i = 0; i<(int)a.size(); i++) tab[i+size] = a[i];
		for (int i = size-1; i>0; i--) tab[i] = tab[i<<1]+tab[i<<1|1];
	}
	
	int calc(int a, int b){
		a = a+size-1;
		b = b+size+1;
		int suma = 0;
		while (b-a>1){
			if (!(a&1)) suma += tab[a+1];
			if (b&1) suma+=tab[b-1];
			a/=2;
			b/=2;
		}
		return suma;
	}
	
	void set(int pos, int val){
		pos=pos+size-1;
		tab[pos] = val;
		while (pos>0){
			pos/=2;
			tab[pos]= tab[pos<<1]+tab[pos<<1|1];
		}
	}
};

int main(){
	fastio;
	int n, q, t, a, b;
	cin >> n >> q;
	vector <int> arr(n);
	for (int i = 0; i<n; i++)cin >> arr[i];
	segtree seg;
	seg.init(n);
	seg.build(arr);
	while (q--){
		cin >> t >> a >> b;
		if (t == 0)	seg.set(a, b);
		else cout << seg.calc(a-1, b-1) << "\n";
	}
	return 0;
}
