#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int res = 0, a;
	cin >> a;
	while (cin >> a) res ^= a;
	cout << res;
	return 0;
}
