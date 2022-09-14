#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define pb push_back
#define st first
#define nd second
#define debug(x) cerr << x << " "

LL d(LL m, double x){
	return (LL)floor((double)m/x);
}

LL warunek(LL m){
	LL ans = d(m, 2.0) + d(m, 3.0) + d(m, 5.0) - d(m, 6.0) - d(m, 10.0) - d(m, 15.0) + d(m, 15.0);  
	return m - ans - 1;
}

LL binsearch(LL n){
	LL start = 1, koniec = LLONG_MAX, ans = -1;
	while (koniec >= start){
		LL m = (start+koniec)/2;
		debug(m);
		LL x = warunek(m);
		debug(x);
		cerr << "\n";
		if (x >= n) {
			ans = m;
			koniec = m-1;
		} else start = m+1;
	}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	LL n;
	cin >> n;
	cout << binsearch(n) << "\n";
	return 0;
}



