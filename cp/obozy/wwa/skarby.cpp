#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

struct elem{
	int x, y, w;
	elem(){}
	elem(int x, int y, int w): x(x), y(y), w(w) {}
};

map<int, LL>wiersz, kolumna;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x, y, w;
	cin >> n;
	vector<elem>Points(n);
	set<pii>s;
	for (int i = 0; i<n; i++){
		cin >> Points[i].x >> Points[i].y >> Points[i].w;
		kolumna[Points[i].x]+=Points[i].w;
		wiersz[Points[i].y]+=Points[i].w;
		s.insert({Points[i].x, Points[i].y});
	}
	
	debug("wiersz");
	cerr << "\n";
	for (auto v: wiersz) {
		debug(v.st);
		debug(v.nd);
		cerr << "\n";
	}
	debug("kolumna");
	cerr << "\n";
	for (auto v: kolumna) {
		debug(v.st);
		debug(v.nd);
		cerr << "\n";
	}
	
	
	return 0;
}



