//https://www.codechef.com/problems/MCO16504
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pb push_back
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second

const int MAX = 2e5+69;
int cnt[MAX];
set<pii>edges;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, d, s, a, b;
	cin >> n >> m >> d >> s;
	for (int i = 0; i<m; i++){
		cin >> a >> b;
		edges.insert({a, b});
	}
	return 0;
}
