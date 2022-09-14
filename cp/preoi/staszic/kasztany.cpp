#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
	fastio;
	int a, b, c;
	cin >> a >> b >> c;
	cout << min(a, min(b, c));
	return 0;
}

