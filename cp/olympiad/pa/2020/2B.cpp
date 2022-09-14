#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e5+7;
int tab[MAX];
int pref[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i<=n; i++){
		cin >> tab[i];
		pref[i] = pref[i-1] + tab[i];
		cerr << pref[i] << " ";
	}
	cerr << "\n";
	return 0;
}
