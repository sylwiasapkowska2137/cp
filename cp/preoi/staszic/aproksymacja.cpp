#include <bits/stdc++.h>

using namespace std;

#define LD long double
#define debug(x) cerr << x << " "

int n;
vector <LD> a;
vector<LD> b;

bool warunek(LD m){
	b[0] = a[0]-m;
	for (int i = 1; i<n; i++){
		if (a[i]+m< b[i-1]) return false;
		else b[i] = max(b[i-1], a[i]-m);
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(5) << fixed;
	cerr << setprecision(5) << fixed;
	cin >> n;
	a.resize(n);
	b.resize(n);
	LD start = 0, koniec = 2e6, m, epsilon = 1e-6;
	for (int i = 0; i<n; i++){
		cin >> a[i];
		start = min(start, a[i]);
		koniec = max(koniec, a[i]);
	}
	
	while (koniec - start > epsilon){
		m = (start+koniec)/2;
		if (warunek(m)) koniec = m;
		else start = m;
	}
	cout << start << "\n";
	for (int i = 0; i<n; i++){
		cout << b[i] << "\n";
	}
	return 0;
}
