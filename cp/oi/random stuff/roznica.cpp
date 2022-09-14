#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 30;
vector <int> tab[MAX];
string s;
int n;

int psoms(int a, int b){
	int wynik = 0, suma = 0, suma_pop = 0, mini = 1e9+7, ptra = 0, ptrb = 0;
	while (tab[a-'a'][ptra] != tab[b-'a'][ptrb]){
		while (tab[a-'a'][ptra] < tab[b-'a'][ptrb] && ptra < tab[a-'a'].size()-1 ){
			//debug(tab[a-'a'][ptra]);
			suma++;
			ptra++;
			wynik = max(wynik, suma-mini);
		}
		while (tab[a-'a'][ptra] > tab[b-'a'][ptrb] && ptrb<tab[b-'a'].size()-1){
			//debug(tab[b-'a'][ptrb]);
			suma--;
			mini = min(mini, suma_pop);
			suma_pop = suma;
			ptrb++;
			wynik = max(wynik, suma-mini);
		}
	}
	/*
	for (int i = 1; i<=n; i++){
		if (s[i] == a) suma++;
		if (s[i] == b){
			suma--;
			mini = min(mini, suma_pop);
			suma_pop = suma;
		} 
		wynik = max(wynik, suma-mini);
	}*/
	return wynik;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int wynik = 0;
	cin >> n >> s;
	s = "$"+s;
	for (int i = 1; i<=n; i++){
		tab[s[i]-'a'].pb(i);
	}
	for (int i = 'a'; i<='z'; i++){
		if (tab[i-'a'].size()>0)	tab[i-'a'].pb(n+1);
	}
	for (int i = 'a'; i<='z'; i++){
		for (int j = 'a'; j<='z'; j++){
			if (tab[i-'a'].size() == 0 || tab[j-'a'].size() == 0) continue;
			if (i != j) wynik = max(wynik, psoms(i, j));
		}
	}
	cout << wynik << "\n";
	return 0;
}
