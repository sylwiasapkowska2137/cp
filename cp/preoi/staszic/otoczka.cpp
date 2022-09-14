#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

struct point{
	LL x, y;
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
	point& operator = (const point &t){
		x = t.x;
		y = t.y;
		return *this; 
	}
};

vector <point> tab;

bool cmp(point a, point b){
	if (a.y == b.y) return (a.x < b.x);
	return (a.y < b.y);
}

LL il(point a, point b, point c){
	return (b.x-a.x)*(c.y-a.y)*(b.y-a.y)*(c.x-a.x);
}

LL iloczyn(point a, point b){
	return a.x*b.y-a.y*b.x;
}

bool cmp2(point a, point b){
	LL ilo = iloczyn(a, b);
	if (ilo == 0){
		LD o1 = a.x*a.x+a.y*a.y;
		LD o2 = b.x*b.x+b.y*b.y;
		return (o1<o2);
	}
	return (ilo > 0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	LD x,y;
	for (int i = 0; i<n; i++){
		cin >> x >> y;
		tab.pb({x, y});
	}
	sort(tab.begin(), tab.end(), cmp);
	point zero = tab[0];
	for (int i = 0; i<n; i++) tab[i]-=zero;
	sort(tab.begin(), tab.end(), cmp2);
	
	return 0;
}
