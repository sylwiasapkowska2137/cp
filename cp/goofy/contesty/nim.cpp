#include <bits/stdc++.h>

using namespace std;

#define LL long long

bool tab[400];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LL n;
	int t, ile;
	cin >> t;
	while (t--){
		cin >> n;
		if (n%2 == 1) cout << "TAK\n";
		else {
			ile = 0;
			while (n%2 == 0){
				n/=2;
				ile++;
			}
			if (ile%2 == 0) cout << "TAK\n";
			else cout << "NIE\n";
		}
	}
	return 0;
}
