#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "
#define rep(i, a, b) for (int i = a; i<b; i++)

vector<int>tab[6];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	string s;
	cin >> n >> q >> s;
	int m = 3, k = 0;
	vector<int>p = {0, 1, 2};
	
	do{
		tab[k].assign(n, 0);
		if (s[0] == p[0]+'a') tab[k][0] = 0;
		else tab[k][0] = 1;
		rep(i, 1, n){
			tab[k][i] = tab[k][i-1];
			if (s[i] != p[i%3]+'a') tab[k][i]++;
		}
		k++;
	} while(next_permutation(p.begin(), p.end()));
	
	
	while (q--){
		int a, b; cin >> a >> b;
		a--;b--;
		int ans = INT_MAX;
		rep(i, 0, 6){
			int x;
			if (a == 0) x = 0;
			else x = tab[i][a-1];
			ans = min(ans, tab[i][b] - x);
		}
		cout << ans << "\n";
	}
	return 0;
}


