#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s, t;
	cin >> n >> s >> t;
	vector<int>ab, ba;
	for (int i = 0; i<n; i++){
		if (s[i] == t[i])continue;
		if (s[i] == 'a') ab.pb(i);
		else ba.pb(i);
	}
	
	//cnt
	bool a = ba.size()&1;
	bool b = ab.size()&1;
	if (a != b){
		cout << "-1\n";
		return 0;
	}
	
	vector<pii>ans;
	for (int i = 0; i+1<(int)ab.size(); i+=2){
		ans.pb({ab[i], ab[i+1]});
	} 
	for (int i = 0; i+1<(int)ba.size(); i+=2){
		ans.pb({ba[i], ba[i+1]});
	} 
	if (ab.size()&1){
		ans.pb({ab[ab.size()-1], ab[ab.size()-1]});
		ans.pb({ab[ab.size()-1], ba[ba.size()-1]});
	}
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x.st+1 << " " << x.nd+1 << "\n";
	return 0;
}


