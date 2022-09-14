#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << x << " "

set <int> used;
int m;
vector <int> tab;
string res;

void calc(char c, int n, int k){
	if (k == 0) return;
	if (k == 1) {
		res+=c;
		return;
	} 
	auto znak = c+1;
	auto l = -1, p = k, suma = 0, prev = 0;
	do {
		l++;
		p--;
		prev = suma;
		suma += tab[l]*tab[p];
	} while (suma < n);
	m = n-prev;
	auto n1 = ((m-1)/tab[p])+1;
	auto n2 = ((m-1)%tab[p])+1;
	res += znak; 
	calc(c, n1, l);
	calc(znak+1, n2, p);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> m >> n;
	tab.resize(21);
	tab[0] = tab[1] = 1;
	for (int i = 2; i<=20; i++){
		for (int k = 0; k<i; k++){
			tab[i]+=(tab[k]*tab[i-k-1]);
		}
	}
	calc('a', n, m);
	cout << res;
	return 0;
}
