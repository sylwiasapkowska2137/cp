#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

void solve(){
	int k;
	cin >> k;
	int s = sqrt(k);
	if (s*s == k){
		cout << s << " " << 1 << "\n";
	} else {
		int ile = (s+1)*(s+1)-s*s;
		if (k-s*s>ile/2){
			cout << s+1 << " " << (s+1)*(s+1)-k+1 << "\n";
		} else {
			cout << k-s*s << " " << s+1 << "\n";
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
