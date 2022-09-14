#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int>a(10);
	int suma = 0;
	for (int i = 0; i<10; i++) {
		cin >> a[i];
		suma+=a[i];
	}
	sort(a.begin(), a.end());
	int c = suma/4 - a[0] - a[9];
	int x = a[1]-c;
	int b = a[0]-x;
	int e = a[8]-c;
	int d = a[9]-e;
	cout << x << " " << b << " " << c << " " << d << " " << e << "\n";
	return 0;
}


