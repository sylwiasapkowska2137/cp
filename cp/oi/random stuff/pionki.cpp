#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

vector<int>pion, poziom;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, x = 0;
	cin >> n >> m;
	char c;
	pion.resize(m);
	poziom.resize(n);
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++){
			cin >> c;
			if (c == '#'){
				x++;
				pion[j]++;
				poziom[i]++;
			}
		}
	}
	LL ans = 0;
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++){
			ans = max(ans, (LL)pion[j]+poziom[i]);
		}
	}
	cout << 2*x-ans << "\n";
	return 0;
}
