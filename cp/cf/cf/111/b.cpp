#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back
#define rep(i, a, b) for (int i = a; i<b; i++)
#define repd(i, a, b) for (int i = a; i>=b; i--)

void solve(){
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	s+="a";
	//cout << s << "\n";
	if (b<0){ //oplaca nam sie usuwac najpierw 0, potem calosc 1, albo odwrotnie
		int ile[2], cons[2];
		rep(i, 0, 2) ile[i] = 0, cons[i] = 0;
		rep(i, 1, n+1){
			if (s[i]==s[i-1]) continue;
			cons[s[i-1]-'0']++;
		}
		rep(i, 0, n) ile[s[i]-'0']++;
		int white = (cons[0]+1)*b+a*n;
		int black = (cons[1]+1)*b+a*n;
		cout << max(white, black) << "\n";
	} else {
		cout << n*(b+a) << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
