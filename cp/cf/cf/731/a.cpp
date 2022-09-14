#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

void solve(){
	string s;
	getline(cin, s);
	int ax, ay, bx, by, fx, fy;
	cin >> ax >> ay >> bx >> by >> fx >> fy;
	if (ax == bx){
		if (ax == fx && ((ay < fy && fy < by) || (ay > fy && fy > by))) cout << abs(ay-by)+2 << "\n";
		else cout << abs(ay-by) << "\n";
	} else if (ay == by){
		if (ay == fy && ((ax < fx && fx < bx) || (ax > fx && fx > bx))) cout << abs(bx-ax)+2 << "\n";
		else cout << abs(bx-ax) << "\n";
	} else cout << abs(ax-bx)+abs(ay-by) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
