#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 1e6+7;
vector<int>tab[MAX];

int bigger(int val, int pos){
	int start = 0, koniec = tab[pos].size()-1, res = -1;
	while (start <= koniec){
		int m = (start+koniec)/2;
		if (tab[pos][m]>=val) {
			koniec = m-1;
			res = m;
		} else {
			start=m+1;
		}
	}
	return res;
}

void solve(){
	int m;
	cin >> m;
	vector <int> a(m);
	for (int i = 0; i<m; i++) cin >> a[i];
	int x = bigger(0, a[0]);
	//debug(x);
	if (x == -1){
		cout << "NIE\n";
		return;
	}
	for (int i = 1; i<m; i++){
		x = bigger(tab[a[i-1]][x]+1, a[i]);
		//debug(x);
		if (x == -1) {
			cout << "NIE\n";
			return;
		}
	}
	cout << "TAK\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x, q;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> x;
		tab[x].pb(i);
	}
	cin >> q;
	while (q--) solve();
	return 0;
}
