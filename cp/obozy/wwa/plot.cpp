#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define ok if (1)

struct query{
	char type;
	int a, b;
};
map<int,int>mapa;

struct suma{
	vector<LL>tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0LL);
	}
	
	LL q(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = 0LL;
		while(r-l>1){
			if (!(l&1)) ans+=tab[l+1];
			if (r&1) ans+=tab[r-1];
			l/=2;r/=2;
		} 
		return ans;
	}
	
	void update(int pos, int val){
		pos+=size;
		tab[pos] += val;
		while (pos){
			pos/=2;
			tab[pos] = tab[pos*2] + tab[2*pos+1];
		}
	}
	
};

struct maxi{
	vector<LL>tab;
	int size = 1;
	
	void init(int n){
		while (size < n) size*=2;
		tab.assign(2*size+1, 0LL);
	}
	
	LL q(int l, int r){
		l = l+size-1;
		r = r+size+1;
		LL ans = 0LL;
		while(r-l>1){
			if (!(l&1)) ans=max(ans, tab[l+1]);
			if (r&1) ans=max(tab[r-1], ans);
			l/=2;r/=2;
		} 
		return ans;
	}
	
	void update(int pos, int val){
		pos+=size;
		tab[pos] += val;
		while (pos){
			pos/=2;
			tab[pos] = max(tab[pos*2], tab[2*pos+1]);
		}
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<query>a(n);
	vector<int>liczby;
	for (int i = 0; i<n; i++){
		cin >> a[i].type >> a[i].a >> a[i].b;
		if (a[i].type == 'D') liczby.pb(a[i].a);
	}
	sort(liczby.begin(), liczby.end());
	liczby.erase(unique(liczby.begin(), liczby.end()), liczby.end());
	//for (auto x: liczby) debug(x);
	for (int i = 0; i<(int)liczby.size(); i++) mapa[liczby[i]] = i;
	suma SUMA;
	maxi MAX;
	SUMA.init(liczby.size()+1);
	MAX.init(liczby.size()+1);
	for (int i = 0; i<n; i++){
		if (a[i].type == 'Z'){
			//1. indeks elementu mniejszego o sumie pref mniejszej równej A
			//2. indeks elementu wiekszego 
			//
		} else{
			if (a[i].type == 'U') a[i].b = -a[i].b;
			SUMA.update(mapa[a[i].a], a[i].b);
			MAX.update(mapa[a[i].a], a[i].b);
		}
	}
	return 0;
}
