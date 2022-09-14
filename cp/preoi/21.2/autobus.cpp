#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

vector <int> l, r;
vector <pii> tab;

int bigger(int val){
	int ans = -1, start = 0, koniec = l.size()-1;
	while (start <= koniec) {
		int m = (start+koniec) / 2;
		if (l[m] <= val) {
			start = m+1;
		} else {
			ans = m;
			koniec = m - 1;
		}
	}
	return ans;
}

int smaller(int val){
	int ans = -1, start = 0, koniec = r.size()-1;
	while (start <= koniec) {
		int m = (start+koniec) / 2;
		if (r[m] >= val) {
			koniec = m-1;
		} else {
			ans = m;
			start = m + 1;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int q, n, a, b;
	cin >> q >> n;
	for (int i = 0; i<q; i++){
		cin >> a >> b;
		l.pb(a);
		r.pb(b);
		tab.pb({l[i], r[i]});
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	for (auto x: tab){
		int big = q-bigger(x.nd);
		if (big > q) big = 0;
		int small = smaller(x.st)+1;
		int v = q - big - small - 1;
		cout << v << "\n";
	}
	return 0;
}
