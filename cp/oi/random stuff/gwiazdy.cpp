#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, s, prawo = 0, lewo = 0, mini = 1e9+7, index;
	cin >> n >> s;
	vector <pii> tab(n);
	for (int i = 1; i<n; i++){
		cin >> tab[i].st >> tab[i].nd;
		if (tab[i].st < tab[i].nd) prawo++;
		else lewo++;
	}
	if (s > 1 && s < n){
		if (prawo >= 1 && lewo >= 1){
			//wypisywanie wyniku
			debug("end");
			return 0;
		}
		if (prawo == 0){
			//znalezc jeden z lewych o najmniejszej roznicy
			for (int i = 1; i<n; i++){
				if (tab[i].nd >= tab[i].st && tab[i].nd - tab[i].st < mini){
					mini = tab[i].nd - tab[i].st;
					index = i;
				}
			}
			debug(index);
			
		} else if (lewo == 0){
			for (int i = 1; i<n; i++){
				if (tab[i].st >= tab[i].nd && tab[i].st - tab[i].nd < mini){
					mini = tab[i].st - tab[i].nd;
					index = i;
				}
			}
			debug(index);
		}
	} else if (s == 1){
		
	} else if (s == n){
		
	}
	return 0;
}
