//https://szkopul.edu.pl/c/oki-dla-zaawansowanych/p/tro/
#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define LD long double
#define ULL unsigned LL
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

struct point{
	LD x, y;
	point() {}
    point(LD x, LD y): x(x), y(y) {}
	point& operator+=(const point &t){
		x+=t.x;
		y+=t.y;
		return *this;
	}
	point& operator-=(const point &t){
		x-=t.x;
		y-=t.y;
		return *this;
	}
	point& operator*=(const point &t){
		x*=t.x;
		y*=t.y;
		return *this;
	}
	point& operator/=(const point &t){ //dzielenie przez 0
		x/=t.x;
		y/=t.y;
		return *this;
	}
	point& operator + (const point &t){
		return point(*this) += t;
	}
	point& operator - (const point &t){
		return point(*this) -= t;
	}
	point& operator * (const point &t){
		return point(*this) *= t;
	}
	point& operator / (const point &t){
		return point(*this) /= t;
	}
	point& operator = (const point &t){
		x = t.x;
		y = t.y;
		return *this; 
	}
	
};

LD iloczyn(point a, point b){
	return a.x*b.y - a.y*b.x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LD x,y;
	cin >> x >> y;
	point a(x,y);
	cin >> x >> y;
	point b(x, y);
	cin >> x >> y;
	point c(x, y);
	b-=a;
	c-=a;
	LD ilo = iloczyn(b,c);
	if (ilo < 0) cout << "ZGODNIE\n";
	else cout << "PRZECIWNIE\n";
	return 0;
}

