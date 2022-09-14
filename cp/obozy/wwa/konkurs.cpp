#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

LL skalar(pii a, pii b){return (LL)a.st*(LL)b.st+(LL)a.nd*(LL)b.nd;}
pii vo = {0, 1};
LL iloczyn(pii a, pii b){return (LL)a.st*(LL)b.nd-(LL)a.nd*(LL)b.st;}

bool cmp(pii a, pii b){
	LL ilo = iloczyn(a, b);
	if (ilo == 0){
		LD o1 = a.st*a.st+a.nd*a.nd;
		LD o2 = b.st*b.st+b.nd*b.nd;
		return (o1<o2);
	}
	return (ilo > 0);
}

void zamiatanie(vector<pair<LL, LL>>&tab){
	int tmp = 0;
	pii xx = {1, -1};
	for (auto x: tab){
		if (x.st >= 0 && x.nd <= 0) tmp++;
	}
	int ans = tmp;
	for (int i = 0; i<(int)tab.size(); i++){
		if (tab[i].st <= 0 && tab[i].nd >= 0) tmp++;
		else tmp--;
		if (ans>=tmp){
			ans = tmp;
			xx = tab[i];
		}
	}
	//debug(xx.st);
	//debug(xx.nd);
	LL M = 1e9;
	LL I = -(LL)xx.nd*M/(LL)xx.st;
	while (M>1e9 || I>1e9){
		M/=2;I/=2;
	}
	while (M < 1 || I < 1){
		M*=2;I*=2;
	}
	cout << I << " " << M << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, miejsce = 1;
	cin >> n;
	vector<pair<LL, LL>>tab(n);
	cin >> tab[0].st >> tab[0].nd;
	for (int i = 1; i<n; i++){
		cin >> tab[i].st >> tab[i].nd;
		tab[i].st-=tab[0].st;
		tab[i].nd-=tab[0].nd;
	}
	tab[0].st = tab[0].nd = 0;
	for (int i = 1; i<(int)tab.size(); i++){
		if (tab[i].st <= tab[0].st && tab[i].nd <= tab[i].nd){
			swap(tab[i], tab[tab.size()-1]);
			tab.pop_back();
		}
	}
	for (int i = 1; i<(int)tab.size(); i++){
		if (tab[i].st > tab[0].st && tab[i].nd > tab[0].nd){
			miejsce++;
			swap(tab[i], tab[tab.size()-1]);
			tab.pop_back();
		}
	}
	if (tab.size() == 1){
		cout << miejsce << "\n1 1\n";
		return 0;
	}
	swap(tab[0], tab[tab.size()-1]);
	tab.pop_back();
	sort(tab.begin(), tab.end(), cmp);
	/*for (auto x: tab){
		debug(x.st);
		debug(x.nd);
		cerr << "\n";
	}*/
	cout << miejsce << "\n";
	zamiatanie(tab);
	return 0;
}

