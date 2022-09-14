#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define pb push_back
#define st first
#define nd second
#define debug(x) cerr << x << " "

int toint(char c){
	return (int)(c-'a');
}
vector<int>freq(30, 0), tmp;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s, x;
	int q;
	cin >> s >> q;
	for (int i = 0; i<(int)s.size(); i++) freq[toint(s[i])]++;
	while (q--){
		tmp.assign(30, 0);
		cin >> x;
		bool ok = 0;
		for (int i = 0; i<(int)x.size(); i++) tmp[toint(x[i])]++;
		for (int i = 0; i<(int)tmp.size(); i++){
			if (freq[i]<tmp[i]){
				ok = 1;
				cout << "NIE\n";
			} 
		}
		if (!ok) cout << "TAK\n";
	}
	return 0;
}


