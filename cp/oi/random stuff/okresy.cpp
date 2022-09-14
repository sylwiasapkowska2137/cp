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
	cout.tie(0);
	int n;
	string s;
	cin >> n >> s;
	vector<int> pi(n+1), p(n+1), sz(n+1);
	pi[0] = 0;
	for (int i = 1; i<n; i++){
		int j = pi[i-1];
		while (j > 0 && s[i]!=s[j]) j = pi[j-1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	LL res = 0LL;
	
	for (int i = 1; i<=n; i++) {
		p[i] = pi[i-1];
		//debug(p[i]); //prefiksosufix prefiksu dlugosci i+1
	}
	//cerr << "\n";
	for (int i = 1; i<=n; i++){
		if (p[i] == 0) sz[i] = i;
		else sz[i] = sz[p[i]]; 
		//debug(sz[i]);
	}
	for (int i = 1; i<=n; i++){
		if (sz[i]>(i/2)) continue;
		else res += (LL)(i-sz[i]);
	}
	cout << res;
	return 0;
}
