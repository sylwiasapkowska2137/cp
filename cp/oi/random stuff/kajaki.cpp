#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " "
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int w, n, val, res = 0, elem;
	cin >> w >> n;
	vector <int> tab(n);
	vector<bool>used(n, 0);
	for (int i = 0; i<n; i++) cin >> tab[i];
	int b = n-1;
	sort(tab.begin(), tab.end());
	for (int i = 0; i<n; i++){
		if (used[i]) continue;
		used[i] = 1;
		while (tab[i]+tab[b]>w && b>0) b--;
		while (used[b] && b>0) b--;
		if (b <= 0 && used[0]) break;
		used[b] = 1;
		res++;
		b--;
	}
	cout << n-res;
	return 0;
}
