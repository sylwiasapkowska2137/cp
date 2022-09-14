#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
#define dbg if(1)

const LD MAX = 2e6, EPS = 1e-9;
vector<LD>a, b;
int n;

bool warunek(LD w){
	b[0] = a[0]-w;
	for (int i = 1; i<n; i++){
		if (a[i]+w<b[i-1]) return 0;
		b[i] = max(b[i-1], a[i]-w);
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	a.resize(n);
	b.resize(n);
	LD start = MAX, koniec = -MAX;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		start = min(start, a[i]);
		koniec = max(koniec, a[i]);
	}
	cout << setprecision(10) << fixed;
	cerr << setprecision(10) << fixed;
	while (koniec - start > EPS){
		LD m = (start+koniec)/2;
		//debug(m);
		if (warunek(m))	koniec = m;
		else start = m;
	}
	cout << start << "\n";
	for (auto x: b) cout << x << "\n";
	return 0;
}

