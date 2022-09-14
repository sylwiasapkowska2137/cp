#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define pb push_back
#define st first
#define nd second
#define pii pair <int, int>
#define debug(x) cerr << x << " "

vector <pii> tab;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, curr;
	cin >> n >> curr;
	for (int i = 1; i<n-1; i++){
		cin >> curr;
		tab.pb({curr, i});
	}
	cin >> curr;
	sort(tab.begin(), tab.end());
	if (tab[1].nd != tab[0].nd+1 && tab[1].nd != tab[0].nd-1) cout << tab[0].st+tab[1].st;
	else if (tab[2].nd != tab[0].nd+1 && tab[2].nd != tab[0].nd -1)cout << tab[0].st+tab[2].st;
	else cout << min(tab[0].st+tab[3].st, tab[1].st+tab[2].st);
	return 0;
}
