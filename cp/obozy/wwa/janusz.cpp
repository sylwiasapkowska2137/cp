//47
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

	string s;
	cin >> s;
	LL suma = 0LL;
	int n = s.size();
	for (int i = 0; i<n; i++){
		suma+=(LL)(s[i]-'0');
	}
	int x = s[n-1]-'0';
	if (suma%3 == 0 && !(x&1))cout << "TAK\n";
	else cout << "NIE\n";
	return 0;
}


