//https://goofy.ilo.pl/team/problem.php?id=1338
#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5+7;
int tab[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n, m, a, b;
	cin >> n >> m >> s;
	s="&"+s;
	while (m--){
		cin >> a >> b;
		tab[a]++;
		tab[b+1]--;
	}
	for (int i = 1; i<=n; i++){
		tab[i] += tab[i-1];
	}
	for (int i = 1; i<=n; i++){
		if (tab[i]%2 == 0) cout << s[i];
		else {
			if (s[i]=='A') cout << "R";
			else cout << "A";
		}
	}
	return 0;
}
