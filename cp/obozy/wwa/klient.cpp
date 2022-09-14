#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<LL, LL>
#define st first
#define nd second
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 2; i<=sqrt(n); i++){
		while (n%i == 0){
			//debug(i);
			ans++;
			n/=i;
		}
	}
	if (n>1)ans++;
	cout << ans << "\n";
	return 0;
}


