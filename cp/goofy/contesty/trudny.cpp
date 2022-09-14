#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pb push_back
#define st first
#define nd second
#define pii pair <int, int>
#define debug(x) cerr << x << " "

const int MAX = 1e6+7;
vector <int> tab[MAX];

int binsearch(int val, int i){
	int start = 0, koniec = tab[val].size(), m;
	while (start - koniec > 1){
		m = (start+koniec)/2;
		if (tab[val][m]<i) start = m;
		else koniec = m;
	}
	return start;
}

void solve(){
	int n, a, ptr = 0;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> a;
		ptr = binsearch(a, ptr)+1;
		debug(ptr);
	}
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t, n, curr;
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> curr;
		tab[curr].pb(i);
	}
	cin >> t;
	while (t--) solve();
	return 0;
}

