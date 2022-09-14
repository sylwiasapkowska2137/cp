#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	LL t;
	string s;
	cin >> n >> t >> s;
	vector<int>jeden, lewo(n), prawo(n);
	for (int i = 0; i<n; i++){
		if (s[i]=='1') jeden.pb(i); 
	}
	//for (auto x: jeden) debug(x);
	//cerr << "\n";
	if (s[0]=='0') lewo[0] = 1;
	else lewo[0] = 0;
	for (int i = 1; i<n; i++){
		lewo[i] = lewo[i-1];
		if (s[i]=='0') lewo[i]++;
	}
	if (lewo[n-1] == n){
		cout << n-1 << "\n";
		return 0;
	}
	if (s[n-1]=='0') prawo[n-1] = 1;
	else prawo[n-1] = 0;
	for (int i = n-2; i>=0; i--){
		prawo[i] = prawo[i+1];
		if (s[i]=='0') prawo[i]++;
	}
	/*
	for (int i = 0; i<n; i++){
		debug(s[i]);
		debug(lewo[i]);
		debug(prawo[i]);
		cerr << "\n";
	}
	cerr << "\n";*/
	int l = 0, r = jeden.size()-1, x = 0;
	while (1){
		//debug(l);
		//debug(r);
		LL left = (LL)min(lewo[jeden[l]], prawo[jeden[l]]);
		LL right = (LL)min(lewo[jeden[r]], prawo[jeden[r]]);
		//debug(left);
		//debug(right);
		//cerr << "\n";
		if (left < right){
			if (t>=left){
				t-=left;
				x++;
				l++;
			} else break;
		} else {
			if (t>=right){
				t-=right;
				r--;
				x++;
			} else break;
		}
		if (l > r) break;
	}
	cout << n - x - 1 << "\n";
	return 0;
}
