#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pb push_back
#define st first
#define nd second
#define pii pair <int, int>
#define debug(x) cerr << x << " "

vector <pair<char, int> > tab;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin >> s;
	int n = s.length(), ile = 1;
	for (int i = 1; i<n; i++){
		if (s[i]==s[i-1]) ile++;
		else {
			tab.pb({s[i-1], ile});
			ile = 1;
		}
	}
	tab.pb({s[n-1], ile});
	for (int i = 0; i<(int)tab.size(); i++){
		if (tab[i].nd == 1) cout << tab[i].st;
		else {
			char c;
			if (tab[i].st == 'a' or tab[i+1].st == 'a'){
				if (tab[i].st == 'b' or tab[i+1].st == 'b')	c = 'c';
				else c = 'b';
			} else c = 'a';
			for (int j = 0; j<tab[i].nd; j++){
				if (j%2 == 0) cout << tab[i].st;
				else cout << c;
			}
		}
	}
	return 0;
}




