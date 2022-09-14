#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, start = 0, koniec = 2, maxi = 0;
	cin >> n;
	vector <int> bierki(n);
	for (int i = 0; i<n; i++) cin >> bierki[i];
	sort(bierki.begin(), bierki.end());
	while (start < n){
		if (koniec +  2 > start) {
			start++;
			continue;
		}
		if (bierki[koniec]+bierki[koniec+1]>bierki[start]){
			maxi = max(maxi, start-koniec+1);
			start++;
			continue;
		}
		koniec++;
	}
	cout << maxi << "\n";
	return 0;
}
