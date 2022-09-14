#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	vector<int>tab;
	int n;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> s;
		if (s[1]=='C') tab.pb(10*(s[0]-'0')+1);
		else if (s[1]=='D') tab.pb(10*(s[0]-'0')+2);
		else if (s[1]=='H') tab.pb(10*(s[0]-'0')+3);
		else if (s[1]=='S') tab.pb(10*(s[0]-'0')+4);
		else tab.pb(10*(s[0]-'0')+5);
	}
	//for (auto x: tab) debug(x);
	for (int i = 1; i<tab.size(); i++){
		if (tab[i]<=tab[i-1]){
			cout << "licytacja niepoprawna\n";
			return 0;
		}
	}
	if (n&1) cout << "NS\n";
	else cout << "WE\n";
	return 0;
}
