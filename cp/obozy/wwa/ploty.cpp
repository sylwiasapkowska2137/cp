#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

LD EPS = 1e-13, ND = 1e-3;
vector<LD>a;
int k;

bool warunek(LD m){
	int cnt = 0;
	for (int i = 0; i<(int)a.size(); i++){
		cnt += floor(a[i]/m);
	}
	if (cnt >= k) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i<n; i++) cin >> a[i];
	LD start = 0, koniec = INT_MAX;
	while (koniec - start > EPS){
		LD m = (start+koniec)/2;
		//debug(m);
		if (warunek(m)) start = m;
		else koniec = m;
	}
	for (int i = 0; i<n; i++){
		LD t = abs(round(a[i]/start) - a[i]/start);
		if (t <= ND){
			//debug('x');
			int x = a[i];
			int y = round(a[i]/start);
			int d = __gcd(x, y);
			cout << x/d << " " << y/d << "\n";
			return 0;
		}
	}
	
	return 0;
}
