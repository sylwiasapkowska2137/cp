#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, mini = 1e9+7, maxi = -1e9+7, a;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> a;
		maxi = max(a, maxi);
		mini = min(a, mini);
	}
	cout << maxi - mini << "\n";
	return 0;
}
