#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, ans = 0;
	cin >> n;
	while (1){
		bool ok = 0;
		for (int i = 2; i<=(int)sqrt(n); i++){
			if (n%i == 0){
				n = i;
				ok = 1;
				ans++;
				break;
			}
		}
		if(!ok) break;
	}
	cout << ans + n << "\n";
	return 0;
}
