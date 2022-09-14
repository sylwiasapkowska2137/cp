#include <bits/stdc++.h>
#include "maja.h"
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const int MAX = 1e6+2;
bool tab[MAX];
vector<int> primes;
int ans;

void sito(){
	tab[0] = tab[1] = 0;
	for (int i = 2; i<MAX; i++) tab[i] = 1;
	for (int i = 2; (i*i)<MAX; i++){
		if (tab[i]){
			for (int j = i*i; j<MAX; j+=i) tab[j] = 0; 
			primes.pb(i);
		}
	}

}

void solve(int n){
	int i = 0;
	ans = 1;
	while (i < primes.size()){
		int l = 1;
		while (l < n && czy_podzielna_przez(l)){
		       	l=l*primes[i];
		}
		ans*=l;		
		i++;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	sito();
	while (n = gramy_dalej()){
		if (n == 0) return 0;
		solve(n);
		zgaduj(ans);
	}
	return 0;
}
