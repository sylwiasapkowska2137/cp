#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, cnt = 0;
	LL ans = 0LL;
	string s;
	cin >> n >> s;
	vector<int> lewo(n), prawo(n);
	if (s[0]=='C') lewo[0] = 1;
	else lewo[0] = 0;
	for (int i = 1; i<n;i++){
		lewo[i] = lewo[i-1];
		if (s[i]=='C') lewo[i]++; 
	}
	if (s[n-1]=='C') prawo[n-1] = 1;
	else prawo[n-1] =0;
	for (int i = n-2; i>=0; i--){
		prawo[i] = prawo[i+1];
		if (s[i]=='C') prawo[i]++;
	}
	for (int i = 0; i<n; i++){
		if (s[i]=='B'){
			ans += (LL)min(lewo[i], prawo[i]);
		}
	}
	cout << ans << "\n";
	return 0;
}
