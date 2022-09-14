//
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a, b, c;
	for (int i = 0; i<3; i++){
		cin >> a >> b >> c;
		if (a[0]=='T') {
			cout << c << "\n";
			return 0;
		}
	}
	cout << "\n";
	return 0;
}
