#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
int n, m, q;

LL power(LL a, LL b) {
	LL res = 1LL;
	while (b){
		if (b&1)res = (res*a)%m;
		a = (a*a)%m;
		b /=2;
	}
	return res;
}

LL dziel(vector<int>tab, int potega){
	if (tab.size() == 1) return tab[0];
	vector<int>p,np;
	for (int i = 0; i<tab.size(); i++){
		if (i&1) np.pb(tab[i]);
		else p.pb(tab[i]);
	}
	LL a = dziel(np, 2*potega);
	LL b = dziel(p, 2*potega);
	return (a+power(q, potega)*b);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> q;
	vector<int>tab(n);
	for (int i = 0; i<n; i++) cin >> tab[i];
	LL a = dziel(tab, 1);
	debug(a);
	return 0;
}
