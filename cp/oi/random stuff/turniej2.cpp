#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
int n, p;
const int MAX = 5e5+8;
int tab[4][MAX];
vector<int>indeks, hamilton, lewo, numer;

bool win(int a, int b){ //czy a wygrywa moralnie z b?
	int val = 0;
	if (tab[1][b]>tab[1][a]) val++;
	if (tab[2][b]>tab[2][a]) val++;
	if (tab[3][b]>tab[3][a]) val++;
	if (val>=2) return 1;
	return 0;
}

bool cmp(int a, int b){
	return tab[p][a] > tab[p][b];
}

vector<int> dziel(int a = 1, int b = n){
	if (a == b) return {a};
	if (b-a == 1){
		if (win(a, b)) return {a, b};
		else return {b, a};
	}
	int m = (a+b)/2;
	vector<int>x = dziel(a, m);
	vector<int>y = dziel(m+1, b);
	int px = 0, py = 0;
	vector<int>ans;
	while (px < x.size() && py < y.size()){
		if (win(x[px], y[py])) {
			ans.pb(x[px]); 
			px++;
		} else {
			ans.pb(y[py]);
			py++;
		}
	}
	while (px < x.size()){
		ans.pb(x[px]);
		px++;
	}
	while (py < y.size()){
		ans.pb(y[py]);
		py++;
	}
	x.clear();
	y.clear();
	return ans;
}

struct segtree{
	int size = 1;
	vector<int>t;
	
	void init(int n){
		while (size < n) size*=2;
		t.assign(2*size+1, INT_MAX);
	}
	
	void clear(){
		t.assign(2*size+1, INT_MAX);
	}
	
	void set(int val, int pos){
		pos += size;
		t[pos] = val;
		while (pos > 0){
			pos/=2;
			t[pos] = min(t[2*pos], t[2*pos+1]);
		}
	}
	
	
	int query(int a, int b){
		a = a+size-1;
		b = b+size+1;
		int ans = INT_MAX;
		while (b-a>1){
			if (!(a&1)) ans = min(ans, t[a+1]);
			if (b&1) ans = min(ans, t[b-1]);
			a/=2;
			b/=2;
		}
		return ans;
	}
	
} seg;

void scc(){
	numer.assign(n+1, 0);
	int nalewo = n, nr = 1;
	for (int i = n; i>=1; i--){
		numer[hamilton[i-1]] = nr;
		nalewo = min(nalewo, lewo[i]);
		if (nalewo>=i) nr++;
	}
}


void krawedzie(int y, int z){
	p = z;
	vector<int>tmp;
	for (int i = 0; i<n; i++) tmp.pb(i+1);
	sort(tmp.begin(), tmp.end(), cmp);
	//for (auto x: tmp) debug(x);
	//cerr << "\n";
	for (int i = 0; i<tmp.size(); i++) tmp[i] = indeks[tmp[i]];
	//for (auto x: tmp) debug(x);
	//cerr << "\n";
	seg.clear();
	for (int i = 0; i<tmp.size(); i++){
		lewo[tmp[i]] = min(lewo[tmp[i]], seg.query(tab[y][hamilton[tmp[i]-1]], n));
		seg.set(tmp[i], tab[y][hamilton[tmp[i]-1]]);
	}
	//for (int i = 1; i<=n; i++) debug(lewo[i]);
	//cerr << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int q, a, b;
	cin >> n;
	seg.init(n+1);
	indeks.resize(n+1);
	lewo.assign(n+1, INT_MAX);
	for (int i = 1; i<=n; i++) cin >> tab[1][i];
	for (int i = 1; i<=n; i++) cin >> tab[2][i];
	for (int i = 1; i<=n; i++) cin >> tab[3][i];
	hamilton = dziel();
	for (int i = 0; i<(int)hamilton.size(); i++) indeks[hamilton[i]] = i+1;
	//for (auto x: hamilton) debug(x);
	//cerr << "\n";
	//for (int i = 1; i<(int)indeks.size(); i++) debug(indeks[i]);
	//cerr << "\n\n";
	krawedzie(1, 2);
	krawedzie(2, 3);
	krawedzie(3, 1);
	for (int i = 1; i<=n; i++){
		lewo[i] = min(lewo[i], i);
		//debug(lewo[i]);
	}
	//cerr << "\n";
	scc();
	//for (int i = 1; i<=n; i++) debug(numer[i]);
	cin >> q;
	while (q--){
		cin >> a >> b;
		if (win(a, b) || numer[a]==numer[b]) cout << "TAK\n";
		else cout << "NIE\n";
	}
	return 0;
}
