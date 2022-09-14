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
	LL suma = 0;
	vector <int> tab(n);
	for (int i = 0; i<n; i++){
		cin >> tab[i];
		suma += (LL)tab[i];
	}
	LD res = (LD)suma/(LD)n;
	if (res == (int)res){
		LL wyn = 0;
		for (int i = 0; i <n; i++){
			wyn += max(0LL, (LL)tab[i]-(LL)res);
		}
		cout << wyn;
	} else cout << "NIE";
	return 0;
}







