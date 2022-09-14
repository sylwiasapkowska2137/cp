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
	
	int n = 30, x = 0;
	for (int i = 1; i<=n; i++){
		for (int j = i; j<=n; j++){
			if (__gcd(i, j) == 1) x++;
		}
	}
	debug(x);
	return 0;
}
