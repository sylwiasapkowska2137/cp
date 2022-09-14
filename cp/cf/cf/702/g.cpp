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
	int n, m;
	LL x, suma = 0;
	cin >> n >> m;
	vector<LL>a(n), pref, indeks;
	rep(i, 0, n) {
		cin >> a[i];
		suma += a[i];
		if (pref.empty() || pref.back() < suma) {
			pref.pb(suma);
			indeks.pb(i);
		}
	}
	rep(i, 0, m) {
		cin >> x;
		if (suma<=0 && pref.back() < x){
			cout << "-1 ";
			continue;
		} 
		LL ilepelnych = 0;
		if (pref.back() < x) ilepelnych = (x-pref.back() + suma - 1)/suma;
		x-=ilepelnych*suma;
		cout << ilepelnych*n + indeks[lower_bound(pref.begin(), pref.end(), x)-pref.begin()] << " ";
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
