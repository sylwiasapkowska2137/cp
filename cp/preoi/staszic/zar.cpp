#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
#define pii pair<int, int>
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pb push_back
#define dbg if(1)

const int MAX = 1e6+7;
vector<int>graf[MAX];
vector<bool>vis;
int n; 
int in[MAX], val[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, ans = 0;
	cin >> n;
	vis.assign(n+1, 0);
	for (int i = 1; i<n; i++){
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
		in[a]++;
		in[b]++;
	}
	
	return 0;
}
 
