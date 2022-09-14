#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pb push_back
#define st first
#define nd second
#define pii pair <int, int>
#define debug(x) cerr << x << " "

vector <LL> tab;

bool warunek(LL m, LL n, LL k){
	LL cnt = 1, suma = 0;
	for (int i = 0; i<n; i++){
		if (tab[i]>m) return 0;
		suma += tab[i];
		if (suma>m) {
			cnt++;
			suma = (LL)tab[i];
		}
	}
	if (cnt <= k) return 1;
	return 0;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	LL suma = 0;
	cin >> n >> k;
	tab.assign(n, 0);
	for (int i = 1; i<n; i++) {
		cin >> tab[i];
		suma+=tab[i];
	}
	LL start = 1, koniec = suma, m, ans = -1;
	while (start <= koniec){
		m = (start + koniec)/2;
		if (warunek(m, n, k)){
			ans = m;
			koniec = m-1;
		} else start = m+1;
	}
	cout << ans;
	return 0;
}
