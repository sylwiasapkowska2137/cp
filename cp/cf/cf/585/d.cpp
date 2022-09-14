#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	LL a = 0, b = 0;
	string s;
	cin >> n >> s;
	
	n/=2;
	for (int i = 0; i<n; i++){
		a+=(s[i]=='?')?9: 2*(s[i]-'0');
	}
	for (int i = 0; i<n; i++){
		b+=(s[i+n]=='?')?9: 2*(s[i+n]-'0');
	}
	if (a == b) cout << "Bicarp\n";
	else cout << "Monocarp\n";
	return 0;
}
