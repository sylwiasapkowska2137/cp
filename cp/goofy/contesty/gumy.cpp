#include <bits/stdc++.h>

using namespace std;

#define LL long long

LL cnt(vector <LL> &tab, int start, int koniec){ //start włącznie, koenic wyłacznie
	LL z = tab[start]; 
	LL bez = 0LL; 
	for(int i = start+1; i<koniec; i++){
		LL tmp = z;   
		z = max(tmp, tab[i]+bez);
		bez = tmp; 
	}
	return max(bez, z);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector <LL> tab(n);
	vector <LL> ujemne;
	ujemne.push_back(-1);
	for (int i = 0; i<n; i++) {
		cin >> tab[i];
		if (tab[i]<0){
			ujemne.push_back(i);
		}
	}
	LL res = 0;
	if (ujemne.back() != n-1)ujemne.push_back(n);
	for (int i = 1; i<ujemne.size(); i++){
		res += cnt(tab, ujemne[i-1]+1, ujemne[i]);
	}
	cout << res;
	return 0;
}
