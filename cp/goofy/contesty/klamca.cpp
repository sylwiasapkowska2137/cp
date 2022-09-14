#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

map <int, pii> tab;

int main(){
	fastio;
	string s;
	int n, a;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> s >> a;
		if (tab.find(a) == tab.end()){
			tab[a] = {0, 0};
		} 
		if (s[0] == 'W'){
			tab.find(a)->nd.nd++;
		} else {
			tab.find(a)->nd.st++;
		}
	}
	for (auto x: tab){
		
		debug(x.st);
		debug(x.nd.st);
		debug(x.nd.nd);
		cerr << "\n";
	}
	return 0;
}

