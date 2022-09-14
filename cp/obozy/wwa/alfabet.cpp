#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define pb push_back
#define st first
#define nd second
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	char c;
	cin >> c;
	c = tolower(c);
	string s = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i<(int)s.size(); i++){
		if (s[i]==c){
			cout << i+1 << "\n";
			return 0;
		}
	}
	
	return 0;
}

