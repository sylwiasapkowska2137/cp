#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pb push_back
#define st first
#define nd second
#define pii pair <int, int>
#define debug(x) cerr << x << " "

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n, maxi = 1e9+7;
	vector <int> first(27, -1), last(27, -1);
	cin >> n >> s;
	for (int i = 0; i<n; i++) if (first[s[i]-'a']==-1) first[s[i]-'a'] = i;
	for (int i = n-1; i>=0; i--) if (last[s[i]-'a']==-1) last[s[i]-'a'] = i;
	for (int i = 0; i<27; i++) maxi = min(maxi, first[i]+n-last[i]-1);
	cout << maxi;
	return 0;
}






