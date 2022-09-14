#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b, c, ans = INT_MAX;
	cin >> n;
	vector<pii>tab;
	vector<int>freq(n, 0);
	for (int i = 0; i<n; i++){
		cin >> a >> b >> c;
		tab.pb({a, i});
		tab.pb({b, i});
		tab.pb({c, i});
	}
	sort(tab.begin(), tab.end());
	int end = 0, cnt = 0;
	for (int start = 0; start<3*n; start++){
		while (cnt < n && end < 3*n){
			//add
			freq[tab[end].nd]++;
			if (freq[tab[end].nd] == 1) cnt++;
			end++;
		}
		if (end >= 3*n) break;
		ans = min(ans, tab[end-1].st-tab[start].st);
		freq[tab[start].nd]--;
		if (!freq[tab[start].nd]) cnt--;
	}
	cout << ans << "\n";
	return 0;
}
