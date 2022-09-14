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
};

int kierunek(point p, point q, point r){
	LD iloczyn = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (iloczyn == 0) return 0;
	else if (iloczyn > 0) return 1;
	else return -1;
}

bool na(point a, point b, point c){
	if (b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) && b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y)) return true;
	return false;
}

bool intersect(point a, point b, point c, point d){
	int o1 = kierunek(a, b, c);
	int o2 = kierunek(a, b, d);
	int o3 = kierunek(c, d, a);
	int o4 = kierunek(c, d, b);
	if (o1 != o2 && o3 != o4) return 1;
	if (o1 == 0 && na(a, c, b)) return 1;  
	if (o2 == 0 && na(a, d, b)) return 1;
	if (o3 == 0 && na(c, a, d)) return 1;
	if (o4 == 0 && na(c, b, d)) return 1;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	LD x, y;
	point a, b, c, d;
	cin >> t;
	while (t--){
		cin >> x >> y;
		a = {x, y};
		cin >> x >> y;
		b = {x, y};
		cin >> x >> y;
		c = {x, y};
		cin >> x >> y;
		d = {x, y};
		if (intersect(a, b, c, d)) cout << "TAK\n";
		else cout << "NIE\n";
	}
	return 0;
}
