//https://szkopul.edu.pl/c/oki-dla-zaawansowanych/p/mur/
#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "

const int MAX = 1e5+7;

struct point{
	LL x, y;
	point() {}
	point(LL x, LL y): x(x), y(y) {}
	point& operator +=(const point &t){
		x+=t.x;
		y+=t.y;
		return *this;
	}
	point& operator +(const point &t){
		return point(*this)+=t;
	}
	point& operator -=(const point &t){
		x-=t.x;
		y-=t.y;
		return *this;
	}
	point& operator -(const point &t){
		return point(*this)-=t;
	}
	point& operator *=(const point &t){
		x*=t.x;
		y*=t.y;
		return *this;
	}
	point& operator *(const point &t){
		return point(*this)*=t;
	}
	point& operator /= (const point &t){
		x/=t.x;
		y/=t.y;
		return *this;
	}
	point& operator / (const point &t){
		return point(*this)/=t;
	}
	point& operator = (const point &t){
		x = t.x;
		y = t.y;
		return *this;
	}
} tab[MAX];

LL iloczyn(point a, point b){
	return a.x*b.y - a.y*b.x;
}

void solve(){
	int n;
	LL x, y, ilo;
	cin >> n >> x >> y;
	bool zgodnie, now;
	point zero(x, y);
	for (int i = 0; i<n; i++){
		cin >> tab[i].x >> tab[i].y;
		tab[i] -= zero;
	}
	for (int i = 0; i<n; i++){
		if (i == 0) {
			ilo = iloczyn(tab[n-1], tab[0]);
			zgodnie = (ilo >= 0) ? false : true;
		} else { 
			ilo = iloczyn(tab[i-1], tab[i]);
			now = (ilo >= 0) ? false : true;
			if (now != zgodnie) {
				cout << "NIE\n";
				return;
			}
		}
	}
	cout << "TAK\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
