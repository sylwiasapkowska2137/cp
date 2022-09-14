#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct point{
	LL x, y;
	point(LL x, LL y): x(x), y(y) {}
	point& operator += (const point &t){
		x+=t.x;
		y+=t.y;
		return *this;
	}
	point& operator -= (const point &t){
		x-=t.x;
		y-=t.y;
		return *this;
	}
};

LL iloczyn(point a, point b){
	return a.x*b.y-a.y*b.x;
}

bool cmp(point a, point b){
	LL ilo = iloczyn(a, b);
	if (ilo == 0){
		LD o1 = a.x*a.x+a.y*a.y;
		LD o2 = b.x*b.x+b.y*b.y;
		return (o1<o2);
	}
	return (ilo > 0);
}

bool cmp2(point a, point b){
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int main(){
	fastio;
	cout << fixed << setprecision(0);
	int n; 
	LL x,y;
	cin >> n;
	vector <point> tab;
	for (int i = 0; i<n; i++){
		cin >> x >> y;
		tab.pb({x, y});
	}
	sort(tab.begin(), tab.end(), cmp2);
	point zero = tab[0];
	for (int i = 0; i<n; i++) tab[i]-=zero;
	sort(tab.begin(), tab.end(), cmp);
	for (int i = 0; i<n; i++){
		tab[i]+=zero;
		cout << tab[i].x << " " << tab[i].y << "\n";
	}
	return 0;
}
