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
	string s;
	cin >> s;
	int n = s.size();
	vector<int> pi(n), ans;
	pi[0] = 0;
	for (int i = 1; i<n; i++){
		int j = pi[i-1];
		while (j > 0 && s[i]!=s[j]) j = pi[j-1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	int v = pi[n-1];
	ans.pb(v);
	while (v>0){
		v = pi[v-1];
		ans.pb(v);
	}
	int res = n;
	for (int i = 0; i<(int)ans.size()-1; i++){
		if (ans[i]<=2*ans[i+1]) continue;
		else {
			res = ans[i];
			break;
		}
	}
	cout << res;
	return 0;
}

