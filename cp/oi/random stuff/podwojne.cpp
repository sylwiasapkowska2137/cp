#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

const LL MOD = 1e9+7, POT = 31;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q, a, b, len, mid;
	string s;
	cin >> n >> s >> q;
	s = "%" + s;
	vector<LL> hasz(n+1), pot(n+1);
	pot[0] = 1;
	for (int i = 1; i<=n; i++){
		pot[i] = ((pot[i-1]*POT)%MOD+MOD)%MOD;
		hasz[i] = ((hasz[i-1]*POT)+s[i]+MOD)%MOD;
		debug(hasz[i]);
	}
	cerr << "\n";
	while (q--){
		cin >> a >> b;
		mid = (a+b)/2;//[a, mid] + [mid+1, b]
		LL hash1 = (((hasz[mid]-hasz[a-1])*pot[mid-a+1])%MOD+MOD)%MOD;
		LL hash2 = (((hasz[b]-hasz[mid])*pot[mid-a+1])%MOD+MOD)%MOD;
		debug(hash1);
		debug(hash2);
		cerr << "\n";
		if (hash1 == hash2) cout << "TAK\n";
		else cout << "NIE\n";
	}
	return 0;
}
