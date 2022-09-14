//https://szkopul.edu.pl/problemset/problem/ocGBMr4-sFMy6iEUQ6cZ6gNW/site/?key=statement
#include <bits/stdc++.h>

using namespace std;
#define LD long double
#define LL long long
#define debug(x) cerr << x << " "
struct point{
	LD odleglosc;
	int abonament;
};
vector <point> tab;


bool cmp(point a, point b){
	return (a.odleglosc < b.odleglosc);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LD x,y, maxi, a, tmp;
	int n, k, m;
	cin >> n >> k;
	tab.resize(n);
	for (int i = 0; i<n; i++){
		maxi = 0.0;
		cin >> m >> tab[i].abonament;
		for (int j = 0; j<m; j++){
			cin >> x >> y;
			tmp = x*x+y*y;
			//debug(tmp);
			maxi = max(maxi, sqrt(tmp));
		}
		tab[i].odleglosc = max(tab[i].odleglosc, maxi);
	}
	LL res = 0, suma = 0, zasieg, koszt;
	sort(tab.begin(), tab.end(), cmp);
	for (auto x: tab){
		x.odleglosc = ceil(x.odleglosc);
		debug(x.odleglosc);
		debug(x.abonament);
		cerr << "\n";
		
	}
	return 0;
}
