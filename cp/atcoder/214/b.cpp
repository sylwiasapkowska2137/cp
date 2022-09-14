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
	
	LL ans = 0LL, S, T;
	cin >> S >> T;
	
	rep(i, 0, 101){
		rep(j, 0, 101){
			rep(k, 0, 101){
				int s = i+j+k;
				LL t = (LL)i*(LL)j*(LL)k;
				if (s <= S && t <= T) ans++;
			}
		}
	}
	cout << ans;
	
	return 0;
}


