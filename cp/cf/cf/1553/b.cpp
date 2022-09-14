#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define ok cerr << "\n"
#define pb push_back

void solve(){
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	for (int start = 0; start<n; start++){
		for (int right = start; right<n; right++){
			int left = m-(right-start+1);
			if (left>right)continue;
			string a = s.substr(start, right);
			string b = s.substr(right-left, right);
			reverse(b.begin(), b.end());
			a+=b;
			debug(a);
			if (a == t){
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int q;
	cin >> q;
	while (q--) solve();
	
	return 0;
}
