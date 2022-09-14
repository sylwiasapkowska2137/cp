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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, res = 0;
	cin >> n;
	vector <int> tab(n), maxi(n);
	vector <bool> vis;
	for (int i = 0; i<n; i++) cin >> tab[i];
	maxi[n-1] = tab[n-1];
	for (int i = n-2; i>=0; i--){
		maxi[i] = max(maxi[i+1], tab[i]);
	}
	for (auto x: maxi) debug(x);
	for (int i = n-2; i>=0; i--){
		if (maxi[i]>tab[i] && !vis[maxi[i]]){
			vis[maxi[i]] = true;
			res = max(res, maxi[i]);
		}
	}
	cout << res-1;
	return 0;
}




