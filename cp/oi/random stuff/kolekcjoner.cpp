#include <bits/stdc++.h>
#include "ckollib.h"
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
	vector <int> tab(32, 0);
	int one = -1, two = -1, a = 0, b = 0;
	while (true) { 
		int k = karta();
		int tmp = k;
		if (k == 0) break;
		if (one == -1) one = k;
		else if (two == -1 && one != k) two = k;
		for(int i = 0; k>0; i++) {    
			tab[i]+=k%2;    
			k/=2;  
		}
		if (tmp == one) a++; 
		if (tmp == two) b++;
	}

	if (two == -1){
		//cout << one;
		odpowiedz(one);
		return 0;
	}
	if (a!=b) {
		if (a > b) odpowiedz(two);
		else odpowiedz(one);
		return 0;
	}
	int res = 0;
	for (int i = 0; i<32; i++){
		tab[i]%=a;
		//debug(tab[i]);
		if (tab[i]!=0){
			res += (1<<(i));
		}
	}
	//cout << res;
	odpowiedz(res);
	return 0;
}
