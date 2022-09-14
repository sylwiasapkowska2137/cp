#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

void solve(){
	string a, b;
	int k, indeks = -1, ile;
	cin >> a >> b >> k;
	string c = b; ile = k;
	vector<int>zmiany(a.size(), 0);
	if (a[0]!=b[0]) zmiany[0] = 1;
	for (int i = 1; i<a.size(); i++){
		zmiany[i] = zmiany[i-1];
		if (a[i]!=b[i]) zmiany[i]++;
	}
	for (int i = 0; i<a.size(); i++){
		if (b[i]=='0') continue;
		int diff = 0;
		if (i!=0) diff = zmiany[i-1];
		if (a[i]>=b[i]) diff++;
		int pozostale = a.size() - i - 1;
		if (a[i]<b[i] && (b[i]!='1')) pozostale++;
		ile = k-diff;
		if (diff <= k && pozostale >= ile) indeks = i;
	}
	if (indeks == -1){
		cout << "-1\n";
		return;
	}
	ile = k;
	if (indeks) ile -= zmiany[indeks-1];
	if (ile > 0 && (a[indeks]!=b[indeks]-1)){
		c[indeks] = b[indeks] - 1;
		ile--;
	} else c[indeks] = a[indeks];
	
	
	for (int i = indeks+1; i<a.size(); i++){
		if (ile > 0 && a[i]!='9'){
			c[i]='9';
			ile--;
		} else c[i] = a[i];
	}
	
	for (int i = a.size()-1; i>=0; i--){
		if (ile > 0 && c[i]==a[i]){
			c[i] = c[i]-1;
			ile--;
		}
	}
	cout << c << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
