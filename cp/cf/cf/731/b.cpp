#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

void solve(){
	string s;
	cin >> s;
	int n = s.size() - 1;
	deque<char>q;
	for (char x: s) q.pb(x);
	
	while (1){
		char c = n+'a';
		if (q.front() == c) q.pop_front();
		else if (q.back() == c) q.pop_back();
		else {
			cout << "NO\n";
			return;
		}
		n--;
		if (n<0) {
			cout << "YES\n";
			return;
		}
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

