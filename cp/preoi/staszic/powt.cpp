#include <bits/stdc++.h>

using namespace std;

map<int, int>m;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, a;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> a;
		m[a]++;
	}
	for (auto x: m){
		if (x.first != x.second) {
			cout << "NIE\n";
			return 0;
		}
	}
	cout << "TAK\n";
	return 0;
}
