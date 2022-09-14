#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int,int>
#define st first
#define nd second
#define pb push_back

struct Horizontal{//poziomy
	int x1, x2, y;
	Horizontal() {}
	Horizontal(int x1, int x2, int y): x1(x1), x2(x2), y(y) {} 
};

struct Vertical{//pionowy
	int y1, y2, x;
	Vertical() {}
	Vertical(int y1, int y2, int x): y1(y1), y2(y2), x(x) {} 
};

struct Line{
	int x1, x2, y, add; //add: 1 gdy poziomy, 0 gdy pionowy i poczatek, 2 gdy pionowy i koniec
	Line(){}
	Line(int x1, int x2, int y, int add): x1(x1), x2(x2), y(y), add(add){}
};

vector<Horizontal>HorizontalLines;
vector<Vertical>VerticalLines;

bool cmp(Line a, Line b){
	if (a.y == b.y) return a.add < b.add;
	return a.y < b.y;
}

struct segtree{
	int size = (1<<19);
	vector<int>tab;
	
	void init(){
		tab.assign(2*size+1, 0);
	}
	
	int suma(int l, int r){
		l = l+size-1;
		r = r+size+1;
		int ans = 0;
		while (r-l>1){
			if (!(l&1)) ans+=tab[l+1];
			if (r&1) ans+=tab[r-1];
			l/=2;r/=2;
		}
		return ans;
	}
	
	void update(int pos, int val){
		pos+=size;
		tab[pos]+=val;
		while (pos>0){
			pos/=2;
			tab[pos] = tab[2*pos]+tab[2*pos+1];
		}
	}
	
} seg;

bool warunek(int m){
	//skracamy kazdy odcinek z dwóch stron o m
	vector<Line>tab;
	vector<int>scaler;
	for (auto x: HorizontalLines){
		if (x.x1+m <= x.x2-m) {
			tab.pb({x.x1+m, x.x2-m, x.y, 1});
			scaler.pb(x.x1+m);
			scaler.pb(x.x2-m);
		}
	}
	for (auto x: VerticalLines){
		if (x.y1+m <= x.y2-m) {
			tab.pb({x.x, x.x, x.y1+m, 0});
			tab.pb({x.x, x.x, x.y2-m, 2});
			scaler.pb(x.x);
		}
	}
	sort(tab.begin(), tab.end(), cmp);
	sort(scaler.begin(), scaler.end());
	scaler.erase(unique(scaler.begin(), scaler.end()), scaler.end());
	seg.init();
	
	map<int, int>mapa;
	
	for (int i = 0; i<(int)scaler.size(); i++) mapa[scaler[i]] = i;
	
	for (auto x: tab){
		if (x.add == 1){
			int t = seg.suma(mapa[x.x1], mapa[x.x2]);
			if (t > 0) return 1;
		} else if (!x.add)seg.update(mapa[x.x1], 1);
		else seg.update(mapa[x.x1], -1);
	}
	return 0;
}

int binsearch(int start, int koniec){
	int ans = 0;
	while (koniec > start){
		int m = (start+koniec)/2;
		if (warunek(m)){
			start = m+1;
			ans = m;
		} else koniec = m-1;
	}
	if (warunek(start))ans++;
	return ans;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	HorizontalLines.resize(n);
	VerticalLines.resize(m);
	
	for (int i = 0; i<n; i++) {
		cin >> HorizontalLines[i].x1 >> HorizontalLines[i].x2 >> HorizontalLines[i].y;
	}
	for (int i = 0; i<m; i++) {
		cin >> VerticalLines[i].y1 >> VerticalLines[i].y2 >> VerticalLines[i].x;
	}
	cout << binsearch(1, 1e9) << "\n";
	return 0;
}
