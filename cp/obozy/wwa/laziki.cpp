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
	
	LL n, w;
	cin >> n >> w;
	LL delta = n*n-4*w;
	LL b1 = (n-sqrt(delta))/2;
	LL b2 = (n+sqrt(delta))/2;
	cout << min(b1, b2) << "\n";
	return 0;
}
