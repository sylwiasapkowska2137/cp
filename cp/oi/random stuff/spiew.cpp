#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << x << " ";

int main(){
	int n, ile = 0, res = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i<n; i++){
		if (s[i]=='Z'){
			ile++;
		} else {
			res += (ceil((double)ile/3));
			ile = 0;
		}
	}
	res += (ceil((double)ile/3));
	cout << res;
}
