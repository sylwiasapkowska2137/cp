#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, c;
	LL x, y;
	cin >> n >> x >> y;
	vector <int> tab;
	for (int i = 1; i<=n; i++){
		cin >> c;
		tab.pb(c);
	}
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=n; j+=i){
			debug(i);
			debug(j);
			cerr << "\n";
		}
	}
	return 0;
}
