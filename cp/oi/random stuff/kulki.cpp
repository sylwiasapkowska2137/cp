#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define pii pair<int,int>
#define st first
#define nd second
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	char c;
	cin >> n;
	vector<int>black[2], white[2];
	for (int i = 0; i<n; i++) {
		cin >> c;
		if (c == 'C') black[0].pb(i);
		else white[0].pb(i);
	}
	for (int i = 0; i<n; i++) {
		cin >> c;
		if (c == 'C') black[1].pb(i);
		else white[1].pb(i);  
	}
	/*
	for (auto x: white[0]) debug(x);
	cerr << "\n";
	for (auto x: black[1]) debug(x);
	cerr << "\n";
	*/
	LL ans = 0, ans2 = 0;
	for (int i = 0; i<(int)white[0].size(); i++){
		ans += (LL)abs(white[0][i]-black[1][i]);
		ans++;
	}
	/*
	debug(ans);
	cerr << "\n\n";
	for (auto x: white[1]) debug(x);
	cerr << "\n";
	for (auto x: black[0]) debug(x);
	cerr << "\n";
	*/
	for (int i = 0; i<(int)white[1].size(); i++){
		ans2 += (LL)abs(white[1][i]-black[0][i]);
		ans2++;
	}
	//debug(ans2);
	cout << min(ans, ans2) << "\n";
	return 0;
}
