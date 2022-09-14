#include <bits/stdc++.h>

using namespace std;
#define st first
#define nd second
#define pb push_back
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		ll k;
		cin >> n >> k;
		
		vector <ll> a(n);
		vector <pair<ll, int> > mod(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mod[i] = {a[i]%k, i};
		}
		sort(mod.begin(), mod.end());
		int j = 0;
		ll ans = 0;
		vector <int> pom;
		for(int i = 0; i <= n-j-1; i++){
			while(mod[i].st < k-mod[n-j-1].st && i < n-j-1){
				pom.pb(a[mod[i].nd]);
				i++;
			}
			if(i != n-j-1) {
				ans += (a[mod[i].nd] + a[mod[n-j-1].nd])/k;
				j++;
			}
			else pom.pb(a[mod[i].nd]);
		}
		for(int i = 0; i < (int)pom.size(); i+=2){
			ans += (pom[i] + pom[i+1])/k;
		}
		cout << ans << "\n";
	}
	
	return 0;
}