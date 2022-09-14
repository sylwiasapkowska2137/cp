#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define debug(x) cerr << x << " ";
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, j;
	string s;
	cin >> n;
	LD a, b, mini1 = INT_MAX, mini2 = INT_MAX, maxi = 0;
	for (int i = 0; i<n; i++){
		cin >> s;
		a = 0; b = 0, j = 0;
		for (j; s[j]!='/'; j++){
			a+=(s[j]-'0');
			a*=10;
		}
		
		j++;
		for (j; j<(int)s.size(); j++){
			b+=(s[j]-'0');
			b*=10;
		}
		a/=10;b/=10;
		LD dec = a/b;
		if (dec > maxi) maxi = dec;
		if (dec < mini1){
			mini2 = mini1;
			mini1 = dec;
		} else if (dec < mini2){
			mini2 = dec;
		}
	}
	if (mini1 + mini2 > maxi) cout << "TAK\n";
	else cout << "NIE\n";
	return 0;
}
