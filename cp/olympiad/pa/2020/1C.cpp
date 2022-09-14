#include <bits/stdc++.h>
using namespace std;
int tab[5][3];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n;
	cin >> n;
	while (n--){
		cin >> s;
		tab[s[0]-'1'][s[1]-'A']++;
	}
	for (int i = 0; i<5; i++){
		for (int j = 0; j<3; j++){
			if ((i == 4 && tab[i][j]<2) || (i!=4 && tab[i][j]<1)){
				cout << "NIE\n";
				return 0;
			}
		}
	}
	cout << "TAK\n";
	return 0;
}
