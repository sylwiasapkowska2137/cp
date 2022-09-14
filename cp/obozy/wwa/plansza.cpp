
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
	
	int t, n;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n;
		if(n==1) cout << 2 << "\n";
		else if(n==2) cout << 16 << "\n";
		else if(n==3) cout << 32 << "\n";
		else cout << 4 << "\n";
	}
}


