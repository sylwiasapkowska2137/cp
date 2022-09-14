//https://szkopul.edu.pl/c/oki-dla-zaawansowanych/p/smg/
#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "
#define pb push_back

struct point{
	LL x,y;
	int nr;
	point(LL x, LL y, int nr): x(x), y(y), nr(nr) {}
	
};
int n, m;
vector <point> tab;
vector <int> res;
vector <bool> vis;

LL iloczyn(point a, point b){
	return  a.x*b.y - a.y*b.x;
}

bool cmp (point a, point b){ //czy punkt a jest bardziej na lewo niz b?
	LL ilo = iloczyn(a, b);
	if (ilo == 0){ //punkty są wspoliniowe
		if ((a.nr >= n && b.nr >= n) || (a.nr < n && b.nr < n)) return (a.nr < b.nr); //dwa rycerze/gasienice
		else {
			
		}
	} else if (ilo>0) return false; //punkt b jest na lewo od a, b < a
	else return true; // punkt a jest na lewo od b, a < b
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	LL x, y;
	cin >> n >> m;
	vis.assign(n+m, false);
	res.assign(m, 0);
	for (int i = 0; i<n; i++){
		cin >> x >> y;
		point a (x,y,i);
		tab.pb(a);
		cin >> x >> y;
		point b (x,y,i);
		tab.pb(b);
	}
	for (int i = n; i<m+n; i++){
		cin >> x >> y;
		point a (x,y,i);
		tab.pb(a);
	}
	
	sort(tab.begin(), tab.end(), cmp);
	vis.assign(n+1, false);
	int wynik = 0;
	for (auto x: tab){
		debug(x.x);
		debug(x.y);
		
		if (x.nr >= n){ //rycerz
			res[x.nr-n] = wynik;
		} else {
			if (vis[x.nr]){
				wynik--;
			} else {
				wynik++;
			}
			vis[x.nr] = !vis[x.nr];
		}
		debug(wynik);
		cerr << "\n";
	}
	for (auto x: res) cout << x << " ";
	return 0;
}
