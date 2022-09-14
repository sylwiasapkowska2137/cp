#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back

map<string, int> m;
set<string>ss;
vector<string>tab;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	while (cin >> s){
		bool ok = 1;
		tab.pb(s);
		for (int i = 0; i<s.size(); i++){
			if (!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))) ok = 0;
		}
		if (ok){
			
			m[s]++;
		}
	}	
	int maxi = 0;
	for (auto x: m){
		maxi = max(maxi, x.nd);
	}
	for (auto x:m){
		if (x.nd == maxi) ss.insert(x.st);
	}
	for (auto x: tab){
		if (ss.find(x) != ss.end()){
			cout << x << " " << maxi << "\n";
			return 0;
		}
	}
	
	return 0;
}
