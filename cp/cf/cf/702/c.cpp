#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

map<LL, bool>mapa;

void solve(){
	LD x;
	cin >> x;
	LD EPS = 1e-4;
	for (auto y: mapa){
		if (x<=y.st) continue;
		if (mapa.find(x-y.st) != mapa.end()){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 1, 1e4+1){
		LL a = i;
		a = a*a*a;
		mapa[a] = 1;
	}
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
