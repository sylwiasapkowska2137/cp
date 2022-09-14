#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define ULL unsigned LL
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

const LL M = 1000003;
vector <int> pot(32);
vector <int> rep;

int Find(int a){
	if (rep[a] == a) return a;
	rep[a] = Find(rep[a]);
	return rep[a];
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a != b) rep[a] = rep[b];
}

int hashuj(string s){
	int hash = 0;
	for (int i = 0; i<(int)s.size(); i++){
		hash = (hash+((int)s[i]*pot[i]+M)%M);
	}
	return hash;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s, as, bs;
	int q, a, b;
	pot[0] = 1;
	for (int i = 1; i<(int)pot.size(); i++)	pot[i] = (pot[i-1]*467)%M;
	cin >> q;
	rep.resize(M+2);
	for (int i = 0; i<=M; i++) rep[i] = i;
	for (int i = 0; i<q; i++){
		cin >> s >> as >> bs;
		a = hashuj(as);
		b = hashuj(bs);
		debug(a);
		debug(b);
		if (s[0] == 'c') Union(a,b);
		else {
			if (Find(a) == Find(b)) cout << "Tak\n";
			else cout << "Nie\n";
		}
	}
	return 0;
}


