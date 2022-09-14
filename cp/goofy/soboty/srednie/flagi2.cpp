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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector <int> tab(n), last(n);
	for (int i = 0; i<n; i++) {
		cin >> tab[i];
	}
	last[n-1] = 1e9+7;
	for (int i = n-2; i>=1; i--){
		if (tab[i]>tab[i-1] && tab[i]>tab[i+1]){
			last[i] = i;
		} else last[i] = last[i+1];
	}
	last[0] = last[1];
	//for (auto x: last) debug(x);
	int k = 1, wynik = 0;
	while (k*(k-1) <= n){
		int p = 0, flagi = 0;
		while (p<n && flagi < k){
			p = last[p];
			if (p == 1e9+7) break;
			p+=k;
			flagi++;
		} 
		wynik = max(wynik,flagi);
		k++;
	}
	cout << wynik;
	return 0;
}



