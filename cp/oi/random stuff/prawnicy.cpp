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

struct A{
	int l, r, i;
	//A (int l, int r, int i): l(l), r(r), i(i) {}
};

map <int, vector<int> > start, koniec;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k, l, r;
	cin >> n >> k;
	vector <A> tab(n);
	for (int i = 0; i<n; i++){
		cin >> tab[i].l >> tab[i].r;
		tab[i].i = i;
		start[tab[i].l].pb(i);
		koniec[tab[i].r].pb(i);
	}
	for (auto x: start){
		debug(x.st);
		for (auto y: x.nd)debug(y);
		cerr << "\n";
	}
	
	return 0;
}



