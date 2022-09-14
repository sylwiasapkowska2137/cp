#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int a, b, c = 0;
	cin >> a >> b;
	for (int k = 10; k>=0; k--){
		bool x = a&(1<<k);
		bool y = b&(1<<k);
		if (x != y) c+=(1<<k); 
	}
	cout << c << "\n";
	return 0;
}

