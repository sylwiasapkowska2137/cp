#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
int freq1[2][MAX], freq2[2][MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string x, y;
	int n;
	cin >> n >> x >> y;
	for (int i = 0; i<n; i++){
		freq1[i%2][x[i]-'a']++;
		freq2[i%2][y[i]-'a']++;
	}
	for (int i = 0; i<=27; i++){
		//cerr << freq1[0][i] << " " << freq1[1][i] << " " << freq2[0][i] << " " << freq2[1][i] << "\n";
		if (!((freq1[0][i] == freq2[0][i]) && (freq1[1][i] == freq2[1][i]))){
			cout << "NIE\n";
			return 0;
		}
	}
	cout << "TAK\n";
	return 0;
}
