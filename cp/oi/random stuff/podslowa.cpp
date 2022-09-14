#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define ULL unsigned LL
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

const LL M1 = 1e9+7, M2 = 1e9+9, P1 = 41, P2 = 857;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	s = "%"+s;
	LL ans = 1;
	vector <LL> pot1(n+1, 1), pot2(n+1, 1), hash1(n+1), hash2(n+1);
	vector <pair<LL, LL> > res;
	hash1[0] = (LL)s[0];
	hash2[0] = (LL)s[0];
	for (int i = 1; i<=n; i++){
		pot1[i] = (pot1[i-1]*P1+M1) % M1;
		pot2[i] = (pot2[i-1]*P2+M2) % M2; 
		hash1[i] = (hash1[i-1]+(((LL)s[i]*pot1[i]) % M1)) % M1;
		hash2[i] = (hash2[i-1]+(((LL)s[i]*pot2[i]) % M2)) % M2;
	}
	for (int i = 1; i<=n; i++){
		for (int j = i; j<=n; j++){
			LL h1 = (hash1[j]-hash1[i-1]+M1)%M1;
			h1 = (h1*(pot1[n-j])) % M1;
			LL h2 = (hash2[j]-hash2[i-1]+M2)%M2;
			h2 = (h2*(pot2[n-j])) % M2;
			res.pb({h1, h2});
		}
	}
	sort(res.begin(), res.end());
	for (int i = 1; i<(int)res.size(); i++)	if (res[i]!=res[i-1]) ans++;
	cout << ans << "\n";
	return 0;
}
