#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
	int n, seed;
	cin >> n;
	cin >> seed;
	srand(seed);
	cout << n << endl;
	for (int h = 1; h <= 2; h++) {
		for (int i = 1; i <= n; i++) {
			cout << rand() % MOD << (i == n ? "" : " ");
		}
		cout << endl;
	}
	return 0;
}
