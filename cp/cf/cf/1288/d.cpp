#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
	
const int MAX = 3e5+7;
int tab[MAX][9];
int n, k, l, r;

bool warunek(int m){
	int mask = 0;
	vector<int>masks((1<<k), -1);
	int bitmask = (1<<k)-1;
	for (int i = 0; i<n; i++){
		mask = 0;
		for (int j = 0; j<k; j++){
			if (tab[i][j]>=m) mask|=(1<<j);
		}
		masks[mask] = i; 
	}
	for (int i = 0; i<(1<<k); i++){
		for (int j = 0; j<(1<<k); j++){
			if (masks[i] == -1 || masks[j] == -1) continue;
			if ((i|j) == bitmask){
				l = masks[i];
				r = masks[j];
				return 1;
			}
		}
	}
	return 0;
}

void binsearch(){
	int start = 0, koniec = 1e9, ans = 0;
	while (koniec >= start){
		int m = (start+koniec)/2;
		if (warunek(m))	start = m+1;
		else koniec = m-1;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i<n; i++){
		for (int j = 0; j<k; j++){
			cin >> tab[i][j];
		}
	}
	binsearch();
	cout << l+1 << " " << r+1 << "\n";
	return 0;
}

