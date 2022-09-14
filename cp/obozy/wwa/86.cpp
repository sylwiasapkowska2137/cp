#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
const int MAX = 1e6+7, END = 1e9;
int tab[MAX];
int n;

int warunek(int m){
	LL add = 0LL, remove = 0LL;
	for (int i = 0; i<n; i++){
		if (tab[i]>=m) remove += (LL)(tab[i]-m);
		else add += (m-tab[i]);
	}
	if (add == remove) return 0;
	if (add > remove) return 1;
	return -1;
}

bool binsearch(){
	int start = 1, koniec = END;
	while (koniec > start){
		int m = (start+koniec)/2;
		int x = warunek(m);
		//debug(m);
		//debug(x);
		//cerr << "\n";
		if (x == 0) return 1;
		else if (x == -1) {//za duzo add
			start = m+1;
		} else {//za duzo remove
			koniec = m-1;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> tab[i];
	}
	if (binsearch()) cout << "TAK\n";
	else cout << "NIE\n";
	return 0;
}



