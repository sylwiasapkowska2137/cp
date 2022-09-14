#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	if (n <= 125) cout << 4;
	else if (n <= 211) cout << 6;
	else cout << 8;
	
	
	return 0;
}

