#include <bits/stdc++.h>
#include "dlulib.h"
using namespace std;
#define debug(x) cerr << x << " "

vector <int> a;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	//cin >> n;
	int n = daj_n();
	a.resize(n+1, 0);
	int ans = 0;
	//cout << ans << "\n";
	odpowiedz(ans);
	return 0;
}
