#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

const LL MAX = 1e13;

LL silnia(int x){
	LL ans = 1;
	for (int i = 2; i<=x; i++) ans*=i;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<LL>tab;
	int k = 20;
	for (int i = 1; i<(1<<k); i++){
		LL ans = 0;
		bool ok = 0;
		for (int j = 0; j<k; j++){
			if (i&(1<<j)) {
				ans+=silnia(j+1);
				if (ans > MAX) {
					ok = 1;
					break;
				}
			}
		}
		if (ok) break;
		tab.pb(ans);
	}
	tab.pb(0);
	sort(tab.begin(), tab.end());
	vector<LL>pref(tab.size());
	pref[0] = 0;
	for (int i = 1; i<(int)tab.size(); i++) pref[i] = pref[i-1]+tab[i];
	int q;
	LL a, b;
	cin >> q;
	while (q--){
		cin >> a >> b;
		int c = lower_bound(tab.begin(), tab.end(), a) - tab.begin();
		int d = upper_bound(tab.begin(), tab.end(), b) - tab.begin();
		/*
		debug(a);
		debug(b);
		debug(c);
		debug(d);
		debug(tab[c-1]);
		debug(tab[c]);
		debug(tab[d-1]);
		debug(tab[d]);
		debug(pref[d]);
		debug(pref[d-1]);*/
		cout << pref[d-1] - pref[c-1] << "\n";
		//cerr << "\n";
	}
	
	return 0;
}


