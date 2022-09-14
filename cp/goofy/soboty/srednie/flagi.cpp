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

bool warunek(int middle, vector <int> tab){
	int ile = 0, i = 1, n = tab.size();
	while (i<n-1){
		if (tab[i]>tab[i-1] && tab[i]>tab[i+1]){
			i+=middle;
			ile++;
		} else i++;
	}
	debug(ile);
	if (ile >= middle) return true;
	else return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector <int> tab(n);
	for (int i = 0; i<n; i++) cin >> tab[i];
	int start = 0, koniec = n-1;
	while (start < koniec){
		int middle = (start + koniec)/2;
		if (warunek(middle, tab)) start = middle+1;
		else koniec = middle-1;
	}
	cout << koniec;
	return 0;
}


