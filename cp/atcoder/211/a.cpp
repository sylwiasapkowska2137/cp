#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define ok cerr << "\n"
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	LD a, b;
	cin >> a >> b;
	LD c =  (a-b)/3+b;
	cout << setprecision(10) << fixed << c << "\n";

	return 0;
}

