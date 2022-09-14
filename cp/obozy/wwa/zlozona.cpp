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
	
	int q, a, b;
	cin >> q;
	while (q--){
		cin >> a >> b;
		if (b <= 3) {
			cout << "NIE\n";
		} else if (a == b){
			bool ok = 0;
			for (int i = 2; i<=ceil((double)sqrt(a)); i++){
				if (a%i==0){
					ok = 1;
				}
			}
			if (ok) cout << a << "\n";
			else cout << "NIE\n";
		} else {
			if (a&1) cout << a+1 << "\n";
			else cout << a << "\n";
		}
	}
	return 0;
}




