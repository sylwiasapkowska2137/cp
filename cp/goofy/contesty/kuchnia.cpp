#include <bits/stdc++.h>

using namespace std;

vector <int> tab;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int z, n, a;
	cin >> z;
	while (z--){
		tab.clear();
		cin >> n;
		for (int i = 0; i<n; i++){
			cin >> a;
			tab.push_back(a);
		}
		sort(tab.begin(), tab.end());
		for (auto x: tab) {
			cerr << x << " ";
		}
		cerr << "\n";
	}
	return 0;
}

