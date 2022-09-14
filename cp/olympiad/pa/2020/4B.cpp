#include <bits/stdc++.h>

using namespace std;

#define LL long long

LL binary(int n, int m, int p){
	if (m == 0) return 1;
	LL k = binary(n, m/2, p);
	if (m%2 == 1) return (k*k*(LL)n)%p;
	else return (k*k)%p;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, p;
	cin >> n >> m >> p;
	m = m*(m+1)/2;
	cout << binary(m, n, p) << "\n";
	return 0;
}
