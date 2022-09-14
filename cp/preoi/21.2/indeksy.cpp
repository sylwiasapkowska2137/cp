#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pb push_back
#define st first
#define nd second

const int MAX = 2e5+7;
vector <bool> indeks;
const LL M1 = 1e9+7, M2 = 1e9+9, P1 = 41, P2 = 857;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, one = 0;
	string s;
	char c;
	cin >> n >> s;
	indeks.assign(n+1, 0);
	for (int i = 1; i<=n; i++) {
		cin >> c;
		if (c=='1') {
			indeks[i] = 1;
			one++;
		}
	}
	if (one == n) {
		cout << 0;
		return 0;
	}
	s = "%"+s;
	vector <LL> pot1(n+1, 1), pot2(n+1, 1), hash1(n+1), hash2(n+1);
	vector <pair<pair<LL, LL>, LL> >res;
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
			if (indeks[j])continue;
			LL h1 = (hash1[j]-hash1[i-1]+M1)%M1;
			h1 = (h1*(pot1[n-j])) % M1;
			LL h2 = (hash2[j]-hash2[i-1]+M2)%M2;
			h2 = (h2*(pot2[n-j])) % M2;
			res.pb({{h1, h2}, j-i+1});
		}
	}
	sort(res.begin(), res.end());
	LL ile = 1, ans = 1LL;
	for (int i = 1; i<(int)res.size(); i++){
		if (res[i].st == res[i-1].st) ile++;
		else {
			ans = max(ans, ile*res[i-1].nd);
			ile = 1;
		}
	}
	ans = max(ans, ile*res[(int)res.size()-1].nd);
	cout << ans;
	return 0;
}
