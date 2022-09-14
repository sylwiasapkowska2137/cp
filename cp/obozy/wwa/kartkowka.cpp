
#include <bits/stdc++.h>
using namespace std;

#define LL unsigned long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

const int MAX = 1e5+7;
vector<int>indeksy1[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x;
	cin >> n;
	vector<int>tab, b(n+1);
	for (int i = 1; i<=n; i++) {
		cin >> x;
		indeksy1[x].pb(i);
	}
	for (int i = 1; i<=n; i++) {
		cin >> b[i];
		for (int j = indeksy1[b[i]].size()-1; j>=0; j--){
			tab.pb(indeksy1[b[i]][j]);
		}
	}
	//for (auto x: tab) debug(x);
	vector<int>tail(tab.size(), 0);
	int length = 1;
	tail[0] = tab[0];
	for (int i = 1; i < (int)tab.size(); i++) {
		auto b = tail.begin(), e = tail.begin() + length;
		auto it = lower_bound(b, e, tab[i]);
		if (it == tail.begin() + length) tail[length++] = tab[i];
		else *it = tab[i];
	}
	cout << length << "\n";
	return 0;
}
