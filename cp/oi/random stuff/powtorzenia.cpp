#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, maxi = 0;
	cin >> n;
	vector <string> s;
	vector <int> hash1[n], hash2[n];
	for (int i = 0; i<n; i++) {
		cin >> s[i];
		s[i] = "%"+s[i];
		hash[i].resize(s[i].size());
		maxi = max(maxi, s[i].size());
	}
	vector <int> pot1, pot2;
	
	return 0;
}
