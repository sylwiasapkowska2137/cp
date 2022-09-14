#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	vector<int>tab(n+1, 0), pref(n+1);
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		if (a > b) swap(a, b);
		tab[a] = max(tab[a], b);
	}
	for (int i = 1; i<=n; i++){
	       	//debug(tab[i]);
		if (tab[i]!=0){
			pref[i]++;
			pref[tab[i]+1]--;
		}
		pref[i]+=pref[i-1];
		debug(pref[i]);
	}
	cerr << "\n";
	
	return 0;
}
