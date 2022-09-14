#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define LD long double
#define debug(x) cerr << x << " "
struct point{
	LD x,y;
	point() {}
	point(LL x, LL y): x(x), y(y) {}
	point& operator-=(const point &t){
		x-=t.x;
		y-=t.y;
		return *this;
	}
};
vector <point> tab;

LD iloczyn(point a, point b){
	return a.x*b.y - a.y*b.x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LD a, b;
	int n;
	cin >> n >> a >> b;
	point zero(a,b);
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		point curr(a, b);
		curr-=zero;
		tab.push_back(curr);
	}
	LD suma = 0, ilo;
	reverse(tab.begin(), tab.end());
	for (int i = 1; i<tab.size(); i++){
		ilo = iloczyn(tab[i-1], tab[i])/2;
		suma += ilo;
		//debug(suma);
	}
	if (suma == floor(suma)) cout << (LL)suma << "\n";
	else cout << fixed << setprecision(1) << suma << "\n"; 
	return 0;
}
