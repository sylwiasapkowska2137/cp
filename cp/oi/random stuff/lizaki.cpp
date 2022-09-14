#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 1037;
int val[2][MAX]; //waniliowe = 1, truskawkowe = 0
bool typ[2][MAX];
int n[2], ans = 0;
struct prostokat{int w2, w, t2, t;};
vector<prostokat>rec[2];
struct a{int w2,w,t,typ;}; //1 - poczatek prostokąta, -1 koniec prostokata, 0 - punkt
struct b{int w2,w,t2,t,typ;}; //1 - początek pionowego, -1 koniec pionowego, 0 - odcinek poziomy
pii pref[2][MAX];
multiset<int>wartosci;

void wczytaj(int k){
	char t;
	cin >> n[k];
	for (int i = 1; i<=n[k]; i++){
		cin >> t >> val[k][i];
		if (t == 'W') typ[k][i] = 1;
		else typ[k][i] = 0;
	}
}

void sumy(int k){
	pref[k][0] = {0,0};
	for (int i = 1; i<=n[k]; i++){
		pref[k][i] = pref[k][i-1];
		if (typ[k][i]) pref[k][i].st += val[k][i];
		else pref[k][i].nd += val[k][i];
	}
	for (int i = 1; i<=n[k]; i++){
		for (int j = i; j<=n[k]; j++){
			int w = pref[k][j].st-pref[k][i-1].st;
			int t = pref[k][j].nd-pref[k][i-1].nd;
			int w2 = w;
			int t2 = t;
			if (typ[k][i]) w2-=val[k][i];
			else t2-=val[k][i];
			if (i!=j){
				if (typ[k][j]) w2-=val[k][j];
				else t2 -=val[k][j];
			}
			//cerr << i << " " << j << ": " << w2 << " ≤ w ≤ " << w << " " << t2 << " ≤ t ≤ " << t << "\n";
			rec[k].pb({w2,w,t2,t});
		}
	}
	//cerr << "\n";
}

bool cmp(a x, a y){
	if (x.t == y.t)	return x.typ > y.typ;
	return x.t < y.t;
}

struct segtree{
	int size = 1;
	vector<int>tab;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0);
	}
	
	void update(int l, int r, int val){
		l = l+size-1;
		r = r+size+1;
		while (r-l>1){
			if (!(l&1)) tab[l+1]+=val;
			if (r&1) tab[r-1]+=val;
			l/=2;
			r/=2;
		}
	}
	
	int query(int pos){
		pos+=size;
		int ans = 0;
		while (pos>0){
			ans += tab[pos];
			pos/=2;
		}
		return ans;
	}
} seg;

void first(int k){
	int l = k^1, size = 1;
	vector<a>tmp;
	for (int i = 0; i<rec[k].size(); i++){
		tmp.pb({rec[k][i].w2, rec[k][i].w, rec[k][i].t2, 1});
		tmp.pb({rec[k][i].w2, rec[k][i].w, rec[k][i].t, -1});
		size = max(size, rec[k][i].w);
	}
	for (int i = 0; i<rec[l].size(); i++){
		tmp.pb({rec[l][i].w, rec[l][i].w, rec[l][i].t, 0});
		size = max(size, rec[l][i].w);
	}
	seg.init(size+1);
	sort(tmp.begin(), tmp.end(), cmp);
	for (auto x: tmp){
		if (x.typ == 0){
			if (seg.query(x.w)>0) {
				ans = max(ans, x.w+x.t);
				//debug(x.w);
				//debug(x.t);
				//cerr << "\n";
			}
		} else {
			seg.update(x.w2, x.w, x.typ);
		}
	}
}

struct segment{
	int size = 1;
	vector<int>tab;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0); 
	}
	
	int suma(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans += tab[l+1];
			if (r&1) ans += tab[r-1];
			l/=2;
			r/=2;
		}
		return ans;
	}
	
	void update(int pos, int val){
		pos += size;
		tab[pos]+=val;
		while (pos>0){
			pos/=2;
			tab[pos]=tab[2*pos]+tab[2*pos+1];
		}
	}
}drzewo;

void second(int k){
	int l = k^1, size = 1;
	vector<b>tmp;
	for (int i = 0; i<(int)rec[k].size(); i++){//dodajemy pionowe odcinki
		tmp.pb({rec[k][i].w, rec[k][i].w, rec[k][i].t2, rec[k][i].t2, 1});
		tmp.pb({rec[k][i].w, rec[k][i].w, rec[k][i].t, rec[k][i].t, -1});
		size = max(size, rec[k][i].w);
	}
	for (int i = 0; i<(int)rec[l].size(); i++){//poziome odcinki
		tmp.pb({rec[l][i].w2, rec[l][i].w, rec[l][i].t, rec[l][i].t, 0});
		size = max(size, rec[l][i].w);
	}
	drzewo.init(size+1);
	sort(tmp.begin(), tmp.end(), cmp);
	for (auto x: tmp){
		if (x.typ == 0){
			if (drzewo.suma(x.w2, x.w)>0){
				
			}
		} else {
			seg.update(x.w, x.typ);
			if (x.typ == 1) wartosci.insert(-x.w);
			else {
				auto it = wartosci.lower_bound(-x.w);
				
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	
	wczytaj(0);
	wczytaj(1);
	
	sumy(0);
	sumy(1);
	
	first(0);
	first(1);

	second(0);
	second(1);
	
	cout << ans << "\n";
	return 0;
}
