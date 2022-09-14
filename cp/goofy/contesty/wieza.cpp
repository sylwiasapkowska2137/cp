#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pb push_back
#define st first
#define nd second
#define pii pair <int, int>
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	LL n, k;
	cin >> n >> k;
	if (k*(k+1)/2 > n) {
		cout << 0;
		return 0;
	} else {
		for (int i = 1; i<k; i++) cout << i << " ";
		LL t = n - (k-1)*k/2;
		cout << t << "\n";
	}
	return 0;
}

